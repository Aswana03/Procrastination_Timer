#include <esp_now.h>
#include <WiFi.h>

#define vry 23
#define trigPin 12  // Define the trigger pin for ultrasonic sensor
#define echoPin 14  // Define the echo pin for ultrasonic sensor
#define controlPin1 18 // Define pin 2 for control output
#define controlPin2 19
#define controlPin3 21

uint8_t broadcastAddress[] = {0xC8, 0x2B, 0x96, 0x19, 0xEF, 0xDB};  // C8:2B:96:19:EF:DB

typedef struct struct_message {
  int x;
  int y;
} struct_message;

struct_message data;
esp_now_peer_info_t peerInfo;

int pushUpCount = 0;  // Initialize push-up counter
int lastDistance = 0;  // To store the last distance for comparison

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  // Callback when data is sent
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  pinMode(vry, INPUT_PULLDOWN);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(controlPin3, OUTPUT); 
  // Set pin 2 as output
}

long readUltrasonicDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;  // Convert to distance in centimeters
}

void loop() {
  // Read joystick inputs
  data.y = digitalRead(vry);

  // Measure distance using the ultrasonic sensor
  int distance = readUltrasonicDistance();

  // Detect a push-up based on distance threshold (e.g., closer than 10 cm)
  if (distance < 10 && lastDistance >= 10) {
    pushUpCount++;
    Serial.print("Push-up count: ");
    Serial.println(pushUpCount);
  }
  lastDistance = distance;  // Update the last measured distance

  // Set data.x to 1 when push-up count reaches 10, otherwise set to 0
  if (pushUpCount >= 10) {
    data.x = 1;
  } else {
    data.x = 0;
  }

  // Control pin 2 based on the value of data.x
  if (data.x == 1) {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW); 
    digitalWrite(controlPin3, HIGH);  // Set pin 2 LOW
     // Set pin 2 LOW
      // Set pin 2 LOW
    delay(1000);
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);  
    digitalWrite(controlPin3, LOW);  // Set pin 2 LOW
    // Set pin 2 LOW





    
  } else {
    digitalWrite(controlPin1, HIGH); // Set pin 2 HIGH
  }

  // Send data via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &data, sizeof(data));

  // Print data to Serial Monitor
  Serial.print("x: ");
  Serial.print(data.x);
  Serial.print("\t y: ");
  Serial.println(data.y);

  delay(100); 
}
