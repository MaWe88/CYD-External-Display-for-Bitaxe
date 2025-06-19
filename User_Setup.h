#ifndef USER_SETUP_H
#define USER_SETUP_H

#define USER_SETUP_INFO "CYD-2432S028R LVGL optimized"

// ── Driver für ILI9341 ──────────────────────────────────
#define ILI9341_DRIVER

// ── Display-Größe (native Portrait-Orientierung) ────────
#define TFT_WIDTH  320
#define TFT_HEIGHT 240

// ── CYD Hardware-Pins ───────────────────────────────────
#define TFT_MISO 12
#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  -1  
#define TFT_BL   21
#define TFT_BACKLIGHT_ON HIGH
#define TOUCH_CS 33

// ── SPI-Geschwindigkeiten ───────────────────────────────
#define SPI_FREQUENCY       27000000  
#define SPI_READ_FREQUENCY  20000000  
#define SPI_TOUCH_FREQUENCY 2500000   

// ── Wichtige LVGL-Optimierungen ─────────────────────────
#define CGRAM_OFFSET                  
#define SUPPORT_TRANSACTIONS          
#define TFT_MISO_READ                 
#define TFT_RGB_ORDER TFT_RGB

// ── Font-Unterstützung ──────────────────────────────────
#define LOAD_GLCD    // Standard-Font
#define LOAD_FONT2   // Kleine Fonts
#define LOAD_FONT4   // Mittlere Fonts
#define LOAD_FONT6   // Große Fonts
#define LOAD_FONT7   // 7-Segment-Style
#define LOAD_FONT8   // Große Zahlen
#define LOAD_GFXFF   // FreeFonts
#define SMOOTH_FONT  // Anti-Aliasing

// ── LVGL-spezifische Einstellungen ──────────────────────
#define TFT_DISPOFF 0x28
#define TFT_SLPIN   0x10


#endif
