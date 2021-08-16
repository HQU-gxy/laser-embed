# CMake minimum version
cmake_minimum_required (VERSION 3.1)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(linker "STM32F10X.ld")

# https://stackoverflow.com/questions/53633705/cmake-the-c-compiler-is-not-able-to-compile-a-simple-test-program
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
# if(UNIX)
#   set(CROSS_TARGET_TRIPLET "arm-none-eabi-")
#   set(CMAKE_C_COMPILER ${CROSS_TARGET_TRIPLET}gcc)
#   set(CMAKE_ASM_COMPILER ${CROSS_TARGET_TRIPLET}gcc)
# endif(UNIX)

# if you're in Windows 
# cmake . -G "MSYS Makefiles"
if(WIN32)
  set(CMAKE_GENERATOR "MSYS Makefiles")
  set(tools "C:/Program Files (x86)/GNU Arm Embedded Toolchain/9 2020-q2-update/bin/")
  set(gcc "gcc.exe")
  set(CROSS_TARGET_TRIPLET "arm-none-eabi-")
  set(CMAKE_C_COMPILER ${tools}${CROSS_TARGET_TRIPLET}${gcc})
  set(CMAKE_ASM_COMPILER ${tools}${CROSS_TARGET_TRIPLET}${gcc})
endif(WIN32)

# Project Infomation
project(Target C ASM)


# CC AR LD AS

enable_language(ASM)
enable_language(C)

# Reset output path
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# STDLIB
set (CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)

# Set include path
include_directories (User)
include_directories (Libraries/CMSIS)
include_directories (Libraries/STM32F10x_StdPeriph_Driver/inc)
include_directories (APP/led)
include_directories (Public)
include_directories (APP/beep)
include_directories (APP/smg)
include_directories (APP/key)
include_directories (APP/exti)
include_directories (APP/time)
include_directories (APP/pwm)
include_directories (APP/iwdg)
include_directories (APP/wwdg)
include_directories (APP/input)
include_directories (APP/touch_key)
include_directories (APP/wkup)
include_directories (APP/adc)
include_directories (APP/adc_temp)
include_directories (APP/dac)
include_directories (APP/pwm_dac)
include_directories (APP/dma)
include_directories (APP/rtc)
include_directories (APP/24Cxx)
include_directories (APP/iic)
include_directories (APP/ds18b20)
include_directories (APP/hwjs)
include_directories (APP/rs485)
include_directories (APP/can)
include_directories (APP/tftlcd)
include_directories (APP/hwjs)
include_directories (APP/hexify)
include_directories (APP/nrf24l01)
include_directories (APP/spi)
include_directories (APP/input)
include_directories (APP/gps)
include_directories (APP/function)
include_directories (APP/module)

# The need build source path and build all files
set (SRC_FILE0 User/main.c)
set (SRC_FILE1 User/stm32f10x_it.c)
set (SRC_FILE2 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c)
set (SRC_FILE3 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c)
set (SRC_FILE4 Libraries/STM32F10x_StdPeriph_Driver/src/misc.c)
set (SRC_FILE5 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c)
set (SRC_FILE6 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_tim.c)
set (SRC_FILE7 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c)
set (SRC_FILE8 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_iwdg.c)
set (SRC_FILE9 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_wwdg.c)
set (SRC_FILE10 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_bkp.c)
set (SRC_FILE11 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_pwr.c)
set (SRC_FILE12 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_adc.c)
set (SRC_FILE13 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_dac.c)
set (SRC_FILE14 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_dma.c)
set (SRC_FILE15 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rtc.c)
set (SRC_FILE16 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_can.c)
set (SRC_FILE17 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_fsmc.c)
set (SRC_FILE18 Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_spi.c)
set (SRC_FILE19 Libraries/STM32F10x_StdPeriph_Driver/inc/stm32f10x_spi.h)
set (SRC_FILE20 Libraries/CMSIS/system_stm32f10x.c)
set (SRC_FILE21 Libraries/CMSIS/core_cm3.c)
set (SRC_FILE22 APP/led/led.c)
set (SRC_FILE23 APP/tftlcd/tftlcd.c)
set (SRC_FILE24 APP/hwjs/hwjs.c)
set (SRC_FILE25 APP/hwjs/hwjs.h)
set (SRC_FILE26 APP/nrf24l01/nrf24l01.c)
set (SRC_FILE27 APP/nrf24l01/nrf24l01.h)
set (SRC_FILE28 APP/spi/spi.c)
set (SRC_FILE29 APP/spi/spi.h)
set (SRC_FILE30 APP/gps/gps.c)
set (SRC_FILE31 APP/gps/gps.h)
set (SRC_FILE32 APP/module/module.c)
set (SRC_FILE33 APP/module/module.h)
set (SRC_FILE34 APP/function/function.c)
set (SRC_FILE35 APP/function/function.h)
set (SRC_FILE36 APP/time/time.c)
set (SRC_FILE37 APP/time/time.h)
set (SRC_FILE38 Public/system.c)
set (SRC_FILE39 Public/SysTick.c)
set (SRC_FILE40 Public/usart.c)



