################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/main_camera.obj: ../src/main_camera.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --include_path="F:/温大研一/数据挖掘/数据挖掘/camera_ov5640/inc" --diag_warning=225 --abi=coffabi --optimizer_interlist --remove_hooks_when_inlining --opt_for_speed=0 --gen_opt_info=0 --preproc_with_compile --preproc_dependency="src/main_camera.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


