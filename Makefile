CC=gcc
INCLUDE   =-I./include
SOURCES   =$(wildcard ./src/*.c)
OBJECTS   =$(patsubst ./src/%.c,./obj/%.o,$(SOURCES))

TARGET    =bank_algorithm

${TARGET}:${OBJECTS}
	${CC} ${TARGET}.c ${OBJECTS} ${INCLUDE} -o ${TARGET}

./obj/%.o:./src/%.c
	$(shell if [ ! -d ./obj ]; then mkdir ./obj; fi)
	${CC} ${INCLUDE} -c $< -o $@

.PHONY:clean
clean:
	@echo "Cleaning up..."
	rm -f ${OBJECTS} ${TARGET}
