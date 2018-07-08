#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

static const char *ssid = "ServerModeByESP8266";
static const char *pwd = "12341234";

ESP8266WebServer server(80);
IPAddress ip( 192, 168, 100, 20); 
IPAddress subnet( 255, 255, 255, 0 ); 

void handleRoot() {
    Serial.println("receive req: /");
    server.send(200, "text/html", "<h1>Hello world</h1>");
}

void setup() { 
  Serial.begin(9600);
  WiFi.mode(WIFI_AP); 
  WiFi.softAPConfig(ip, ip, subnet); 
  WiFi.softAP(ssid, pwd); 
  server.on("/", handleRoot); 
  server.begin();
  Serial.println("ap setup..."); 
} 
void loop() { 
  server.handleClient(); 
}
