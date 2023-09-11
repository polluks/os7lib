TARGET_EXEC ?= os7

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

CC=zcc
AS=z88dk-z80asm

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CFLAGS=+coleco
LDFLAGS=-xos7

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(AS) $(LDFLAGS) $(OBJS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: install clean

install: src/os7.h eos.lib
	install src/os7.h /usr/local/share/z88dk/include/
	install os7.lib /usr/local/share/z88dk/lib/

clean:
	$(RM) -r os7.lib $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
