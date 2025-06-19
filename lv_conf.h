#ifndef LV_CONF_H
#define LV_CONF_H

/* FUNKTIONIERENDE MINIMALE LVGL-Konfiguration für ESP32 */

#if 1 

/*====================
   COLOR SETTINGS
 *====================*/
#define LV_COLOR_DEPTH 16
#define LV_COLOR_16_SWAP 0

/*====================
   MEMORY SETTINGS - REDUZIERT
 *====================*/
#define LV_MEM_CUSTOM 0
#define LV_MEM_SIZE (24U * 1024U)    

/*====================
   HAL SETTINGS  
 *====================*/
#define LV_DISP_DEF_REFR_PERIOD 30

/*====================
   FEATURES - MINIMAL
 *====================*/
#define LV_USE_PERF_MONITOR 0
#define LV_USE_MEM_MONITOR 0
#define LV_USE_REFR_DEBUG 0
#define LV_USE_USER_DATA 1

/*====================
   DRAWING - MINIMAL
 *====================*/
#define LV_DRAW_COMPLEX 1
#define LV_SHADOW_CACHE_SIZE 0
#define LV_IMG_CACHE_DEF_SIZE 0
#define LV_GRADIENT_MAX_STOPS 2

/*====================
   LOGGING AUS
 *====================*/
#define LV_USE_LOG 0

/*====================
   LAYOUTS - NUR FLEX (Menu braucht es)
 *====================*/
#define LV_USE_FLEX 1                
#define LV_USE_GRID 0

/*====================
   WIDGETS - ABSOLUTES MINIMUM
 *====================*/
#define LV_USE_LABEL 1               
#define LV_USE_IMG 1                 
#define LV_USE_BTN 0                 
#define LV_USE_BTNMATRIX 0


#define LV_USE_MENU 0                

/* Alle anderen Widgets AUS */
#define LV_USE_ARC 0
#define LV_USE_ANIMIMG 0
#define LV_USE_BAR 0
#define LV_USE_CALENDAR 0
#define LV_USE_CANVAS 0
#define LV_USE_CHART 0
#define LV_USE_CHECKBOX 0
#define LV_USE_COLORWHEEL 0
#define LV_USE_DROPDOWN 0
#define LV_USE_KEYBOARD 0
#define LV_USE_LED 0
#define LV_USE_LINE 0
#define LV_USE_LIST 0
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
#define LV_USE_TEXTAREA 0
#define LV_USE_TILEVIEW 0
#define LV_USE_WIN 0

/*====================
   THEMES - MINIMAL
 *====================*/
#define LV_USE_THEME_DEFAULT 1
#define LV_USE_THEME_BASIC 0

/*====================
   FONTS - NUR 14pt
 *====================*/
#define LV_FONT_MONTSERRAT_14 1
#define LV_FONT_DEFAULT &lv_font_montserrat_14

/* Alle anderen Fonts AUS */
#define LV_FONT_MONTSERRAT_8  1
#define LV_FONT_MONTSERRAT_10 1
#define LV_FONT_MONTSERRAT_12 1
#define LV_FONT_MONTSERRAT_16 0
#define LV_FONT_MONTSERRAT_18 0
#define LV_FONT_MONTSERRAT_20 0

/*====================
   TEXT SETTINGS
 *====================*/
#define LV_TXT_ENC LV_TXT_ENC_UTF8

/*====================
   DEMOS/EXAMPLES - ALLE AUS
 *====================*/
#define LV_BUILD_EXAMPLES 0

/*====================
   COMPILER SETTINGS
 *====================*/
#define LV_COMPILER_VLA_SUPPORTED 1
#define LV_COMPILER_NON_CONST_INIT_SUPPORTED 1

#endif /* End of "Content enable" */

#endif /* LV_CONF_H */
