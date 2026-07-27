


# SCAMP Gesture Recognition
### Ultra-Low-Latency On-Sensor Gesture Recognition on the SCAMP5 Pixel Processor Array

Implementation of a hardware-aware convolutional neural network for the **SCAMP5 Pixel Processor Array (PPA)**, based on the paper:

https://arxiv.org/abs/2004.12525

The entire inference pipeline executes directly on the imaging sensor, eliminating the need to stream intermediate image data to an external processor. The only output is the final gesture prediction, enabling extremely low-latency embedded vision for robotics and edge AI applications.

---

## Demo

---

## Pipeline

```
Input Frames
      │
      ▼
Frame Differencing
      │
      ▼
Binary Event Frames
      │
      ▼
Event Heatmap
      │
      ▼
On-Sensor CNN
      │
      ▼
Gesture Prediction
```

---



## Dataset

Event Gesture Dataset:

https://www.kaggle.com/datasets/alby356/eventgestures

