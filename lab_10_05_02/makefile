CC := gcc

INC := ./inc/
OUT := ./out/
SRC := ./src/
UNIT := ./unit_tests/

CFLAGS := -std=gnu99 -Wall -Werror -ggdb -Wvla -pedantic -Wfloat-equal -Wfloat-conversion -Iinc

OBJS := $(OUT)list_tools.o $(OUT)task.o $(OUT)tools.o
CHECK_OBJS := $(OUT)check_main.o $(OUT)check_compact.o $(OUT)check_concatenation.o $(OUT)check_remove_duplicates.o $(OUT)check_search.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe


app.exe : $(OBJS) $(OUT)main.o
	$(CC) -o $@ $^

unit_tests.exe : $(OBJS) $(CHECK_OBJS)
	$(CC) -o $@ $^ -lcheck


$(OUT)%.o : $(SRC)%.c
	mkdir -p out && $(CC) $(CFLAGS) -c $< -o $@

$(OUT)check_%.o : $(UNIT)check_%.c
	mkdir -p out && $(CC) $(CFLAGS) -c $< -o $@


.PHONY : clean
clean :
	$(RM) $(OUT)*.o *.exe
