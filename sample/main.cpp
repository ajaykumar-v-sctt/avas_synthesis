#include "JetEngineSample.hpp"

#include "HvUtils.h"

#include <array>
#include <cmath>
#include <cstdio>
#include <exception>

namespace {
const int kSampleRate = 48000;
const int kFramesPerBlock = 128;
const float kMaximumVehicleSpeedKph = 250.0f;
}

int main() {
  try {
    JetEngineSample engine(kSampleRate, kMaximumVehicleSpeedKph);
    std::array<float, kFramesPerBlock * 2> stereoScratch;
    std::array<float, kFramesPerBlock> monoOutput;
    const float demoSpeedKph[] = {0.0f, 35.0f, 80.0f, 120.0f};

    for (float speedKph : demoSpeedKph) {
      if (!engine.onVehicleSpeedKph(speedKph)) {
        std::fprintf(stderr, "Could not queue speed %.1f km/h\n", speedKph);
        return 1;
      }

      const int rendered = engine.renderMono(
          monoOutput.data(), stereoScratch.data(), kFramesPerBlock);
      if (rendered != kFramesPerBlock) {
        std::fprintf(stderr, "Could not render the requested audio block\n");
        return 1;
      }

      float peak = 0.0f;
      for (float sample : monoOutput) {
        peak = std::fmax(peak, std::fabs(sample));
      }
      std::printf("speed=%5.1f km/h, rendered=%d mono frames, peak=%f\n",
                  speedKph, rendered, peak);
    }

    return 0;
  } catch (const std::exception &error) {
    std::fprintf(stderr, "jetengine sample error: %s\n", error.what());
    return 1;
  }
}
