# Arduino LED Lightshow 💡

A sophisticated Arduino lightshow with multiple LED animation sequences using 12 LEDs.

## 👀 Demo
![Lightshow Demo](https://github.com/user-attachments/assets/29db9ef7-15bb-4543-99be-e28a8a5a5f7b)

## 🔌 Circuit Diagram 
![Circuit Diagram](https://github.com/user-attachments/assets/fc87376d-715d-4e7e-b584-ed4378db6718)

## 💻 Code
The main Arduino code is available here: **[lightshow.ino](lightshow.ino)**

## ✨ Features
- 7 different animation patterns
- Serial command control ("start" trigger)
- PWM breathing effects
- Color-based sequencing
- Row and parity patterns

## 🔧 Hardware Requirements
- Arduino Uno/Nano
- 12 LEDs (4 red, 4 yellow, 4 green)
- Resistors (220Ω)
- Breadboard and jumper wires

## 🚀 Quick Start
1. Upload `lightshow.ino` to your Arduino
2. Open Serial Monitor at 9600 baud
3. Type "start" to begin the lightshow

## 🎮 Animation Sequences
1. **Sequential Scan** - LEDs light up in order then in reverse
2. **Sequential Scan from the middle** - LEDs light up starting from the middle in order then in reverse
3. **Color Groups** - All reds, then yellows, then greens
4. **Row Patterns** - Lighting by rows
5. **Pair Groups** - LEDs light up in pairs
6. **Breathing Effect** - Fade in/out using PWM

// Open for any opinion or suggestion!! :D
