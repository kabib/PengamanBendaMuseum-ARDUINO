// Program Alarm Keamanan Benda-benda Musium
//Sketch Oleh www.Kabib.net

int LDR= A2; // membuat variabel LDR untuk pin A2 (Analog PIN)
int LED= 4; // membuat variabel LED untuk pin 13 (DIGITAL PIN): LED Merupakan Variabel pin
int nilaiLDR= 0;  // variabel nilai awal untuk nilaiLDR
int BUZZER=3; //Variabel pin Buzzer (DIGITAL PIN)
void setup() {
  
  pinMode(LED, OUTPUT);// menentukan LED menjadi OUTPUT
  Serial.begin(9600);// komunikasi Arduino ke Komputer
  pinMode(BUZZER, OUTPUT); 
  digitalWrite(BUZZER, 1); //Apabila Buzzer Nyala di anga 1 maka ganti dengan 0
}

void loop() {
 digitalWrite(LED, HIGH); //LED selalu Nyala untuk memberikan penerangan ke Benda Musium dan LDR
 nilaiLDR= analogRead(LDR); // menyimpan nilai yang dibaca dari LDR ke variabel nilaiLDR
 Serial.print("NilaiLDR= "); 
 Serial.println(nilaiLDR);    
 if(nilaiLDR < 500) { // jika nilai dari LDR kurang dari 500
    digitalWrite(BUZZER, 0); //Buzzer Menyala
    delay(100);
    digitalWrite(BUZZER, 1); 
  }
  else  { // jika tidak
    digitalWrite(BUZZER, 1); //Buzzer Mati
    delay(100);
    digitalWrite(BUZZER, 1);
  }  
}