# CFLAGS
set (CMAKE_C_FLAGS "-g -Wextra -Wshadow -Wimplicit-function-declaration -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes -fno-common -ffunction-sections -fdata-sections -MD -Wall -Wundef -mthumb -mcpu=cortex-m3 " CACHE INTERNAL "c compiler flags")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -D STM32F10X_MD  -D USE_STDPERIPH_DRIVER ")

# CXXFLAGS
set (CMAKE_CXX_FLAGS "-Wextra -Wshadow -Wredundant-decls  -Weffc++ -fno-common -ffunction-sections -fdata-sections -MD -Wall -Wundef -mthumb -mcpu=cortex-m3 " CACHE INTERNAL "cxx compiler flags")

# ASMFLAGS
set (CMAKE_ASM_FLAGS "-g -mthumb -mcpu=cortex-m3 " CACHE INTERNAL "asm compiler flags")

# LDFLAGS
set (CMAKE_EXE_LINKER_FLAGS "-g -Wl,--gc-sections -Wl,-Map=Target 1.map -mthumb -mcpu=cortex-m3 " CACHE INTERNAL "executable linker flags")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/${linker} -L ")


# Generate the target
add_executable (${CMAKE_PROJECT_NAME}.elf  ${SRC_FILE0}  ${SRC_FILE1}  ${SRC_FILE2}  ${SRC_FILE3}  ${SRC_FILE4}  ${SRC_FILE5}  ${SRC_FILE6}  ${SRC_FILE7}  ${SRC_FILE8}  ${SRC_FILE9}  ${SRC_FILE10}  ${SRC_FILE11}  ${SRC_FILE12}  ${SRC_FILE13}  ${SRC_FILE14}  ${SRC_FILE15}  ${SRC_FILE16}  ${SRC_FILE17}  ${SRC_FILE18}  ${SRC_FILE19}  ${SRC_FILE20}  ${SRC_FILE21}  ${SRC_FILE22}  ${SRC_FILE23}  ${SRC_FILE24}  ${SRC_FILE25}  ${SRC_FILE26}  ${SRC_FILE27}  ${SRC_FILE28}  ${SRC_FILE29}  ${SRC_FILE30}  ${SRC_FILE31}  ${SRC_FILE32}  ${SRC_FILE33}  ${SRC_FILE34}  ${SRC_FILE35}  ${SRC_FILE36}  ${SRC_FILE37}  ${SRC_FILE38}  ${SRC_FILE39}  ${SRC_FILE40} )

# Link the library to the target
target_link_libraries (${CMAKE_PROJECT_NAME}.elf )

# Generate the binary file
add_custom_target (${CMAKE_PROJECT_NAME}.bin ALL arm-none-eabi-objcopy -Obinary "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf" "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.bin" DEPENDS ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf)

# Generate the hex file
add_custom_target (${CMAKE_PROJECT_NAME}.hex ALL arm-none-eabi-objcopy -Oihex "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf" "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.hex" DEPENDS ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf)

# Echo the size Infomation
add_custom_target (size ALL arm-none-eabi-size "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf" DEPENDS ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf)

# Make flash to the board by st-link
add_custom_target (flash COMMAND st-flash write ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.bin 0x8000000)

# Make clean-all
add_custom_target (clean-all COMMAND rm -rf ${CMAKE_BINARY_DIR}/*)