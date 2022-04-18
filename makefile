CC = gcc
CFLAGS =-Wall -Wextra -Werror
SOURCES = my.c 11.c
BUILD_DIR = .
OUTFILE = aaa

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(BUILD_DIR)/$(OUTFILE)


# clean:
# 	rm -rf $(BUILD_DIR)/$(OUTFILE)
# 	rm -rf *.o

# style:
# 	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

# leaks:
# 	leaks -atExit -- $(BUILD_DIR)/$(OUTFILE)

# check:
# 	cppcheck --enable=all --suppress=missingIncludeSystem *.c

run:
	$(BUILD_DIR)/$(OUTFILE)