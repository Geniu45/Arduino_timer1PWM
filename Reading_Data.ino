//Citim valoare encoderului
void read_encoder()
{
currentStateCLK = (PIND & (1<<PD2)); //citim starea curenta a encoderului.
  // daca aceasta e diferita, si e high 
  if (currentStateCLK != lastStateCLK && currentStateCLK == 0x4) 
   { 
     if(((PIND & (1<<PD3))-4) != currentStateCLK)
     {
      
      degree_to_move-=10;
     }
     else
     {
      degree_to_move+=10;
     }
    }
   // Actualizam ultima stare CLK
   lastStateCLK = currentStateCLK;
   moveServo(degree_to_move);
}

//Citim valoarea butonului.
void read_button()
{
  button_state = (PIND & (1<<PD4));
  if(button_state != last_button_state)
  {
     if (button_state == 0)
    {
       
     degree_to_move = 2000;
     contor++;
    }
      
   }
   if(contor>3)
   {
    contor=1;
   }
   //Serial.println(contor); 
   last_button_state = button_state;  
}
  
