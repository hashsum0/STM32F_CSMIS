PROJECT = led_on

EABI = arm-none-eabi

CMSIS_DIR = /home/saturn/MEGA/Projects/STM32/PROJ_STM32F100/$(PROJECT)/src
CMSIS_INC = $(CMSIS_DIR)
MCU_INC = $(CMSIS_DIR)

CC = $(EABI)-gcc
OC = $(EABI)-objcopy

CFLAGS = -mcpu=cortex-m3 -mthumb
CFLAGS += -Os
CFLAGS += -I./Inc -I$(CMSIS_INC) -I$(MCU_INC)

LDFLAGS = -T$(CMSIS_DIR)/STM32F100XB_FLASH.ld --specs=nano.specs
LDFLAGS += --specs=nosys.specs
LDFLAGS += -g

SRCS = main.c
SRCS += $(CMSIS_DIR)/startup_stm32f10x_md_vl.s

all: $(PROJECT)

bin: $(PROJECT)
	$(OC) -Obinary $(PROJECT) $(PROJECT).bin

clean:
	$(RM) $(PROJECT)*

$(PROJECT): $(SRCS) makefile
	$(CC) $(SRCS) $(CFLAGS) $(LDFLAGS) -o $(PROJECT)
