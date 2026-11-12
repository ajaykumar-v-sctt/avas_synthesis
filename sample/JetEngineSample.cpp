#include "JetEngineSample.hpp"

#include "Heavy_jetengine.h"
#include "HvUtils.h"

#include <cmath>
#include <stdexcept>

JetEngineSample::JetEngineSample(double sampleRate, float maxVehicleSpeedKph)
    : context_(nullptr),
      speedParameter_(),
      maxVehicleSpeedKph_(maxVehicleSpeedKph) {
  if (!std::isfinite(sampleRate) || sampleRate <= 0.0 ||
      !std::isfinite(maxVehicleSpeedKph_) || maxVehicleSpeedKph_ <= 0.0f) {
    throw std::invalid_argument("Sample rate and maximum vehicle speed must be positive and finite");
  }

  context_ = hv_jetengine_new(sampleRate);
  if (context_ == nullptr) {
    throw std::runtime_error("Failed to create the Heavy jetengine context");
  }

  if (context_->getParameterInfo(0, &speedParameter_) == 0 ||
      speedParameter_.type != HV_PARAM_TYPE_PARAMETER_IN ||
      speedParameter_.maxVal <= speedParameter_.minVal) {
    hv_jetengine_free(context_);
    context_ = nullptr;
    throw std::runtime_error("The generated patch has no usable speed input parameter");
  }
}

JetEngineSample::~JetEngineSample() {
  if (context_ != nullptr) {
    hv_jetengine_free(context_);
  }
}

bool JetEngineSample::onVehicleSpeedKph(float speedKph) {
  if (!std::isfinite(speedKph) || speedKph < 0.0f) {
    return false;
  }

  const float normalizedSpeed = speedKph / maxVehicleSpeedKph_;
  const float parameterValue =
      speedParameter_.minVal +
      (speedParameter_.maxVal - speedParameter_.minVal) *
          (normalizedSpeed > 1.0f ? 1.0f : normalizedSpeed);

  return context_->sendFloatToReceiver(speedParameter_.hash, parameterValue);
}

int JetEngineSample::render(float *stereoOutput, int frames) {
  if (stereoOutput == nullptr || frames <= 0 || (frames & HV_N_SIMD_MASK) != 0) {
    return 0;
  }

  return context_->processInlineInterleaved(nullptr, stereoOutput, frames);
}

int JetEngineSample::renderMono(float *monoOutput, float *stereoScratch, int frames) {
  if (monoOutput == nullptr || stereoScratch == nullptr ||
      frames <= 0 || (frames & HV_N_SIMD_MASK) != 0) {
    return 0;
  }

  const int rendered = render(stereoScratch, frames);
  if (rendered != frames) {
    return rendered;
  }

  for (int i = 0; i < rendered; ++i) {
    monoOutput[i] = 0.5f * (stereoScratch[2 * i] + stereoScratch[2 * i + 1]);
  }
  return rendered;
}
