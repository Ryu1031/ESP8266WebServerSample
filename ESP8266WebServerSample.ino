#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define WIFI_SSID ""
#define WIFI_PWD ""

ESP8266WebServer server(80);

void handleRoot() {
  Serial.println("receive req: /");
  server.send(200, "text/html", "<h1>Hello world</h1>");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.begin();
}
void loop() {
  server.handleClient();
}

