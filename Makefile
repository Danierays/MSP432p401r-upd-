#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

# Compiler Flags and Defines
TARGET = c1m4
CC = gcc
LD = ld
DUMP = objdump
SIZE = size
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = -E

ifeq ($(COURSE1),1)
	CFLAGS += -DCOURSE1
endif

ifeq ($(VERBOSE),1)
	VBFLAGS += -DVERBOSE
endif

ifeq ($(PLATFORM),MSP432)
	# Architectures Specific Flags
	LINKER_FILE = ./msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	ARM_ARCH = armv7e-m
	FLOAT_ABI = hard
	FPU = fpv4-sp-d16
	SPECS = nosys.specs
	PLATFORM_FLAGS = -mcpu=$(CPU) -m$(ARCH) -march=$(ARM_ARCH) \
                         -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU) \
                         --specs=$(SPECS)

	CROSS_COMPILE = arm-none-eabi-
	CC = $(CROSS_COMPILE)$(CC)
	LD = $(CROSS_COMPILE)$(LD)
	DUMP = $(CROSS_COMPILE)$(DUMP)
	SIZE = $(CROSS_COMPILE)$(SIZE)
	CFLAGS += $(PLATFORM_FLAGS)
	LDFLAGS += -T $(LINKER_FILE) $(PLATFORM_FLAGS)
endif

PREPROC = $(SRC:.c=.i)
S = $(SRC:.c=.s)
ASM = $(SRC:.c=.asm)
OBJS = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

%.i : %.c
	$(CC) $(CPPFLAGS) $< > $@ -D$(PLATFORM) $(INCLUDES)

$(S) : %.s : %.c
	$(CC) $< -S -o $@ $(CFLAGS) -D$(PLATFORM) $(INCLUDES)

%.asm : $(S) $(TARGET)
	$(DUMP) -S $(TARGET).out > $(TARGET).asm

$(OBJS) : %.o : %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(VBFLAGS) -D$(PLATFORM) $(INCLUDES)

$(DEP) : %.d : %.c
	$(CC) -M $< -MF $@ -D$(PLATFORM) $(INCLUDES)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET).out $(LDFLAGS)

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(DEP) $(TARGET)
	$(SIZE) -Ad $(TARGET).out

.PHONY: clean
clean:
	rm *.out -f $(OBJS) $(ASM) $(S) $(DEP) $(PREPROC) $(TARGET).map

