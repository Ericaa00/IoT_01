# **ESP32-C3 SOS Signaling Device**
WiFi Provisioning + OTA Update

---

## **1. Overview**

This project implements an ESP32-C3 based embedded system that:

- Generates Morse code **SOS (... --- ...)** using an LED
- Supports WiFi provisioning via captive portal (WiFiManager)
- Supports firmware update via **Over-The-Air (OTA)**
- Provides serial debug output

Target platform: **ESP32-C3 (4MB Flash)**
Framework: **Arduino (PlatformIO)**

---

## **2. System Features**

### **2.1 SOS LED Signaling**

- Morse pattern: **... --- ...**
- Dot duration: **200 ms**
- Dash duration: **600 ms**
- Continuous looping pattern
- Non-blocking execution to prevent watchdog reset

---

### **2.2 WiFi Provisioning**

- Automatic WiFi connection using stored credentials
- If no credentials exist:
  - Device creates Access Point
  - Default SSID: **ESP32C3-Setup**
  - Captive portal for network configuration
- Credentials stored in **NVS (Non-Volatile Storage)**

---

### **2.3 OTA Firmware Update**

- OTA supported over local WiFi
- Default hostname: **ESP32C3-SOS**
- OTA progress displayed via Serial Monitor
- Automatic reboot after successful update

---

### **2.4 Serial Debug Output**

- Baud rate: **115200**
- Displays:
  - Boot status
  - WiFi connection status
  - IP address
  - OTA progress
  - SOS cycle notification

---

## **3. Hardware Requirements**

- ESP32-C3 Dev Board (**4MB Flash recommended**)
- USB 5V power supply
- Onboard LED or external LED

### **Recommended GPIO for LED**

Common working pins:
- **GPIO 8** (commonly onboard LED)
- **GPIO 4 / GPIO 5** (safe for external LED)

---

## **4. Software Requirements**

- PlatformIO
- Espressif32 platform
- Arduino framework
- Required Libraries:
  - **WiFiManager**
  - **ArduinoOTA**

---

## **5. Functional Requirements**

- **FR-01**: System shall initialize Serial at 115200 baud
- **FR-02**: System shall initialize LED GPIO as OUTPUT
- **FR-03**: System shall attempt WiFi auto-connect on boot
- **FR-04**: System shall start AP mode if WiFi is not configured
- **FR-05**: System shall allow OTA update when connected
- **FR-06**: System shall continuously display SOS pattern
- **FR-07**: System shall remain responsive during OTA handling

---

## **6. Non-Functional Requirements**

- **NFR-01**: System shall not trigger watchdog reset
- **NFR-02**: Firmware shall fit within OTA partition
- **NFR-03**: Flash mode must be **DIO**
- **NFR-04**: Flash size must be **4MB**

---

## **7. System Operational States**

1. **Boot**
2. **WiFi Check**
3. **AP Provisioning Mode** (if WiFi not configured)
4. **Normal Operation (SOS + OTA handling)**
5. **OTA Update**
6. **Reboot**

---

## **8. Recommended PlatformIO Flash Configuration**

Add to `platformio.ini`:

board_build.flash_mode = dio
board_build.flash_freq = 80m
board_build.flash_size = 4MB
board_build.partitions = default.csv

---

## **9. Future Enhancements**

- Web-based status dashboard
- Configurable SOS timing
- MQTT integration
- Deep sleep mode
- Secure OTA (TLS support)

---

## **10. License**
