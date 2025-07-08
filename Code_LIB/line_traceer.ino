#define LmotorCW 5
#define LmotorCCW 6

#define RmotorCW 9
#define RmotorCCW 10

#define IRL 7
#define IRR 8

iint Speed = 50;

void setup(){
pinMode(LmotorCW,OUTPUT);
pinMode(LmotorCCW,OUTPUT);
pinMode(RmotorCW,OUTPUT);
pinMode(RmotorCCW,OUTPUT);

pinMode(IRL,INPUT);
pinMode(IRR,INPUT);
}

void loop(){

if (digitalRead(IRL) == HIGH && digitalRead(IRR) == HIGH) {
analogWrite(LmotorCW,0);
analogWrite(LmotorCCW,Speed);

analogWrite(RmotorCW,Speed);
analogWrite(RmotorCCW,0);

}
elseif (digitalRead(IRL) == LOW && digitalRead(IRR) == HIGH) {
analogWrite(LmotorCW,0);
analogWrite(LmottoCCW,Speed);

analogWrite(RmotorCW,0);
analogWrite(RmottoCCW,Speed);
}

else if (digitalRead(IRL) == HIGH && digitalRead(IRR) == HIGH){
analogWrite(LmotorCW,Speed);
analogWrite(LmottoCCW,0);

analogWrite(RmotorCW,Speed);
analogWrite(RmottoCCW,0);
}

else if (digitalRead(IRL) == LOW && digitalRead(IRR) == LOW){
analogWrite(LmotorCW,0);
analogWrite(LmottoCCW,0);

analogWrite(RmotorCW,0);
analogWrite(RmottoCCW,0);

}

}
