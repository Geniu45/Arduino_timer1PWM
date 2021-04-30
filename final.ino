/*
CLK  - output  A  PD2
DT   - output  B  PD3 
SW   - button  S  PD4
OC1B - servom  10 PB2
*/
byte button_state = 16;     // starea butonului HIGH (din program initial is pe HIGH)
byte last_button_state = 0; // memomoram ultima starea butonului
int contor = 1;            // stare multiplicator

byte lastStateCLK = "";    // ultima stareCLK
byte currentStateCLK = ""; // stare curenta CLK
int degree_to_move = 2000; // setam servo in pozitia de 90

void setup() {
  Serial.begin(9600);
  initPort();
  PWM_setup();
  Timer2_Setup();
  lastStateCLK = (PIND & (1<<PD2)); // actualizam starea anterioara
}

void loop() {
  read_encoder();
  read_button();
  Serial.println(degree_to_move);
}

//Initializare Porturi
void initPort()
{
  DDRD |= (1<<PD5);
  DDRB |= (1<<PB4)|(1<<PB5)|(1<<PB0);
  PORTD |= (1<<PD4);
}

void activate_led()
{
  
}
