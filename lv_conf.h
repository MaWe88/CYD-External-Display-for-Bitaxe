#ifndef LV_CONF_H
#define LV_CONF_H

/* OPTIMIERTE LVGL-KONFIGURATION FÜR POKÉMON-TYPEN-TOOL AUF ESP32 CYD */

#if 1 

/*====================
   COLOR SETTINGS
 *====================*/
#define LV_COLOR_DEPTH 16
#define LV_COLOR_16_SWAP 0

/*====================
   MEMORY SETTINGS - OPTIMIERT FÜR CYD
 *====================*/
#define LV_MEM_CUSTOM 0
#define LV_MEM_SIZE (32U * 1024U)    // Etwas mehr RAM für UI-Elemente

/*====================
   HAL SETTINGS  
 *====================*/
#define LV_DISP_DEF_REFR_PERIOD 30
#define LV_INDEV_DEF_READ_PERIOD 30
#define LV_TICK_CUSTOM 0

/*====================
   FEATURES - OPTIMIERT
 *====================*/
#define LV_USE_PERF_MONITOR 0
#define LV_USE_MEM_MONITOR 0
#define LV_USE_REFR_DEBUG 0
#define LV_USE_USER_DATA 1
#define LV_USE_ASSERT_NULL 1
#define LV_USE_ASSERT_MALLOC 1
#define LV_USE_ASSERT_STYLE 0
#define LV_USE_ASSERT_MEM_INTEGRITY 0
#define LV_USE_ASSERT_OBJ 0

/*====================
   DRAWING - OPTIMIERT
 *====================*/
#define LV_DRAW_COMPLEX 1
#define LV_SHADOW_CACHE_SIZE 0
#define LV_IMG_CACHE_DEF_SIZE 1
#define LV_GRADIENT_MAX_STOPS 4
#define LV_GRAD_CACHE_DEF_SIZE 0
#define LV_DITHER_GRADIENT 0
#define LV_DISP_ROT_MAX_BUF (10*1024)

/*====================
   LOGGING AUS
 *====================*/
#define LV_USE_LOG 1

/*====================
   INPUT DEVICES
 *====================*/
#define LV_USE_INDEV 1

/*====================
   LAYOUTS - NUR FLEX
 *====================*/
#define LV_USE_FLEX 1                
#define LV_USE_GRID 0

/*====================
   WIDGETS - FÜR POKÉMON-TOOL OPTIMIERT
 *====================*/
#define LV_USE_OBJ 1
#define LV_USE_LABEL 1               
#define LV_USE_IMG 1                 
#define LV_USE_BTN 1                 // BUTTONS AKTIVIERT
#define LV_USE_BTNMATRIX 1
#define LV_USE_LIST 1                // FÜR LISTEN-DARSTELLUNG

/* ALLE ANDEREN WIDGETS AUS - SPEICHER SPAREN */
#define LV_USE_ARC 0
#define LV_USE_ANIMIMG 0
#define LV_USE_BAR 0
#define LV_USE_CALENDAR 0
#define LV_USE_CANVAS 0
#define LV_USE_CHART 0
#define LV_USE_CHECKBOX 0
#define LV_USE_COLORWHEEL 0
#define LV_USE_DROPDOWN 1
#define LV_USE_KEYBOARD 1
#define LV_USE_LED 0
#define LV_USE_LINE 0
#define LV_USE_MENU 0                
#define LV_USE_METER 0
#define LV_USE_MSGBOX 0
#define LV_USE_ROLLER 0
#define LV_USE_SLIDER 0
#define LV_USE_SPAN 0
#define LV_USE_SPINBOX 0
#define LV_USE_SPINNER 0
#define LV_USE_SWITCH 0
#define LV_USE_TABLE 0
#define LV_USE_TABVIEW 0
#define LV_USE_TEXTAREA 1
#define LV_USE_TILEVIEW 0
#define LV_USE_WIN 0
#define LV_TEXTAREA_DEF_PWD_SHOW_TIME     1500    /*ms*/

/*====================
   THEMES - MINIMAL
 *====================*/
#define LV_USE_THEME_DEFAULT 1
#define LV_USE_THEME_BASIC 0
#define LV_THEME_DEFAULT_DARK 0
#define LV_THEME_DEFAULT_GROW 1
#define LV_THEME_DEFAULT_TRANSITION_TIME 80

/*====================
   FONTS - OPTIMIERT FÜR POKÉMON-TOOL
 *====================*/
#define LV_FONT_MONTSERRAT_8  1
#define LV_FONT_MONTSERRAT_10 1      // FÜR KLEINE TEXTE
#define LV_FONT_MONTSERRAT_12 1      // FÜR LISTEN
#define LV_FONT_MONTSERRAT_14 1      // STANDARD
#define LV_FONT_MONTSERRAT_16 1      // FÜR ÜBERSCHRIFTEN
#define LV_FONT_MONTSERRAT_18 1      // FÜR TYP-NAMEN
#define LV_FONT_MONTSERRAT_20 1

