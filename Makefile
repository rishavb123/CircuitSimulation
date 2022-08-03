CC = g++
CFLAGS = -Wall -g

OFILES = main.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OFILES)

$(TARGET).o: $(TARGET).cpp 
	$(CC) $(CFLAGS) -c $(TARGET).cpp

clean:
	rm $(TARGET) $(TARGET).o
