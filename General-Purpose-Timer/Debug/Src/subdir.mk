################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/tim.c 

OBJS += \
./Src/gpio.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/tim.o 

C_DEPS += \
./Src/gpio.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F411xE -c -I"C:/Users/dange/STM32CubeIDE/workspace_2.1.1/First-Project/GENERAL PURPOSE TIMER/chip_headers/CMSIS/Include" -I"C:/Users/dange/STM32CubeIDE/workspace_2.1.1/First-Project/GENERAL PURPOSE TIMER/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/gpio.cyclo ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/tim.cyclo ./Src/tim.d ./Src/tim.o ./Src/tim.su

.PHONY: clean-Src

