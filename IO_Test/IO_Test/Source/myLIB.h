void Delay(unsigned int time);
int  random(int val);

void Uart_Init(int baudrate);
char Uart_Getch(void);
char Uart_Getkey(void);
void Uart_Putch(char data);
void Uart_SendByte(int data);
void Uart_PutStr(char *pt);
void Uart_Printf(char *fmt,...);

void Sound(int freq);
void Nosound(void);

#define	CFG_HZ				1562500
