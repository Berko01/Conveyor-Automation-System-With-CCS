#include <main.h>
int counter = 0;
void main()
{
   set_tris_b(0x00);
   set_tris_a(0xff);
   output_b(0x00);
   
   while(input(pin_A2) == 0); //Start.
   
   output_b(0b00000101); //M1==>ON
   
   while(TRUE)
   {
      while(input(pin_A0) == 0);//Did the sensor detect?
      delay_ms(70);
      while(input(pin_A0) == 1); //Has the product passed?
      delay_ms(70);
      counter++;
      if(counter != 10)
      continue;
      output_b(0b00011000);
      while(input(pin_A1) == 0);//Did the sensor detect?
      delay_ms(70);
      while(input(pin_A1) == 1); //Has the product passed?
      delay_ms(70);
      output_b(0b00000101); //M1==>ON
      counter = 0;
   }

}
