################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3

GEN_OPTS__FLAG := @"configPkg/compiler.opt"
GEN_CMDS__FLAG := -Wl,-T"configPkg/linker.cmd"

ORDERED_OBJS += \
"./EK_TM4C123GXL.o" \
"./empty.o" \
"./gameConsoleRTOS.o" \
-Wl,-T"../EK_TM4C123GXL.lds" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-l"gr" \
-l"usb" \
-l"driver" \
-l"gcc" \
-l"m" \
-l"rdimon" \
-l"c" \
-Wl,--end-group \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
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
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
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
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
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
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
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
EXE_OUTPUTS += \
empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.out \

EXE_OUTPUTS__QUOTED += \
"empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.out" \

BIN_OUTPUTS += \
empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.hex \

BIN_OUTPUTS__QUOTED += \
"empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.hex" \


# All Target
all: empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.out

# Tool invocations
empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.out: $(OBJS) $(LDS_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU Linker'
	"C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3/bin/arm-none-eabi-gcc.exe" -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -D_POSIX_SOURCE -Dgcc -DTIVAWARE -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -Wl,-Map,"empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.map" -nostartfiles -static -Wl,--gc-sections -L"C:/ti/tirtos_tivac_2_14_04_31/products/TivaWare_C_Series-2.1.1.71b/grlib/gcc" -L"C:/ti/tirtos_tivac_2_14_04_31/products/TivaWare_C_Series-2.1.1.71b/usblib/gcc" -L"C:/ti/tirtos_tivac_2_14_04_31/products/TivaWare_C_Series-2.1.1.71b/driverlib/gcc" -L"C:/ti/tirtos_tivac_2_14_04_31/products/bios_6_42_03_35/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/armv7e-m/fpu" -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -o"empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: GNU Objcopy Utility'
	"C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3/bin/arm-none-eabi-objcopy.exe"  $(EXE_OUTPUTS__QUOTED) "empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_OPTS__QUOTED)$(GEN_CMDS__QUOTED)
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-$(RM) "EK_TM4C123GXL.d" "empty.d" "gameConsoleRTOS.d" 
	-$(RM) "EK_TM4C123GXL.o" "empty.o" "gameConsoleRTOS.o" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

