
# Add your Source files to this variable
SRC = src/main.c \
	  src/memory.c \
          src/data.c \
          src/stats.c \
          src/course1.c

# Add your include paths to this variable
INCLUDES = -I include/common

ifeq ($(PLATFORM),MSP432)
	SRC += src/interrupts_msp432p401r_gcc.c \
        src/startup_msp432p401r_gcc.c \
        src/system_msp432p401r.c

	INCLUDES += -I include/CMSIS \
        -I include/msp432
endif
