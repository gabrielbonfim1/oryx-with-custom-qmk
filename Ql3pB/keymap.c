#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
};

uint16_t returnCommand(){
  os_variant_t OS; 
  OS = detected_host_os();
  switch (OS){
    case OS_MACOS:
      return KC_LCMD;
    case OS_WINDOWS:
      return KC_LCTL;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           MO(1),          
    KC_CAPS,        KC_A,           KC_S,           KC_D,           LT(2,KC_F),     KC_G,           KC_LEFT_CTRL,                                                                   KC_TILD,        KC_H,           LT(2,KC_J),     KC_K,           KC_L,           KC_COLN,        KC_QUOTE,       
    KC_LEFT_SHIFT,  MT(MOD_LCTL, KC_Z),KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,                                                                                                        KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       returnCommand(),    MO(3),                          KC_ESCAPE,      KC_ENTER,       KC_BSPC
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    LGUI(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, LALT(KC_1),     LALT(KC_2),     LALT(KC_3),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ASTR,        KC_TRANSPARENT, KC_MINUS,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_CIRC,        KC_DLR,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PLUS,        KC_LPRN,        KC_RPRN,        KC_MINUS,       KC_UNDS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_SCLN,        KC_PIPE,        KC_AMPR,        KC_GRAVE,       KC_PERC,        KC_TRANSPARENT,                                                                 KC_COLN,        KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_DQUO,        KC_QUOTE,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TILD,                                        KC_LCBR,        KC_RCBR,        KC_MINUS,       KC_RABK,        KC_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, LCTL(KC_F13),   LCTL(KC_LBRC),  LCTL(KC_BSLS),  LCTL(KC_SLASH), LCTL(KC_RBRC),  
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, ST_MACRO_0,     KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PAGE_UP,     
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_PGDN,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F13,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_HOME,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_C),     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_END,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 LGUI(KC_SPACE), LALT(KC_SPACE), KC_TRANSPARENT
  ),
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2,KC_F):
            return TAPPING_TERM -20;
        case KC_LEFT_GUI:
            return TAPPING_TERM + 100;
        case LT(2,KC_J):
            return TAPPING_TERM -20;
        default:
            return TAPPING_TERM;
    }
}

// Custom QMK Functions By @gabrielbonfim1

// Function to set the first row of moonlander to red
void color_first_row_to_red(void){
    int first_row[] = {0,5,10,15,20,25,36,41,46,51,56,61}; // Leds for the first row of moonlander, ommited 29 e 65 because I don't use those keys.
    for (int i = 0; i < 12; i++){
            rgb_matrix_set_color(first_row[i], 0xFF, 0x00, 0x00);
    }
}

bool caps_lock_on = false; // Variable to track if caps lock is turned on

// Update the caps lock status
bool led_update_user(led_t led_state){
	caps_lock_on = led_state.caps_lock;
	// if (caps_lock && IS_LAYER_ON(0)){
	// 	color_first_row_to_red();
	// }
	return true;
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204}, {0,0,0}, {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204}, {0,0,0}, {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204}, {0,0,0}, {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204}, {0,0,0}, {167,218,204}, {167,218,204}, {41,255,255}, {167,218,204}, {0,0,0}, {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204}, {0,0,0}, {0,0,0}, {74,255,206}, {167,218,204}, {167,218,204}, {0,245,245}, {167,218,204}, {167,218,204}, {188,255,255}, {167,218,204}, {167,218,204}, {0,0,0}, {167,218,204}, {167,218,204}, {167,218,204}, {0,0,0}, {0,0,0}, {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204}, {0,0,0}, {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204}, {0,0,0}, {167,218,204}, {167,218,204}, {41,255,255}, {167,218,204}, {0,0,0}, {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204}, {0,0,0}, {0,0,0}, {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204}, {167,218,204} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }

  // Custom Part to Change RGB color on caps_lock
	if (caps_lock_on && biton32(layer_state) == 0){
		color_first_row_to_red();
	}
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LEFT) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}



