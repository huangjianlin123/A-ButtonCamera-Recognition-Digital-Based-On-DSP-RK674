################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/main_camera.obj: ../src/main_camera.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="src/main_camera.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


