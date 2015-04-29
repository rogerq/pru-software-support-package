################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
pru.obj: ../pru.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/temp_ccs/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me -O2 --include_path="C:/temp_ccs/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="C:/TI/AM335X_StarterWare_02_00_01_01/include/armv7a/am335x" --include_path="C:/TI/AM335X_StarterWare_02_00_01_01/include/armv7a" --include_path="C:/TI/AM335X_StarterWare_02_00_01_01/include/hw" --include_path="C:/TI/AM335X_StarterWare_02_00_01_01/include" --define=am3359 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="pru.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pru_cape_demo.obj: ../pru_cape_demo.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/temp_ccs/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me -O2 --include_path="C:/temp_ccs/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="C:/TI/AM335X_StarterWare_02_00_01_01/include/armv7a/am335x" --include_path="C:/TI/AM335X_StarterWare_02_00_01_01/include/armv7a" --include_path="C:/TI/AM335X_StarterWare_02_00_01_01/include/hw" --include_path="C:/TI/AM335X_StarterWare_02_00_01_01/include" --define=am3359 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="pru_cape_demo.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


