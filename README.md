# Bitaxe Monitor Project - Build Guide

Welcome to the Bitaxe Monitor Project! This custom UI allows you to monitor your Bitcoin mining hardware (Bitaxe) on a CYD 2432S028R board using an ESP32 microcontroller. Follow this guide to set up and deploy the project with ease.




## What's New in Version 3.3 (latest)
- **4th Layout**: a layout perfect for your Desk. Clock with Hashrate and current Weather. Everything fetched automaticly via API

- **New Notification**: If you unlock a Achievement, you will now get a notification via NTFY
  
- **Status Led**: the status LED now behaves like a Price Up / Down indicator. Up -> green; Down -> red
  
  ---
  

## Features

-**WiFiManager for Easy Configuration**: Configure WiFi credentials, Bitaxe URL and so on via a web portal without modifying the code.

-**Multi Device Support**: Monitors up to 5 Bitaxe devices, switching display every 30 seconds.

-**Price Data for Mineable Coins**: Supports BTC, BCH, DGB, XEC, NMC, PPC, and LCC.

-**Combined Hashrate Mode**: Displays total mining power from all devices, including combined block chance per year.

-**Swipe Functionality and Multiple Layouts**: Three layouts with gesture navigation (swipe right to advance, left to go back).

-**Achievements System**: Unlock 16 achievements with popups; access page by swiping right from Layout 3 (swipe left to return).

-**Maintanence Reminder**: reminds you every 30 days to clean the Bitaxe Fans.

-**Reset Function**: Long-press (10 seconds) on Layouts 1, 2, or 3 to reset all settings and return to configuration portal.

-**Notification System**: Integrated ntfy.sh push alerts for critical mining events such as device offline, low voltage, or high temperature.

---

#### Resetting Achievements
If you want to start fresh:
1. download the `Reset_Achievements.bin` and install it via https://web.esphome.io/
   
or

1. Download the sketch `Reset_Achievements.ino` and place it in your Arduino sketches folder.
2. Open the sketch in the Arduino IDE (it will create a folder for it).
3. Select `ESP32 DEV Module` and the correct `COM` port, then upload the sketch.
4. After uploading, re-upload the `Bitaxe_Monitor` sketch.
5. Your achievements will now be reset.

---

## Getting Started: Choose Your Setup Option

You can set up the Bitaxe Monitor in two ways:
- **Option 1**: Flash a precompiled firmware file (recommended for beginners, no coding required).
- **Option 2**: Compile and upload the code manually using the Arduino IDE (for advanced users or customization).

### Prerequisites
Before starting, ensure you have:
- **Hardware**:
  - CYD 2432S028R board (ESP32-based with a 320x240 TFT display)
  - USB cable
  - Bitaxe mining hardware (connected to your local network)
- **Software (for Option 1 - Precompiled Firmware)**:
  - A modern browser like Chrome, Edge, or Opera (for web-based flashing tools)
- **Software (for Option 2 - Manual Compilation)**:
  - Arduino IDE
- **Network**:
  - Wi-Fi credentials
  - IP address of your Bitaxe device on your local network
- **Notifications**:
  - Smartphone with installed NTFY App from Google Playstore or App Store

---

## Option 1: Flash Precompiled Firmware (Recommended for Beginners)

This is the easiest way to get started. Flash the firmware directly to your ESP32 using a web-based tool without installing any software.
### Step 0: ONLY if your upgrading from an older Version
- download and install (see Step 2) the `reset_achievements.bin` file before upgrading, to clear your device NVS. Upgrading without could cause some bugs.
### Step 1: Download the Firmware
- Download the precompiled firmware file `Bitaxe_Monitor.bin` 

