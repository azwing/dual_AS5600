#define AZ_up PA0
#define AZ_down PA1
#define Alt_up PA2
#define Alt_down PA3
#define Zero  PA4

int AZ_state, Alt_state;


void inputs_init(){
  pinMode(AZ_up, INPUT_PULLUP);
  pinMode(AZ_down, INPUT_PULLUP);
  pinMode(Alt_up, INPUT_PULLUP);
  pinMode(Alt_down, INPUT_PULLUP);
  pinMode(Zero, INPUT_PULLUP);
}

void  get_button(){
  AZ_state=0;
  Alt_state=0;
  if (!digitalRead(AZ_up)) AZ_state=1;
  if (!digitalRead(AZ_down)) AZ_state=-1;
  if (!digitalRead(Alt_up)) Alt_state=1;
  if (!digitalRead(Alt_down)) Alt_state=-1;
  if(AZ_state!=0){
    offset_az+=AZ_state;
    if (offset_az<-2048) offset_az=-2048;
    if (offset_az>2048) offset_az=2048;
  }
  if(Alt_state!=0){
    offset_alt+=Alt_state;
    if (offset_alt<-2048) offset_alt=-2048;
    if (offset_alt>2048) offset_alt=2048;
  }
  if(!digitalRead(Zero)){
    if ((az()<50 | az()> 4046) & (alt()<50 | alt()>4046)){  // Reset to Zero only less +/- 5° 
      offset_az=-az();
      offset_alt=-alt();
    }
  }
}
