CC=avr-gcc
CFLAGS=-Os -mmcu=atmega328p
PORT=COM4
BAUDRATE=115200
FILE=traffic_light

all: compile hex upload 

compile: 
	$(CC) $(CFLAGS) -o $(FILE).o $(FILE).c

hex: 
	arv-objcopy -O ihex $(FILE).o $(FILE).hex

upload:
	avrdude -V -p atmega328p -c arduino -P $(PORT) -b ${BAUDRATE} -U flash:w:$(FILE).hex

clean:
	rm *.o