### Step 2: Flash the Firmware Using ESP Web Tools
1. Connect your CYD 2432S028R board to your computer via USB.
2. Open Chrome, Edge, or Opera and visit the website: https://web.esphome.io/
3. Click on "Connect" and select the COM port of your ESP32. (Check the Device Manager. If needed, install the CP210x driver.)
4. Click "Install".
5. Click "Choose File" and upload `Bitaxe_Monitor.bin`. Now click Install.
6. **Optional if your device doesnt install automaticly** On the backside of your CYD are 2 buttons on the left side of the ESP32 Chip (BOOT & RST). Hold `Boot` (after pressing Install), click `RST`, and release `Boot`.
7. Wait until the flashing is complete.

### Step 3: Configure Settings via WiFiManager
1. After flashing, the ESP32 will restart and create a Wi-Fi Access Point named **"BitaxeMonitorAP"** with the password **"password"**.
2. Connect to this network with your phone or computer.
3. Open a browser and navigate to `192.168.4.1` to access the WiFiManager portal.
4. Enter the following settings:
   - **WiFi SSID**: Your Wi-Fi network name.
   - **WiFi Password**: Your Wi-Fi password.
   - **Multi Device**: Choose how many Bitaxe you want to cover. (upto 5)
   - **Bitaxe URL**: The IP address of your Bitaxe device (e.g., `192.168.1.100`).
   - **Display Rotation (0-3)**: Standard is Rotation 2. Only change if your display looks scrambled or you want to place your display differently (e.g., 2 for USB right, 0 for USB left).
   - **Powersaving**: Choose if you want your Display to turn off after some time (never is standard)
   - **Status Led**: Choose if you want to turn it off or leave it on. If on -> Coin Price up green / Coin Price down red
   - **Price Data and Blk/Yr***: Choose from BTC, BCH, DGB, XEC, NMC, PPC or LCC
   - **Combined Hashrate**: Option for displaying your total Mining Power
   - **Notifications**: Option to Turn on Notifications. Download the NTFY App from Google Play Store or App Store. Create a Topic (Choose a non guessable name) in NTFY and enter the Topic to the provided Field in Wifimanager
5. Click "Save". The ESP32 will restart and connect to your Wi-Fi network using the provided settings.

### Step 4: Reset Settings if Needed
- If you need to change settings (e.g., WiFi, Bitaxe URL, or rotation), **long-press (10 seconds)** anywhere on Layouts 1, 2, or 3 of the display. The ESP32 will restart and reopen the "BitaxeMonitorAP" for reconfiguration.

---

## Option 2: Compile and Upload Using Arduino IDE (Advanced Users)

For those who prefer to compile the code themselves or make custom modifications, follow these steps.

### Step 1: Set Up the Arduino IDE
1. **Install ESP32 Board Support**:
   - Open the Arduino IDE.
   - Go to `Tools` > `Board` > `Boards Manager`, search for `ESP32`, and install the package by Espressif Systems.
2. **Select Board and Configure Settings**:
   - Under `Tools` > `Board` > `ESP32`, select `ESP32 Dev Module`.
   - Select the correct COM port.
   - Under `Tools`, configure:
     - `PSRAM` to `disabled`
     - `Partition Scheme` to `Huge APP (3MB No OTA / 1MB SPIFFS)`

### Step 2: Install Required Libraries
1. Go to `Sketch` > `Include Library` > `Manage Libraries...`.
2. Search for and install the following libraries:
   - `TFT_eSPI` by Bodmer
   - `lvgl` by kisvegabor (version 8.3.11)
   - `WiFi` (usually included)
   - `HTTPClient` (usually included)
   - `ArduinoJson` by Benoit Blanchon
   - `XPT2046_Touchscreen` by Paul Stoffregen
   - `Preferences` (usually included)
   - `SPI` (usually included)
   - `WiFiManager` by tzapu

### Step 3: Download and Open the Project
1. **Download the Project Files**:
   - Download the `Bitaxe_Monitor.ino`, `background.c`, `background.h`, `User_Setup.h`, `lv_conf.h`, `background2.c`, `background2.h`, `background3.c`, `background3.h`, `backgroundachieve.c`, `backgroundachieve.h`, `achievementpopup.c`, and `achievementpopup.h` files. (`reset_achievements` is optional)
