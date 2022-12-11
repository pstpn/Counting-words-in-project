CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-conversion -Wfloat-equal -Wvla -I ./inc/
C_FOLDER := ./src/
INC_FOLDER := ./inc/
OBJ_FOLDER := ./out/
SRC_FILES := $(wildcard $(C_FOLDER)*.c)
OBJS := $(filter-out $(OBJ_FOLDER)main.o,$(patsubst $(C_FOLDER)%.c,$(OBJ_FOLDER)%.o,$(SRC_FILES)))


debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe : $(OBJS) $(OBJ_FOLDER)main.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_FOLDER)%.o : */%.c $(INC_FOLDER)*.h
	mkdir -p out/
	$(CC) $(CFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: debug release run clean

run :
	make release -B
	./app.exe

clean :
	- rm *.txt *.exe *.dot *.png *.tmp
	- rm -rf ./out