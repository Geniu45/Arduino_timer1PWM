//PWM pentru Servo
void PWM_setup()
{
  DDRB |= (1<<PB3);// Initilizam iesirea Timer1
  OCR1A  = 40000;  // T = 20ms; 20000 / 62.5ns * prescalar
  TCCR1A =  0x21;  // OCRB Output 
  TCCR1B =   0x12; // Mod 9, prescalar 8
  OCR1B  = 3000;   //Duty cycle
}

void Timer2_Setup()
{
  TCCR2A |= (1<<COM2A1)|(1<<WGM21);
  TCCR2B |= (1<<CS22)|(1<<CS21)|(1<<CS22);
  OCR2A = 40;
  TIMSK2 = (1<<OCIE2A);
}

ISR(TIMER2_COMPA_vect)
{
  TCNT2 = 0;
  PORTD ^= 0x20;
}
