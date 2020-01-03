#define ENA   14          // povoluje rychlost motoru doprava  na pinu GPIO14(D5)
#define ENB   12          // povoluje rychlost motoru doleva  na pinu GPIO12(D6)

#define IN_1  15          // L298N in1 motor doprava na pinu  GPIO15(D8)
#define IN_2  13          // L298N in2 motor doprava na pinu  GPIO13(D7)
#define IN_3  2           // L298N in3 motor doleva na pinu GPIO2(D4)
#define IN_4  0           // L298N in4 motor doleva na pinu GPIO0(D3)

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

int rychlost = 800;         // 400 - 1023.
int koeficient = 3;
int cislo;  // Proměnná do které se uloží hodnota poslaná aplikací ve stringu a následném převedení funkcí toInt().

const char* ssid = "Auticko";

ESP8266WebServer server(80); 

void HTTP_handleRoot(void) {

  if (server.hasArg("State")) {   //Když program příjme hodnotu state, uloží se do proměnné číslo převedený string na int.
  cislo = server.arg("State").toInt();
    
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}


void setup() {  //Nastavení pinů
 
 pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT);  

 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT); 
  
  Serial.begin(115200); //Nastavení komunikačního portu na 115200
  
// Připojení k wifi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress mojeIP = WiFi.softAPIP(); //Výpis IP adresy pro zadání do mobilní aplikace.
  Serial.print("IP adresa je: ");
  Serial.println(mojeIP);
 
 // Zapojení web serveru 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}

//Fuknce pro řízení auta

void dopredu(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, rychlost);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, rychlost);
  }

void dozadu(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, rychlost);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, rychlost);
  }

void doprava(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, rychlost);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, rychlost);
  }

void doleva(){

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, rychlost);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, rychlost);
  }

void stop(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, rychlost);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, rychlost);
 }

void loop() {
    server.handleClient();
      //Porovnávání hodnot v proměnné číslo ve switchi, pokud se vyhodnotí jako pravda, je vyvolána příslušná funkce. 
    
    switch(cislo){
      case 1:
        dopredu();
      break;
      case 4:
         dozadu();
      break;
      case 3:
          doleva();
      break;
      case 2:
        doprava();
      break;
      case 5:
        stop();
      break;
    }
}

