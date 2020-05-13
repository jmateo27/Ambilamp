int value = 10; 
int light;
int value1;
int value2;
int pot;
int diff;
float redratio;
float greenratio;
float blueratio;

//Read values when reaches certain amount of time light level stays constant


void setup() // put your setup code here, to run once: 
{

  Serial.begin(9600);

  pinMode(11, OUTPUT); // red
  pinMode(10, OUTPUT); // green
  pinMode(9, OUTPUT); // blue

} // setup


void loop()
{

  // ---------------------------------- Determining average sensor value (value)

  value1 = analogRead(A0);
  value2 = analogRead(A1);
  value = (value1 + value2)/2;  

  // ----------------------------- Determining Constant Light value (light)

  if (value < 50)
  {
    light = 255;
  }

  if(value > 50 && value < 120)
  {
    light = 120;
  }

  if(value > 120)
  {
    light = 0;
  }

  // ---------------------------------- Determining output value (diff)
  
  diff = light - value;

  //delay(200) --------------- may need delay here, we'll see

  if(diff < 0 )
  {
    diff = 0;
  }

  // ---------------------------------------------- Light Output
  
  pot = analogRead(A3);
  Serial.println(pot);

  if (pot >= 300 && pot <= 600) // white light
  {
    redratio = 1.0;
    blueratio = 1.0;
    greenratio = 1.0;
  
    analogWrite(11, diff*redratio);
    analogWrite(10, diff*greenratio);
    analogWrite(9, diff*blueratio );

  } // end if: white light


  else if (pot < 300) // warm white light
  {
    redratio = 1.0;
    blueratio = 0.95;
    greenratio = 0.9;
  
    analogWrite(11, diff*redratio);
    analogWrite(10, diff*greenratio);
    analogWrite(9, diff*blueratio );

  } // end if: warm white

    
  else if (pot > 600) // blue light
  {
    redratio = 0.5;
    blueratio = 1.0;
    greenratio = 0.5;
  
    analogWrite(11, diff*redratio);
    analogWrite(10, diff*greenratio);
    analogWrite(9, diff*blueratio);

  }  } // end if: blue light
