void moveServo(int degree)
{
  
  switch(contor){
    case 1 : Serial.println("x1"); break;
    case 2 : Serial.println("x3"); break;
    case 3 : Serial.println("x4"); break;
  };
  
  OCR1B = degree;
}
