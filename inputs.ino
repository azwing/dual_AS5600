#define AZ_up PA0
#define AZ_down PA1
#define Alt_up PA2
#define Alt_down PA3

int AZ_state, Alt_state;


void inputs_init(){
  pinMode(AZ_up, INPUT_PULLUP);
  pinMode(AZ_down, INPUT_PULLUP);
  pinMode(Alt_up, INPUT_PULLUP);
  pinMode(Alt_down, INPUT_PULLUP);
}

void  get_button(){
  if (millis() - temps < 200) return;
  temps=millis();
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
}