2. **Place Configuration Files in Correct Folders**:
   - Place `User_Setup.h` in the `TFT_eSPI` library folder (`Documents\Arduino\libraries\TFT_eSPI`).
   - Place `lv_conf.h` in the libraries folder (`Documents\Arduino\libraries\`).
   - Keep all other files in the same folder as the `.ino` file (e.g., `Documents\Arduino\Bitaxe_Monitor`).
3. **Open the Sketch**:
   - In the Arduino IDE, go to `File` > `Open` and select the `Bitaxe_Monitor.ino` file.

### Step 4: Compile and Upload the Sketch
1. Connect your CYD 2432S028R board via USB.
2. In the Arduino IDE, click `Sketch` > `Verify/Compile` to check for errors.
3. If successful, click `Sketch` > `Upload` to upload the code to your board. If necessary, hold the `BOOT` button, then press `RESET`, and release the `BOOT` button on the board during upload.

### Step 5: Configure Settings via WiFiManager
Follow the same steps as in Option 1, Step 3 to configure WiFi, Bitaxe URL, and display rotation via the WiFiManager portal.

---

## Troubleshooting

| **Issue**                       | **Solution**                                                                                           |
|---------------------------------|-------------------------------------------------------------------------------------------------------|
| **Compilation Errors (Option 2)** | Ensure all required libraries are installed. Check if `User_Setup.h` is in the `TFT_eSPI` folder, `lv_conf.h` in the libraries folder, and all `backgroundXXX.c/.h` in the sketch folder. |
| **Wi-Fi Connection Issues**     | Verify that the SSID and password are entered correctly in the WiFiManager portal. Ensure the board is within range of your Wi-Fi network. |
| **No Data from Bitaxe**         | Confirm that the Bitaxe URL (IP address) in the WiFiManager portal is correct and the device is online and accessible on your network. |
| **No COM Port Visible**         | Check the Device Manager. If needed, install the CP210x driver.                                       |
| **Performance/Memory Issues (Option 2)** | Set PSRAM to `Enabled` and Partition Scheme to `HUGE APP`.                                    |
| **Display Issues**              | - **Rotated Display**: Adjust the „Display Rotation“ value (0-3) in the WiFiManager portal (`192.168.4.1`).<br>- **Incorrect Colors**: Refer to the „Advanced Configuration“ section below for instructions on adjusting color settings.<br>- **Access Portal**: Long-press (10 seconds) on Layouts 1, 2, or 3 to reset settings and reopen the portal. |
| **crashes**                     | - make sure you install the `reset_achievements.bin` first before installing `Bitaxe_Monitor.bin` if your upgrading from 2.1, 2.0 and so on. 
| **Notification** not working    | Make sure you entered the correct topic you created in NTFY App in Wifimanager
| **Weather**                     | If the API cant fetch your location via your IP ( while using a VPN for example) weather wont work. 
---

## Fixing Color Issues

If you experience incorrect colors on your display (e.g., blue instead of red/orange), this is often due to hardware differences in the display driver of the CYD 2432S028R board.

Use the file `bitaxe_monitor_inverted.bin` and your screen colors should be correct. No need to fix it yourself anymore :D

---
**Bugs**
- freezes due to memory leak or core hickups; added more checks to trigger a restart in 3.2.1 -> still undergoing testing
- some weather conditions may be missing or too long for the display 

---

***Note on Block Chance Calculations (`Blk/Yr`)**:  
The `Blk/Yr` value represents an estimated probability of mining a block per year based on your device's hashrate compared to the network's total hashrate. For Bitcoin (BTC), this calculation uses real-time network data and is accurate. For other coins (BCH, XEC, DGB, NMC, PPC, LCC), the values are approximations based on Difficulty and Networkhashrate by July 16th. These approximations may not reflect current network conditions and should be considered rough estimates. I am working on improving accuracy for non-BTC coins in future updates.

---
## License

This project is open for personal and educational use. If you redistribute or modify it, please credit the original author.
