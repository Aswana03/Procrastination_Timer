#include <espnow.h>
#include <ESP8266WiFi.h>  // Use ESP8266 WiFi library

#define in1 D1  // Define GPIO pins according to ESP8266
#define in2 D2
#define in3 D5
#define in4 D6

// Structure to hold incoming data
typedef struct struct_message {
  int x;
  int y;
} struct_message;

struct_message data;

void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&data, incomingData, sizeof(data));

  Serial.print("X: ");
  Serial.print(data.x);
  Serial.print("\tY: ");
  Serial.println(data.y);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);  // Set ESP8266 as Wi-Fi station

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);  // Set device as a slave
  esp_now_register_recv_cb(OnDataRecv);       // Register receive callback

  // Set pin modes
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // No code needed here as everything is handled in OnDataRecv
}
