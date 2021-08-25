################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/utils/connection/connection.c 

OBJS += \
./src/utils/connection/connection.o 

C_DEPS += \
./src/utils/connection/connection.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/connection/%.o: ../src/utils/connection/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


