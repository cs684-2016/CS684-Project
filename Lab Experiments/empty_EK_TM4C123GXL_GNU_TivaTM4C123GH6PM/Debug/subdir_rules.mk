################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -D_POSIX_SOURCE -Dgcc -DTIVAWARE -I"C:/Users/Koona/Documents/MTech/EmbeddedSystems/CCSWorkspace/empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM" -I"C:/ti/tirtos_tivac_2_14_04_31/products/TivaWare_C_Series-2.1.1.71b" -I"C:/ti/tirtos_tivac_2_14_04_31/packages/ti/drivers/wifi/cc3100/Simplelink" -I"C:/ti/tirtos_tivac_2_14_04_31/packages/ti/drivers/wifi/cc3100/Simplelink/Include" -I"C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3/arm-none-eabi/include" -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -MD -std=c99 -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: ../empty.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_31_01_33_core/xs" --xdcpath="C:/ti/tirtos_tivac_2_14_04_31/packages;C:/ti/tirtos_tivac_2_14_04_31/products/bios_6_42_03_35/packages;C:/ti/tirtos_tivac_2_14_04_31/products/ndk_2_24_03_35/packages;C:/ti/tirtos_tivac_2_14_04_31/products/uia_2_00_02_39/packages;C:/ti/ccsv6/ccs_base;" xdc.tools.configuro -o configPkg -t gnu.targets.arm.M4F -p ti.platforms.tiva:TM4C123GH6PM -r release -c "C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3" --compileOptions "-mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -D_POSIX_SOURCE -Dgcc -DTIVAWARE -I\"C:/Users/Koona/Documents/MTech/EmbeddedSystems/CCSWorkspace/empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM\" -I\"C:/ti/tirtos_tivac_2_14_04_31/products/TivaWare_C_Series-2.1.1.71b\" -I\"C:/ti/tirtos_tivac_2_14_04_31/packages/ti/drivers/wifi/cc3100/Simplelink\" -I\"C:/ti/tirtos_tivac_2_14_04_31/packages/ti/drivers/wifi/cc3100/Simplelink/Include\" -I\"C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3/arm-none-eabi/include\" -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -MD -std=c99 -c  " "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd


