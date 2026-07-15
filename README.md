https://www.kaggle.com/datasets/alby356/gestures2
https://www.kaggle.com/datasets/alby356/gestures3

| File | Role |
|---|---|
| `REGISTER_ENUMS.hpp` | Two small `enum class`es (`AENUM` for analog registers, `DENUM` for digital registers) so helper functions can take "which register" as an ordinary runtime value. |
| `MISC_FUNCTIONS.hpp` / `.cpp` | Low-level utility library: shifting/centering a binary image (`shift_R11`), drawing rectangle masks (`load_rect_into_DREG`), converting a binary mask to a two-level analog image (`load_DREG_into_F`), plus assorted unused utilities carried over from the reference repo. |
| `AREG_POOLING.hpp` / `.cpp` | `MAX_POOL_F(...)` — 4×4 max-pooling via repeated "shift the image by one pixel, compare with the original, keep the larger" passes (first horizontal, then vertical). |
| `IMG_SCALING_DIGITAL.hpp` / `.cpp` | Digital (not analog) image up/down-scaling of a binary silhouette, one incremental step at a time. Digital scaling is used instead of analog because repeated analog copies accumulate noise, while binary values survive many copies untouched. |
| `IMG_TF.hpp` | Just a few unrelated math-helper declarations pulled in by `IMG_SCALING_DIGITAL`'s include chain; unused by this project. |
| `GESTURE_CAPTURE.hpp` / `.cpp` | The gesture-specific capture pipeline: `extract_gesture_blob_from_F_into_R11(...)` thresholds the camera frame to a binary hand silhouette, centers it, and scales it to a target size; `duplicate_gesture_into_grid_R10(...)` tiles that silhouette into every computation block of the array. |
| `FUNCS_WEIGHT_LOADING.hpp` | One-time setup functions that burn the *trained* weights into the chip's own registers: `load_filter_weights_into_grid_F` (conv filters, one 4×4 ternary kernel per block) and `load_FC_weights_into_grid_E` (the fully-connected layer's ternary weights, encoded as +1/-1 pixel masks). |
| `WEIGHTS_GESTURE_4x4_16CONVOLS_64x64INPUT.hpp` | Generated data, not hand-written — produced by `train.py` after training. Ternary conv/FC weight arrays plus the gesture name strings and size constants. Regenerate this by retraining; nothing else needs to change. |
| `MAIN_GESTURE_SINGLE_LAYER_16.cpp` | The main `while(true)` per-frame loop: capture → extract/tile the gesture → convolution (all 16 filters in one parallel pass via a checkerboard flood-fill trick) → ReLU → max-pool → in-pixel fully-connected layer → read out the 5 gesture scores and print the prediction. Also declares the on-device GUI sliders/buttons (threshold, weight-loading button, etc.). |
| `scamp5_main.cpp` | The actual `main()` entry point — boilerplate USB/init setup that hands off to `MAIN_GESTURE_SINGLE_LAYER_16()`. |
| `TIMING_STATS.hpp` / `.cpp` | Optional profiling helper (named stopwatch). Not currently called anywhere in this pipeline, kept for anyone who wants to instrument timings. |

