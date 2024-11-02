#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int alarmHour = 6;
int alarmMinute = 0;
bool alarmEnabled = false;
bool alarmTriggered = false;
unsigned long alarmOffTime = 0;

// Button pins
const int setAlarmButton = 2;
const int incrementHourButton = 3;
const int incrementMinuteButton = 4;
const int alarmLED = 13;

void setup() {
  pinMode(setAlarmButton, INPUT_PULLUP);
  pinMode(incrementHourButton, INPUT_PULLUP);
  pinMode(incrementMinuteButton, INPUT_PULLUP);
  pinMode(alarmLED, OUTPUT);

  lcd.init();
  lcd.backlight();

  if (!rtc.begin()) {
    lcd.print("Couldn't find RTC");
    while (1);
  }
  
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Set to compile time
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(2024, 10, 31, 0, 0, 0)); // Manually set if RTC is stopped
  }
}

void loop() {
  DateTime now = rtc.now();

  // Display current time
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  printTwoDigits(now.hour());
  lcd.print(":");
  printTwoDigits(now.minute());
  lcd.print(":");
  printTwoDigits(now.second());

  // Display alarm time
  lcd.setCursor(0, 1);
  lcd.print("Alarm: ");
  printTwoDigits(alarmHour);
  lcd.print(":");
  printTwoDigits(alarmMinute);
  lcd.print(alarmEnabled ? " ON " : " OFF");

  // Check for alarm activation
  if (alarmEnabled && now.hour() == alarmHour && now.minute() == alarmMinute && !alarmTriggered) {
    digitalWrite(alarmLED, HIGH);
    alarmTriggered = true;
    alarmOffTime = millis() + 60000;  // Keep LED on for 1 minute
  }

  // Turn off alarm LED after 1 minute
  if (alarmTriggered && millis() > alarmOffTime) {
    digitalWrite(alarmLED, LOW);
    alarmTriggered = false;
  }

  // Button checks
  if (digitalRead(setAlarmButton) == LOW) {
    delay(200);  // Debounce delay
    alarmEnabled = !alarmEnabled;
  }
  
  if (digitalRead(incrementHourButton) == LOW) {
    delay(200);
    alarmHour = (alarmHour + 1) % 24;
  }
  
  if (digitalRead(incrementMinuteButton) == LOW) {
    delay(200);
    alarmMinute = (alarmMinute + 1) % 60;
  }
}

void printTwoDigits(int number) {
  if (number < 10) lcd.print("0");
  lcd.print(number);
}
// Function to read/write alarm settings from/to EEPROM
void saveAlarmSettings() {
  EEPROM.write(0, alarmHour);
  EEPROM.write(1, alarmMinute);
  EEPROM.write(2, alarmEnabled ? 1 : 0);
}

void loadAlarmSettings() {
  alarmHour = EEPROM.read(0);
  alarmMinute = EEPROM.read(1);
  alarmEnabled = EEPROM.read(2) == 1;
}

// Improved debounce function
bool debounceButton(int buttonPin) {
  static unsigned long lastPressTime = 0;
  if (digitalRead(buttonPin) == LOW && (millis() - lastPressTime) > 200) {
    lastPressTime = millis();
    return true;
  }
  return false;
}