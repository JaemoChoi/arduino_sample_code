char input_buffer;
int value;

void setup(){
Serial.begin(9600);
}

void loop(){
    while(Serial.available()){
    input_buffer = Serail.read();
    value = atoi(input_buffer);         //convert char to int
    Serial.print(" Input Data : ");
    Serial.println(value);
    
  }
}
