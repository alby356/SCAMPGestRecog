# On-Sensor, Event-Based Gesture Recognition Completely On-Sensor 

Code for CNN project for Scamp5 PPA, demonstrating the methods presented in the paper "Fully Embedding Fast Convolutional Networks on Pixel Processor Arrays"
![image](https://cdn.phototourl.com/free/2026-07-25-71743543-2bbf-4c7f-b592-3ed589684200.png)

Dataset:

https://www.kaggle.com/datasets/alby356/eventgestures

Frame differencing -> Binary event frames -> Event heatmap.
Includes methods to implement convolutional layers & final fully connected layer entirely within PE array.
This pre-trained network included performs gesture recognition at over 80% accuracy, with 1 convolutional layer and 1 fully connected layer.


