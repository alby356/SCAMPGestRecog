################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AREG_POOLING.cpp \
../src/IMG_SCALING_DIGITAL.cpp \
../src/IMG_TF_HELPER.cpp \
../src/MAIN_MNIST_SINGLE_LAYER_16.cpp \
../src/MISC_FUNCTIONS.cpp \
../src/TIMING_STATS.cpp \
../src/scamp5_main.cpp 

CPP_DEPS += \
./src/AREG_POOLING.d \
./src/IMG_SCALING_DIGITAL.d \
./src/IMG_TF_HELPER.d \
./src/MAIN_MNIST_SINGLE_LAYER_16.d \
./src/MISC_FUNCTIONS.d \
./src/TIMING_STATS.d \
./src/scamp5_main.d 

OBJS += \
./src/AREG_POOLING.o \
./src/IMG_SCALING_DIGITAL.o \
./src/IMG_TF_HELPER.o \
./src/MAIN_MNIST_SINGLE_LAYER_16.o \
./src/MISC_FUNCTIONS.o \
./src/TIMING_STATS.o \
./src/scamp5_main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -std=gnu++20 -D__NEWLIB__ -DNDEBUG -D__CODE_RED -DCORE_M0 -D__USE_LPCOPEN -DNO_BOARD_LIB -DCPP_USE_HEAP -D__LPC43XX__ -D__MULTICORE_M0APP -DCORE_M0APP -DWORKSPACE_PATH='R"RRR(C:\Users\alber\Documents\MCUXpressoIDE_25.6.136\workspace)RRR"' -DPROJECT_NAME='R"RRR(sim)RRR"' -I"C:\Users\alber\Documents\MCUXpressoIDE_25.6.136\workspace\lpc_chip_43xx_m0\inc" -I"C:\Users\alber\Documents\MCUXpressoIDE_25.6.136\workspace\s5d_m0\inc" -I"C:\Users\alber\Documents\MCUXpressoIDE_25.6.136\workspace\s5d_m4\inc" -O2 -fno-common -g -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/AREG_POOLING.d ./src/AREG_POOLING.o ./src/IMG_SCALING_DIGITAL.d ./src/IMG_SCALING_DIGITAL.o ./src/IMG_TF_HELPER.d ./src/IMG_TF_HELPER.o ./src/MAIN_MNIST_SINGLE_LAYER_16.d ./src/MAIN_MNIST_SINGLE_LAYER_16.o ./src/MISC_FUNCTIONS.d ./src/MISC_FUNCTIONS.o ./src/TIMING_STATS.d ./src/TIMING_STATS.o ./src/scamp5_main.d ./src/scamp5_main.o

.PHONY: clean-src

