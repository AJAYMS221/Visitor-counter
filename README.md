# Visitor-counter
👥 Visitor Counter and Room Light Automation System

Project Overview:
This project demonstrates an automatic room light control system using a visitor counter.
The system detects the number of people entering and exiting a room using ultrasonic sensors and Arduino, and automatically turns the room light ON or OFF based on occupancy, utilizing a relay module.

🛠️ Hardware Components
Arduino Uno
Ultrasonic Sensors (for entry/exit detection)
Relay Module (to control the light)
LED Light (simulating a real room light)
Power Supply
Jumper Wires and Breadboard

⚙️ How It Works
Entry Detection:
When a person is detected entering the room, the counter increments, and the light turns ON if at least one person is present.
Exit Detection:
When a person exits, the counter decrements. When the counter reaches zero (room is empty), the light automatically turns OFF.
Automation:
This ensures energy saving and convenience by automatically managing the light without any manual switch.

🔮 Future Enhancements
Add an LCD Display for live counter updates.
Use IR sensors for better precision.
Integrate a mobile app for remote monitoring.
