#include<avr/io.h>
#include<util/delay.h>
void lcd_init(){
lcd_cmd(0X02);
lcd_cmd(0X28);
lcd_cmd(0X0C);
lcd_cmd(0X06);
lcd_cmd(0X01);
lcd_cmd(0X04);
}
void lcd_cmd(int cmd)
{
PORTB=cmd&0XF0;
PORTB=PORTB +0X04;
_delay_ms(1);
PORTB=PORTB-0X04;
PORTB=((cmd<<4)&0XF0);
PORTB=0X04+PORTB;
_delay_ms(1);
PORTB=PORTB-0X04;
}
void lcd_data(int data)
{
PORTB=data &0XF0;
PORTB=PORTB+0X05;
_delay_ms(1);
PORTB=PORTB-0X04;
PORTB=(data<<4)&0XF0;
PORTB=PORTB+0X05;
_delay_ms(1);
PORTB=PORTB-0X04;
}
void lcd_string(char *str)
{
 int i=0;
 while(str[i]!='\0')
{
lcd_data(str[i]);
i++;
}
}

void lcd_num(int num)
{
int a=0;
if(num==0)
{
lcd_data(48);
}

lcd_cmd(0X04);
while(num!=0)
{
a=num%10;
lcd_data(48+a);
num=num/10;
}
lcd_cmd(0X06);
}

int main()
{
DDRB=0XFF;
lcd_init();
_delay_ms(10);
int X=5389;
lcd_cmd(0X87);
lcd_num(X);
}














