################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
inc/cnn.obj: ../inc/cnn.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/cnn.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/interrupt.obj: ../inc/interrupt.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/interrupt.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/intvecs.obj: ../inc/intvecs.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/intvecs.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/mat.obj: ../inc/mat.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/mat.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/ov5640.obj: ../inc/ov5640.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/ov5640.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/rk6748.obj: ../inc/rk6748.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/rk6748.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/rk6748_gpio.obj: ../inc/rk6748_gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/rk6748_gpio.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/rk6748_i2c.obj: ../inc/rk6748_i2c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/rk6748_i2c.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/rk6748_lcd.obj: ../inc/rk6748_lcd.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/rk6748_lcd.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/rk6748_timer.obj: ../inc/rk6748_timer.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/rk6748_timer.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/rk6748_uart.obj: ../inc/rk6748_uart.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/rk6748_uart.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/rk6748_vpif.obj: ../inc/rk6748_vpif.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/rk6748_vpif.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/test_camera.obj: ../inc/test_camera.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/test_camera.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/test_key_gpio.obj: ../inc/test_key_gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/test_key_gpio.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/test_led.obj: ../inc/test_led.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/test_led.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inc/test_uart.obj: ../inc/test_uart.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv6740 -g -O2 --include_path="E:/ccs/ccsv5/tools/compiler/c6000_7.4.4/include" --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="inc/test_uart.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


