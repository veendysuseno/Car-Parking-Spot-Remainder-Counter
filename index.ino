#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define Sensor_Masuk 2
#define Sensor_Keluar 3

int Kondisi_Masuk;
int Kondisi_Keluar;
bool Kendaraan_Masuk = false;
bool Kendaraan_Keluar = false;
int Jumlah_Ruang = 400;

void setup() {
  lcd.init ();
  lcd.setBacklight(HIGH);
  pinMode(Sensor_Masuk, INPUT);
  pinMode(Sensor_Keluar, INPUT);
}

void loop() {
  Kondisi_Masuk = digitalRead(Sensor_Masuk);
  Kondisi_Keluar = digitalRead(Sensor_Keluar);

  if(Kondisi_Masuk == LOW && Kendaraan_Masuk){
    Jumlah_Ruang -= 1; 
    Kendaraan_Masuk = false;
  }
  else if(Kondisi_Masuk == HIGH && !Kendaraan_Masuk){
    Kendaraan_Masuk = true;
  }

  if(Kondisi_Keluar == LOW && Kendaraan_Keluar){
    Jumlah_Ruang += 1; 
    Kendaraan_Keluar = false;
  }
  else if(Kondisi_Keluar == HIGH && !Kendaraan_Keluar){
    Kendaraan_Keluar = true;
  }

  lcd.setCursor(0,0);
  lcd.print("Ruang Parkir");
  lcd.setCursor(0,1);
  lcd.print(Jumlah_Ruang);
  delay(200);
  lcd.clear();
}
