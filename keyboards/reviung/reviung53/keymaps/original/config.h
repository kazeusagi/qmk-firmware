#define RGBLIGHT_LAYERS // 機能の有効化
// #define RGBLED_NUM 10 // LEDの個数
#define RGBLIGHT_MAX_LAYERS 8 // (最大32)

#define LED_LAYOUT( \
  LED1, LED2, LED3, LED4, LED5, \
  LED6, LED7, LED8, LED9, LED10 ){ \
  \
  LED5, LED4, LED3, LED2, LED1, \
  LED6, LED7, LED8, LED9, LED10 }

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
  0, 1, 2, 3, 4, \
  5, 6, 7, 8, 9 )

// TTの回数
#define TAPPING_TOGGLE 1
