#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "smarthome-f62e8.firebaseio.com"                    
#define FIREBASE_AUTH "sDNAqf3Gg6anDQRCdaPaz4odKRInZ0apYyRRzwk6"       
#define WIFI_SSID "SushilTularambagh"                                         
#define WIFI_PASSWORD "aviralsunny"                                   

#define Relay1 16 //D0
int val1;

#define Relay2 5 //D1
int val2;

#define Relay3 4  //D2
int val3;

#define Relay4 0 //D3
int val4;

#define Relay5 2 //D4
int val5;

#define Relay6 14 //D5
int val6;

#define Relay7 12 //D6
int val7;

#define Relay8 13 //D7
int val8;

#define Relay8 15 //D8           //NC
int val9;

void setup() 
{
  Serial.begin(115200);                                                   // Select the same baud rate if you want to see the datas on Serial Monitor
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);
  pinMode(Relay4,OUTPUT);

  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.setInt("S1",0);                     //Here the varialbe"S1","S2","S3" and "S4" needs to be the one which is used in our Firebase and MIT App Inventor
  Firebase.setInt("S2",0); 
  Firebase.setInt("S3",0); 
  Firebase.setInt("S4",0); 
  
}
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }

void loop() 
{
 // if (Firebase.failed())
    //{
    // Serial.print("setting number failed:");
    // Serial.println(Firebase.error());
        firebasereconnect();
    //  return;
     // }
      
  val1=Firebase.getString("S1").toInt(); 
  if(val1==1)
  {
      digitalWrite(Relay1,HIGH);
      Serial.println("1 ON");
    }
    else if(val1==0)                                                   
    {                                      
      digitalWrite(Relay1,LOW);
      Serial.println("1 OFF");
    }

  val2=Firebase.getString("S2").toInt();                                       
  
  if(val2==1)                                                             
     {
      digitalWrite(Relay2,HIGH);
      Serial.println("2 ON");
    }
    else if(val2==0)                                                      
    {                                      
      digitalWrite(Relay2,LOW);
      Serial.println("2 OFF");
    }

   val3=Firebase.getString("S3").toInt();                                        
  
  if(val3==1)                                                          
     {
      digitalWrite(Relay3,HIGH);
      Serial.println("3 ON");
    }
    else if(val3==0)                                                     
    {                                      
      digitalWrite(Relay3,LOW);
      Serial.println("3 OFF");
    }

   val4=Firebase.getString("S4").toInt();                                       
  
  if(val4==1)                                                             
     {
      digitalWrite(Relay4,HIGH);
      Serial.println("4 ON");
    }
    else if(val4==0)                                                      
    {                                      
      digitalWrite(Relay4,LOW);
      Serial.println("4 OFF");
    }
     
     val5=Firebase.getString("S5").toInt();                                        
  
  if(val5==1)                                                            
     {
      digitalWrite(Relay5,HIGH);
      Serial.println("5 ON");
    }
    else if(val5==0)                                                   
    {                                      
      digitalWrite(Relay5,LOW);
      Serial.println("5 OFF");
    }
    val6=Firebase.getString("S6").toInt();                                        
  if(val6==1)                                                             
     {
      digitalWrite(Relay6,HIGH);
      Serial.println("6 ON");
    }
    else if(val6==0)                                                      
    {                                      
      digitalWrite(Relay6,LOW);
      Serial.println("6 OFF");
    }
    val7=Firebase.getString("S7").toInt();                                     
  
  if(val7==1)                                                             
     {
      digitalWrite(Relay7,HIGH);
      Serial.println("7 ON");
    }
    else if(val7==0)                                                     
    {                                      
      digitalWrite(Relay7,LOW);
      Serial.println("7 OFF");
    }
    val8=Firebase.getString("S8").toInt();                                       
  
  if(val8==1)                                                          
     {
      digitalWrite(Relay8,HIGH);
      Serial.println("8 ON");
    }
    else if(val8==0)                                                      
    {                                      
      digitalWrite(Relay8,LOW);
      Serial.println("8 OFF");
    }         
}
