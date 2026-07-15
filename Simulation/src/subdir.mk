################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/scamp5_main.cpp 

CPP_DEPS += \
./src/scamp5_main.d 

OBJS += \
./src/scamp5_main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -DWORKSPACE_PATH='R"RRR(C:\Users\alber\Documents\MCUXpressoIDE_25.6.136\workspace)RRR"' -DPROJECT_NAME='R"RRR(example_1_image_capture_and_display)RRR"' -I"C:\Users\alber\Documents\MCUXpressoIDE_25.6.136\workspace\s5d_m0_sim\inc" -O0 -g -Wall -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/scamp5_main.d ./src/scamp5_main.o

.PHONY: clean-src

