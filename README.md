# Bitaxe Monitor Project - Build Guide

This guide provides simple instructions to build and deploy the Bitaxe Monitor project, a custom UI for monitoring Bitcoin mining hardware (Bitaxe) on a CYD 2432S028R board using an ESP32 microcontroller.

## Prerequisites

- **Hardware**:
  - CYD 2432S028R board (ESP32-based with a 320x240 TFT display)
  - USB cable
  - Bitaxe mining hardware (connected to your local network)
- **Software**:
  - Arduino IDE
- **Network**:
  - Wi-Fi credentials
  - IP address of your Bitaxe device on your local network

## Step 1: Set Up the Arduino IDE

1. **Install ESP32 Board Support**:
   - Open the Arduino IDE.
   - Go to `Tools` > `Board` > `Boards Manager`, search for `ESP32`, and install the package by Espressif Systems.
2. **Select Board and Configure Settings**:
   - Under `Tools` > `Board` > `ESP32`, select `ESP32 Dev Module`.
   - Select the correct COM port
   - Under `Tools`, configure:
     - `PSRAM` to `Enabled`
     - `Partition Scheme` to `Minimal SPIFFS (1.9MB APP with OTA/190KB SPIFFS)`

## Step 2: Install Required Libraries

1. Go to `Sketch` > `Include Library` > `Manage Libraries...`.
2. Search for and install the following libraries:
   - `TFT_eSPI` by Bodmer
   - `lvgl` by kisvegabor (version 8.3.11)
   - `WiFi` (usually included)
   - `HTTPClient` (usually included)
   - `ArduinoJson` by Benoit Blanchon

## Step 3: Download and Open the Project

1. **Download the Project Files**:
   - download the `Bitaxe_Monitor.ino`, `background.c`, `background.h`, `User_Setup.h`, and `lv_conf.h` files.
2. **Place Configuration Files in Correct Folders**:
   - Place `User_Setup.h` in the `TFT_eSPI` library folder (`Documents\Arduino\libraries\TFT_eSPI`).
   - Place `lv_conf.h` in the libraries folder (`Documents\Arduino\libraries\`).
   - Keep `background.c` and `background.h` in the same folder as the `.ino` file. (e.g., `Documents\Arduino\Bitaxe_Monitor`)
3. **Open the Sketch**:
   - In the Arduino IDE, go to `File` > `Open` and select the `Bitaxe_Monitor.ino` file.

## Step 4: Configure the Sketch

Before compiling, update the network settings to match your environment.

1. In the Arduino IDE, locate the following lines near the top of the sketch code:

    ```
    ssid = "YourWifiName";
    pwd = "YourWifiPW";
    bitaxe_url = "http://YourBitaxeIp/api/system/info";
    ```

2. Update these values:
    - `ssid`: Your Wi-Fi network name (replace `YourWifiName` with your actual Wi-Fi SSID).
    - `pwd`: Your Wi-Fi password (replace `YourWifiPW` with your actual Wi-Fi password).
    - `bitaxe_url`: The IP address of your Bitaxe device on your local network (replace `YourBitaxeIp` with the actual IP address of your Bitaxe, e.g., `http://192.168.1.100/api/system/info`).

## Step 5: Compile and Upload the Sketch

1. Connect your CYD 2432S028R board via USB.
2. In the Arduino IDE, click `Sketch` > `Verify/Compile` to check for errors.
3. If successful, click `Sketch` > `Upload` to upload the code to your board. If necessary, hold the `BOOT` button then press `RESET` and then release the `BOOT` Button on the board during upload.

## Troubleshooting

- **Compilation Errors**:
  - Are all required libraries installed as described above?
  - Is `User_Setup.h` in the `TFT_eSPI` folder, `lv_conf.h` in the libraries folder, and `background.c/.h` in the sketch folder?
- **Wi-Fi Connection Issues**:
  - Are the SSID and password correct?
  - Is the board within range of your Wi-Fi network?
- **No Data from Bitaxe**:
  - Is the IP address in the sketch correct?
  - Is the Bitaxe device online and accessible on your network?
- **No COM Port Visible**:
  - Check the Device Manager. If needed, install the CP210x driver.
- **Performance or Memory Issues**:
  - Set PSRAM to `Enabled` and Partition Scheme to `Minimal SPIFFS`.
- **Display Issues**:
  - if your Display looks all scrambled up, search with Crtl + F for rotation and replace the 2 with 1 or 3. Some CYD use a different screen rotation.
  - if your Display is inverted (blue), open the User_Setup.h with editor and search for #define TFT_RGB_ORDER TFT_RGB and change it to TFT_BGR.
- **Issues**:
  - BTC Price and Diff starting to update after one minute after a restart (fallback used before that) (fixed with 1.1)
  - Blk/Yr uses a fallback Networkhashrate (working on API) (added with 1.1)

## License

This project is open for personal and educational use. If you redistribute or modify it, please credit the original author.

