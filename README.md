


# SCAMP Gesture Recognition
### Ultra-Low-Latency On-Sensor Gesture Recognition on the SCAMP5 Pixel Processor Array

Implementation of a hardware-aware convolutional neural network for the **SCAMP5 Pixel Processor Array (PPA)**, based on the paper:

https://arxiv.org/abs/2004.12525

The entire inference pipeline executes directly on the imaging sensor, eliminating the need to stream intermediate image data to an external processor. The only output is the final gesture prediction, enabling extremely low-latency embedded vision for robotics and edge AI applications.

---

## Demo

![Demo](https://cdn.phototourl.com/free/2026-07-25-71743543-2bbf-4c7f-b592-3ed589684200.png)

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

## Features

- Fully on-sensor CNN inference using the SCAMP5 Pixel Processor Array
- Hardware-aware convolution implementation optimized for SCAMP's SIMD architecture
- Event-based preprocessing using frame differencing
- Fully embedded convolutional and fully connected layers
- Pre-trained network achieving **80%+ gesture recognition accuracy**
- Designed for ultra-low-latency embedded vision applications

---

## Dataset

Event Gesture Dataset:

https://www.kaggle.com/datasets/alby356/eventgestures

---

## Repository Contents

- SCAMP5 CNN implementation
- Event preprocessing pipeline
- Hardware-aware convolution operators
- Fully connected layer implementation
- Pre-trained model
- Evaluation utilities

---

## Applications

This project demonstrates how deep learning models can execute directly on a vision sensor for applications including:

- Gesture recognition
- Human-robot interaction
- Embedded computer vision
- Edge AI
- Low-power robotics

---

## References

> Fully Embedding Fast Convolutional Networks on Pixel Processor Arrays
