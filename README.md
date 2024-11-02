<img width="1280" alt="readme-banner" src="https://github.com/user-attachments/assets/35332e92-44cb-425b-9dff-27bcf1023c6c">

# Procrastination_Timer 🎯


## Basic Details
### Team Name: Triple AAA


### Team Members
- Team Lead: Akshay Nandan P - NSSCE,Palakkad
- Member 2: Abhishek - NSSCE,Palakkad
- Member 3: Aswana N - NSSCE,Palakkad

### Project Description
The Procrastination Timer is an interactive alarm clock designed to prevent users from hitting the snooze button by requiring them to complete engaging tasks to silence the alarm. Combining creativity and fun, it offers various mental and physical challenges, ensuring a more stimulating wake-up experience.

### The Problem (that doesn't exist)
The Procrastination Timer Alarm Clock humorously addresses the common and often ridiculous habit of hitting the snooze button and going back to sleep instead of starting the day. By incorporating interactive tasks and challenges that users must complete to turn off the alarm, it tackles the absurdity of our reluctance to get out of bed. The project embraces creativity and fascination, transforming a mundane routine into a playful engagement that highlights the lengths people go to avoid waking up—essentially turning the act of procrastination itself into a comical challenge.

### The Solution (that nobody asked for)
The Procrastination Timer Alarm Clock takes a fun and lighthearted approach to solving the snooze-button dilemma. Instead of simply sounding an alarm, it turns waking up into an entertaining game. Users are greeted with quirky tasks—like solving a riddle, doing a quick dance, or even completing a silly challenge—that must be tackled to silence the alarm. This playful interaction not only makes getting out of bed a bit more enjoyable but also sparks laughter and creativity, transforming the dreaded morning routine into a delightful adventure. By combining humor with a bit of a wake-up challenge, we're turning procrastination into a fun opportunity to kickstart the day!

## Technical Details
### Technologies/Components Used
For Software:
- Arduino IDE
- Library ESP32
- ESP32 NOW
- WIFI.h
- Arduino.h

For Hardware:
- ESP32
- Arduino Nano
- Ultrasonic sensors
- L298 Motor Driver and Motors
- REAL TIME CLOCK
- LCD display
- MP3 Module
- Speaker
- Passive Infrared sensor(PIR)


### Implementation
For Software:
# Installation
[commands]

# Run
[commands]

### Project Documentation
For Software:

# Screenshots (Add at least 3)
!![image](https://github.com/user-attachments/assets/5366cf65-492d-45a6-9c7d-0ea9ae3d633c)
(Add screenshot 1 here with proper name)
Setting the alarm time('ON' indicates that the alarm is set)

!![image](https://github.com/user-attachments/assets/c5757f77-dc45-46ad-a32e-2125b7a2725a)
(Add screenshot 2 here with proper name)
When the time ticks,the signal is high.(The led is given as an indicator to recognize the high signal)

!![image](https://github.com/user-attachments/assets/c3354ace-2058-416d-b5d8-1fc24f5ef9c1)
(Add screenshot 3 here with proper name)
ULT Sensor counting the number of pushups until the target

# Diagrams
!![image](https://github.com/user-attachments/assets/fc656ff5-872a-4303-b8e1-01ecd00a12a2)
(Add your workflow/architecture diagram here)
1. ESP32:
The ESP32 appears to be the main microcontroller, connected to various components.
It controls two ultrasonic sensors (labeled "ULT") for distance measurement or object detection.
2. L298 Motor Driver:
The ESP32 is connected to an L298 motor driver, which controls two motors (labeled "M1" and "M2").
This setup likely enables movement or rotation.
3. L298 Motor Driver:
The ESP32 is connected to an L298 motor driver, which controls two motors (labeled "M1" and "M2").
This setup likely enables movement or rotation.
4. Arduino Nano:
The Arduino Nano works with the ESP32, connected to a Real-Time Clock (RTC) module for timekeeping and an LCD for display.
Push buttons are connected with the arduino nano for the purpose of time setting.
5. MP3 Module and Speaker:
An MP3 module is linked to the ESP32, allowing audio output, which is played through the connected speaker. This is used for alarms and voice prompts.
6. Arduino Nano:
The Arduino Nano works with the ESP32, connected to a Real-Time Clock (RTC) module for timekeeping and an LCD for display.
Push buttons are connected with the arduino nano for the purpose of time setting.
7. ESP32 CAM:
The ESP32 CAM module is included for image or video capture, adding a visual element to the project for internal monitoring.
8. Additional ESP32 with PIO:
Another ESP32 unit is connected to a "PIO" and an additional ultrasonic sensor. The purpose of the PIO(Piezoelectric sensor is to detect the motion of human ie;whether he is awake or not

For Hardware:

# Schematic & Circuit
![Circuit](Add your circuit diagram here)
*Add caption explaining connections*

![Schematic](Add your schematic diagram here)
*Add caption explaining the schematic*

# Build Photos
!![image](https://github.com/user-attachments/assets/7f7c6eb1-f0f3-488d-ae0e-1b17255128d6)
(Add photo of your components here)
- ESP32
- Arduino Nano
- Ultrasonic sensors
- L298 Motor Driver and Motors
- REAL TIME CLOCK
- LCD display
- MP3 Module
- Speaker
- Passive Infrared sensor

![Build](Add photos of build process here)
*Explain the build steps*

![Final](Add photo of final product here)
*Explain the final build*

### Project Demo
# Video
[Add your demo video link here]
*Explain what the video demonstrates*

# Additional Demos
[Add any extra demo materials/links]

## Team Contributions
- Akshay Nandan P: Software codes for communication for ESP32 and ULT sensors.
- Aswana N: Software codes for Arduino nano for interfacing mo3 module.
- Abhishek: Software and hardware including soldering and assembling.

---
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProject--24-24?link=https%3A%2F%2Fwww.tinkerhub.org%2Fevents%2FQ2Q1TQKX6Q%2FUseless%2520Projects)



