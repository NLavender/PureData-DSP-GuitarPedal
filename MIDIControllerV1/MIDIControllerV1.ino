//#include <Bounce2.h>
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

int potNumber = 15;
int switchNumber = 6;
int lightNumber = 6;

//define channel
  int channel = 1;

  

//Arrays
  int potInput[15]{ A9, A8, A7, A6, A5, A4, A3, A2, A1, A0, A22, A21, A20, A19, A18};
  int potValue[15];
  int potChange[15];
  int potMIDI[15]{ 7, 73, 75, 72, 5, 91, 92, 74, 71, 93, 95, 94, 77, 76, 78};

  int switchInput[6]{ A17, A16, A15, A14, A12, A13};
  bool switchOnOff[6];
  bool switchChange[6];
  int switchMIDI[6]{ 65, 0, 3, 4, 9, 11};

  int LEDOutput[6]{ 2, 3, 4, 5, 6, 7};

  
void setup() {
  
  Serial.begin(9600);
  
  //pots
  pinMode(23, INPUT_PULLUP);   //Input Gain
  pinMode(22, INPUT_PULLUP);   //Delay Time
  pinMode(21, INPUT_PULLUP);   //Delay Decay
  pinMode(20, INPUT_PULLUP);   //Rev Wet
  pinMode(19, INPUT_PULLUP);   //Rev Dry
  pinMode(18, INPUT_PULLUP);   //Trem Rate
  pinMode(17, INPUT_PULLUP);   //Trem Depth
  pinMode(16, INPUT_PULLUP);   //Dist Gain
  pinMode(15, INPUT_PULLUP);   //Dist Cutoff
  pinMode(14, INPUT_PULLUP);   //Comp Gain
  pinMode(A21, INPUT_PULLUP);  //Comp Threshold
  pinMode(A22, INPUT_PULLUP);  //Comp Ratio
  pinMode(39, INPUT_PULLUP);   //High
  pinMode(38, INPUT_PULLUP);   //Med
  pinMode(37, INPUT_PULLUP);   //Low

  //switches
  pinMode(36, INPUT);          //OnOff
  pinMode(35, INPUT);          //Delay
  pinMode(34, INPUT);          //Reverb
  pinMode(33, INPUT);          //Tremolo
  pinMode(32, INPUT);          //Distortion
  pinMode(31, INPUT);          //Compressor

  //LEDs
  pinMode(2, OUTPUT);          //OnOff
  pinMode(3, OUTPUT);          //Delay
  pinMode(4, OUTPUT);          //Reverb
  pinMode(5, OUTPUT);          //Tremolo
  pinMode(6, OUTPUT);          //Distrtion
  pinMode(7, OUTPUT);          //Compressor

  //set all pots to current value
  for (int i = 0; i < potNumber; i++){
    potChange[i] = analogRead(potInput[i]);
  }

  //set all switches to off
  for (int i = 0; i < switchNumber; i++){
    switchOnOff[i] = false;
    switchChange[i] = false;
  }
  

}






void loop() {

  //pots
  for (int i = 0; i < potNumber; i++){
    potValue[i] = analogRead(potInput[i]);

    if (abs(potValue[i] - potChange[i]) > 8){
      potChange[i] = potValue[i];
      //Serial.println(potValue[i] / 8);
      usbMIDI.sendControlChange(potMIDI[i], potValue[i] / 8, channel);
    }

  }


  //switches and lights
  for (int i = 0; i < switchNumber; i++){
    
    if (analogRead(switchInput[i]) < 1023){
      switchOnOff[i] = true;
      digitalWrite(LEDOutput[i], HIGH);
      //Serial.println(switchOnOff[i]);
      //usbMIDI.sendControlChange(switchMIDI[i],switchOnOff[i], channel);
    }else{
      switchOnOff[i] = false;
      digitalWrite(LEDOutput[i], LOW);
      
    }
    
    
    if (switchOnOff[i] != switchChange[i]){
      switchChange[i] = switchOnOff[i];
      usbMIDI.sendControlChange(switchMIDI[i], switchOnOff[i], channel);
      //Serial.println(switchOnOff[i]);
      
    }
    
  }



  //Serial.println("done");
  //Serial.println(analogRead(A17));
  delay(10);

  

}