#define LV_FONT_DEFAULT &lv_font_montserrat_14

/* ANDERE FONTS AUS */
#define LV_FONT_MONTSERRAT_22 1
#define LV_FONT_MONTSERRAT_24 1
#define LV_FONT_MONTSERRAT_26 0
#define LV_FONT_MONTSERRAT_28 1
#define LV_FONT_MONTSERRAT_30 0
#define LV_FONT_MONTSERRAT_32 0
#define LV_FONT_MONTSERRAT_34 1
#define LV_FONT_MONTSERRAT_36 0
#define LV_FONT_MONTSERRAT_38 0
#define LV_FONT_MONTSERRAT_40 0
#define LV_FONT_MONTSERRAT_42 0
#define LV_FONT_MONTSERRAT_44 0
#define LV_FONT_MONTSERRAT_46 0
#define LV_FONT_MONTSERRAT_48 0

/* SYMBOL FONTS AUS - SPEICHER SPAREN */
#define LV_USE_FONT_COMPRESSED 0
#define LV_USE_FONT_SUBPX 0
#define LV_FONT_SUBPX_BGR 0

/*====================
   TEXT SETTINGS - UTF-8 FÜR EMOJIS
 *====================*/
#define LV_TXT_ENC LV_TXT_ENC_UTF8
#define LV_TXT_BREAK_CHARS " ,.;:-_"
#define LV_TXT_LINE_BREAK_LONG_LEN 0
#define LV_TXT_LINE_BREAK_LONG_PRE_MIN_LEN 3
#define LV_TXT_LINE_BREAK_LONG_POST_MIN_LEN 3
#define LV_TXT_COLOR_CMD "#"
#define LV_USE_BIDI 0
#define LV_USE_ARABIC_PERSIAN_CHARS 0

/*====================
   WIDGET VERWENDUNG
 *====================*/
#define LV_USE_LARGE_COORD 0

/*====================
   OBJEKT EINSTELLUNGEN
 *====================*/
#define LV_USE_OBJ_ID 0
#define LV_USE_OBJ_PROPERTY 0

/*====================
   ANIMATIONS - MINIMAL FÜR SMOOTH SWIPES
 *====================*/
#define LV_USE_ANIM 1
#define LV_ANIM_CACHE_SIZE 4

/*====================
   GROUP HANDLING - FÜR NAVIGATION
 *====================*/
#define LV_USE_GROUP 1

/*====================
   GPU BESCHLEUNIGUNG - AUS
 *====================*/
#define LV_USE_GPU_STM32_DMA2D 0
#define LV_USE_GPU_SWM341_DMA2D 0
#define LV_USE_GPU_NXP_PXP 0
#define LV_USE_GPU_NXP_VG_LITE 0
#define LV_USE_GPU_SDL 0

/*====================
   FILE SYSTEM - AUS
 *====================*/
#define LV_USE_FS_STDIO 0
#define LV_USE_FS_POSIX 0
#define LV_USE_FS_WIN32 0
#define LV_USE_FS_FATFS 0

/*====================
   PNG/GIF DEKODER - AUS
 *====================*/
#define LV_USE_PNG 0
#define LV_USE_BMP 0
#define LV_USE_GIF 0
#define LV_USE_SJPG 0

/*====================
   FREETYPE - AUS
 *====================*/
#define LV_USE_FREETYPE 0

/*====================
   RLOTTIE - AUS
 *====================*/
#define LV_USE_RLOTTIE 0

/*====================
   API MAPPING
 *====================*/
#define LV_USE_API_EXTENSION_V6 0
#define LV_USE_API_EXTENSION_V7 0

/*====================
   DEMOS/EXAMPLES - ALLE AUS
 *====================*/
#define LV_BUILD_EXAMPLES 0
#define LV_USE_DEMO_WIDGETS 0
#define LV_USE_DEMO_KEYPAD_AND_ENCODER 0
#define LV_USE_DEMO_BENCHMARK 0
#define LV_USE_DEMO_STRESS 0
#define LV_USE_DEMO_MUSIC 0

/*====================
   COMPILER SETTINGS
 *====================*/
#define LV_COMPILER_VLA_SUPPORTED 1
#define LV_COMPILER_NON_CONST_INIT_SUPPORTED 1

/*====================
   HAL SETTINGS - ERWEITERT
 *====================*/
#define LV_USE_OS LV_OS_NONE
#define LV_NO_TASK_HANDLER 0
#define LV_TICK_CUSTOM_INCLUDE "Arduino.h"
#define LV_TICK_CUSTOM_SYS_TIME_EXPR (millis())

/*====================
   DEBUG EINSTELLUNGEN
 *====================*/
#define LV_USE_DEBUG 0

#endif /* End of "Content enable" */

#endif /* LV_CONF_H */
