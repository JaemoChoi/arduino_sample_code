char buffer[20]; 
char bufferIndex = 0; 

void setup(){
  Serial.begin(9600);
}

void loop(){
    while(Serial.available()){
        buffer[bufferIndex] = Serial.read();
        bufferIndex++;
    }
    int data = atoi(buffer);
    Serial.print(" Input Data : ");
    Serial.println(data);
    
    for (int i = 0; i < 21 ; i++){
        buffer[i] = NULL;
    }
    bufferIndex = 0;
}
