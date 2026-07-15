################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := example_1_image_capture_and_display
BUILD_ARTIFACT_EXTENSION := exe
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: example_1_image_capture_and_display.exe

# Tool invocations
example_1_image_capture_and_display.exe: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MinGW C++ Linker'
	g++ -L"C:\Users\alber\Documents\MCUXpressoIDE_25.6.136\workspace\s5d_m0_sim\lib" -o "example_1_image_capture_and_display.exe" $(OBJS) $(USER_OBJS) $(LIBS) -lscamp5_sim_lib -luv -lws2_32 -lpsapi -liphlpapi -luserenv
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) example_1_image_capture_and_display.exe
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
