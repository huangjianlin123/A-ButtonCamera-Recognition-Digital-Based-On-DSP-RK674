# A-ButtonCamera-Recognition-Digital-Based-On-DSP-RK674

一种基于RK6748的嵌入式DSP芯片的拍照识别数字项目。通过在板子上按键，然后ov5640摄像头获取照片图像，并显示在lcd上。然后通过LeNet5经典卷积神经网络，识别拍照的数字。与python或者c++不同，嵌入式一般考虑的因素比较多，如：内存需要动态手动分配，只能用c实现，运算速度等，因此，这个项目具有现实意义。