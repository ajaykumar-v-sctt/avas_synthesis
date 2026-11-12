#ifndef JETENGINE_SAMPLE_HPP
#define JETENGINE_SAMPLE_HPP

#include "HeavyContextInterface.hpp"

class JetEngineSample {
 public:
  JetEngineSample(double sampleRate, float maxVehicleSpeedKph);
  ~JetEngineSample();

  JetEngineSample(const JetEngineSample &) = delete;
  JetEngineSample &operator=(const JetEngineSample &) = delete;

  // Call with decoded vehicle speed. Safe to call from a CAN receive thread.
  bool onVehicleSpeedKph(float speedKph);

  // Call from the audio thread with an interleaved [L, R, L, R, ...] buffer.
  // frames must be positive and a multiple of the Heavy SIMD frame width.
  int render(float *stereoOutput, int frames);

  // Downmixes to mono. stereoScratch must hold 2 * frames floats and must not
  // overlap monoOutput. Both buffers are supplied by the caller.
  int renderMono(float *monoOutput, float *stereoScratch, int frames);

 private:
  HeavyContextInterface *context_;
  HvParameterInfo speedParameter_;
  float maxVehicleSpeedKph_;
};

#endif
