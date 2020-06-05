################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := E:/ccs/ccsv5/tools/compiler/c6000_7.4.4

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./inc/test_uart.obj" \
"./inc/test_led.obj" \
"./inc/test_key_gpio.obj" \
"./inc/test_camera.obj" \
"./inc/rk6748_vpif.obj" \
"./inc/rk6748_uart.obj" \
"./inc/rk6748_timer.obj" \
"./inc/rk6748_lcd.obj" \
"./inc/rk6748_i2c.obj" \
"./inc/rk6748_gpio.obj" \
"./inc/rk6748.obj" \
"./inc/ov5640.obj" \
"./inc/mat.obj" \
"./inc/intvecs.obj" \
"./inc/interrupt.obj" \
"./inc/cnn.obj" \
"./src/main_camera.obj" \
"../src/rk6748_DSP.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir_vars.mk
-include inc/subdir_vars.mk
-include src/subdir_rules.mk
-include inc/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: camera.out

# Tool invocations
camera.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C6000 Linker'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g --diag_warning=225 --abi=coffabi --optimizer_interlist --remove_hooks_when_inlining --opt_for_speed=0 --gen_opt_info=0 -z -m"camera.map" --warn_sections -i"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/lib" -i"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --reread_libs --xml_link_info="camera_linkInfo.xml" --rom_model -o "camera.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C6000_EXECUTABLE_OUTPUTS__QUOTED) "camera.out"
	-$(RM) "src\main_camera.pp" "inc\cnn.pp" "inc\interrupt.pp" "inc\mat.pp" "inc\ov5640.pp" "inc\rk6748.pp" "inc\rk6748_gpio.pp" "inc\rk6748_i2c.pp" "inc\rk6748_lcd.pp" "inc\rk6748_timer.pp" "inc\rk6748_uart.pp" "inc\rk6748_vpif.pp" "inc\test_camera.pp" "inc\test_key_gpio.pp" "inc\test_led.pp" "inc\test_uart.pp" 
	-$(RM) "src\main_camera.obj" "inc\cnn.obj" "inc\interrupt.obj" "inc\intvecs.obj" "inc\mat.obj" "inc\ov5640.obj" "inc\rk6748.obj" "inc\rk6748_gpio.obj" "inc\rk6748_i2c.obj" "inc\rk6748_lcd.obj" "inc\rk6748_timer.obj" "inc\rk6748_uart.obj" "inc\rk6748_vpif.obj" "inc\test_camera.obj" "inc\test_key_gpio.obj" "inc\test_led.obj" "inc\test_uart.obj" 
	-$(RM) "inc\intvecs.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

