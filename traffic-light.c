#define MY_PORT_B *(unsigned char *)0x23
#define MY_PORT_B_DDRB *(unsigned char *)0x24

#define MY_PORT_C *(unsigned char *)0x28
#define MY_PORT_C_DDRC *(unsigned char *)0x27

#define NS_RED (1 << 0)    // Pin 8 B
#define NS_YELLOW (1 << 1) // Pin 9 B
#define NS_GREEN (1 << 2)  // Pin 10 B

#define EW_RED (1 << 3)    // Pin 11 B 
#define EW_YELLOW (1 << 4) // Pin 12 B
#define EW_GREEN (1 << 5)  // Pin 13 B

#define BUTTON (1 << 0) // Pin 14 B

#define NS_RED_C (1 << 0)    // Pin 23 C
#define NS_GREEN_C (1 << 1) // Pin 24 C

#define EW_RED_C (1 << 2)    // Pin 25 C
#define EW_GREEN_C (1 << 3) // Pin 26 C

#define TURN_ON_LIGHT(LED) (MY_PORT_B |= LED)
#define TURN_OFF_LIGHT(LED) (MY_PORT_B &= ~LED)

#define custom_delay(delayMs)                       \
    for (int i = 0; i < delayMs; i++)               \
        \ 
                                             \
        {                                           \
            for (volatile int j = 0; j < 1000; j++) \
            {                                       \
            }                                       \
        }

void setup()
{
    MY_PORT_B_DDRB |= (NS_RED | NS_YELLOW | NS_GREEN | EW_RED | EW_YELLOW | EW_GREEN);
    MY_PORT_C_DDRC |= (NS_RED_C | NS_GREEN_C | EW_RED_C | EW_GREEN_C);
}

void loop()
{
    // NS && EW
    // Rødt
    TURN_ON_LIGHT(NS_RED);
    TURN_ON_LIGHT(EW_RED);
    TURN_OFF_LIGHT(NS_YELLOW);
    TURN_OFF_LIGHT(NS_GREEN);
    TURN_OFF_LIGHT(EW_YELLOW);
    TURN_OFF_LIGHT(EW_GREEN);
    custom_delay(3000);

    // NS
    // Rødt + Gult
    TURN_ON_LIGHT(NS_YELLOW);
    custom_delay(1000);

    // NS
    // Grønt
    TURN_OFF_LIGHT(NS_RED);
    TURN_OFF_LIGHT(NS_YELLOW);
    TURN_ON_LIGHT(NS_GREEN);
    custom_delay(5000);

    // NS
    // Gult
    TURN_OFF_LIGHT(NS_GREEN);
    TURN_ON_LIGHT(NS_YELLOW);
    custom_delay(1000);

    // NS
    // rødt
    TURN_OFF_LIGHT(NS_YELLOW);
    TURN_ON_LIGHT(NS_RED);
    custom_delay(2000);

    // EW
    // Rødt + Gult
    TURN_ON_LIGHT(EW_YELLOW);
    custom_delay(1000);

    // EW
    // Grønt
    TURN_OFF_LIGHT(EW_RED);
    TURN_OFF_LIGHT(EW_YELLOW);
    TURN_ON_LIGHT(EW_GREEN);
    custom_delay(5000);

    // NS
    // Gult
    TURN_OFF_LIGHT(EW_GREEN);
    TURN_ON_LIGHT(EW_YELLOW);
    custom_delay(1000);

    // Tilbage til rødt
    TURN_OFF_LIGHT(EW_YELLOW);
    TURN_ON_LIGHT(EW_RED);
    custom_delay(2000);
}

int main()
{
    setup();
    while (1)
    {
        loop();
    }
}