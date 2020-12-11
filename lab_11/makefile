CC := gcc

INC := ./inc/
OUT := ./out/
SRC := ./src/
UNIT := ./unit_tests/

CFLAGS := -std=gnu99 -Wall -ggdb -Wvla -pedantic -Wfloat-equal -Wfloat-conversion -Iinc

OBJS := $(OUT)funcs.o $(OUT)my_snprintf.o
CHECK_OBJS := $(OUT)check_main.o $(OUT)check_my_snprintf.o $(OUT)check_str_put.o $(OUT)check_str_to_lld.o

all : func unit

func : app.exe

unit : unit_tests.exe

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
