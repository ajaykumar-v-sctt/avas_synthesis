# Heavy jetengine sample

This example uses the generated `c/` Heavy patch. It accepts decoded vehicle
speed in km/h and renders float audio into application-owned buffers. The patch
exposes two output channels; the current generated graph writes the same signal
to both (dual mono), and the sample demonstrates downmixing it to mono. The
demo supplies representative speeds; it does not read a CAN interface or open
an audio device. See [CODE_FLOW.md](CODE_FLOW.md) for the traced speed-to-audio
flow and buffer details.

The generated patch exposes a `speed` parameter with a 0.1–1.0 range. The
adapter maps 0 km/h to the parameter minimum and the configured maximum speed
to its maximum, clamping higher speeds. Configure `kMaximumVehicleSpeedKph`
for your vehicle and calibration.

Build and run with CMake:

```powershell
cmake -S sample -B sample/build
cmake --build sample/build --config Release
.\sample\build\Release\jetengine_sample.exe
```

In an application, call `onVehicleSpeedKph()` from the CAN decoding side with
the decoded speed signal (after applying that vehicle's CAN ID, byte order,
scale, and offset). For stereo, call `render()` with a buffer containing
`2 * frames` floats in `[L, R, L, R, ...]` order. For mono, call `renderMono()`
with a `frames`-sized mono buffer and a caller-owned stereo scratch buffer
holding `2 * frames` floats. The mono result is the average of the left and
right channels. Use frame counts that are multiples of Heavy's SIMD width; the
Heavy render function is intended to run on one audio thread. Check the return
values to detect queue or render failures.
