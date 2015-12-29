
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


const char* ssid     = "your network ssid";
const char* password = "your password";
IPAddress ip(192, 168, 0, 177);    
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

int red = 10; 
int blue = 9; 
int green = 11; 
int uv = 6;

float uv_sun = 0;//0.95935;
float b_sun =  .2;//1.00000;
float g_sun = .6;//0.6;
float r_sun =  1;//0.48;
 

String webString="";

void handle_root() {
  server.send(200, "text/plain", "Hello. I am a light bulb. /on or /off");
  delay(100);
}
 
void setup(void)
{
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(uv, OUTPUT);
  
  Serial.begin(115200); 

  
  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);
  Serial.print("\n\r \n\rWorking to connect");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
   
  server.on("/", handle_root);
  
  server.on("/off", [](){  
    set_brightness(0);
    webString = 'Lights are now off';
    server.send(200, "text/plain", webString);           
  });

  server.on("/on", [](){  
    set_brightness(255);
    webString = 'Lights are now on';
    server.send(200, "text/plain", webString);               
  });
  
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void)
{
  server.handleClient();
} 


void set_brightness(int brightness){
    
  float bb = b_sun*brightness;
  float bg = g_sun*brightness;
  float br = r_sun*brightness;
  float bu = uv_sun*brightness;
  
  analogWrite(red,(int)br);
  analogWrite(blue,(int)bb);  
  analogWrite(green,(int)bg);
  analogWrite(uv, (int)bu);  
  
}

