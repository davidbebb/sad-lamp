
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


const char* ssid     = "your network ssid";
const char* password = "your password";
IPAddress ip(192, 168, 0, 177);    
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);
 

String webString="";

void handle_root() {
  server.send(200, "text/plain", "Hello. I am a light bulb");
  delay(100);
}
 
void setup(void)
{
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
  
  server.on("/temp", [](){  

    server.send(200, "text/plain", webString);           
  });

  server.on("/humidity", [](){  

    server.send(200, "text/plain", webString);               
  });
  
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void)
{
  server.handleClient();
} 


