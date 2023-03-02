/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
 // qmk compile -kb xiudi/xd75 -km snjo

// LAYOUT: http://www.keyboard-layout-editor.com/#/gists/64c416567e435e7d7e065be39ee2414f

#include QMK_KEYBOARD_H
#include "txtmacros.c"

// MACRO FILE ----------------------------------------------------------------------------
// add a txtmacros.c file to this folder and create entries:
// #define TXTMACRO1 "my text 1"
// #define TXTMACRO2 "my text 2"
// #define TXTMACRO3 "my text 3"
// Norwegian backslash: =
// Norwegian underscore: ?


// DECLARATIONS --------------------------------------------------------------------------

enum layer_names {
    _CMK,
    _QWE,
    _GAM,
	_NUM,
	_COD,
	_SYM,	
};

// TAP DANCE ----------------------------------------------------------------
enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
};

#define D_OE_AE TD(DANCE_0)
  #define D0_TAP KC_SCLN
  #define D0_HOLD KC_QUOT

#define D_AP_QT TD(DANCE_1)
  #define D1_TAP KC_BSLS
  #define D1_HOLD S(KC_2)

#define D_PL_EQ TD(DANCE_2)
  #define D2_TAP KC_PPLS
  #define D2_HOLD S(KC_0)

#define D_CM_CL TD(DANCE_3)
  #define D3_TAP KC_PDOT
//#define D3_TAP KC_COMM
  #define D3_DBTAP S(KC_DOT)
  #define D3_HOLD KC_DOT

#define D_AA_AE TD(DANCE_4)
  #define D4_TAP KC_LBRC
  #define D4_HOLD KC_QUOT

#define D_BS_CBS TD(DANCE_5)
  #define D5_TAP KC_BSPC
  #define D5_HOLD C(KC_BSPC)

// MACROS ----------------------------------------------------------------
// Macro declarations
enum custom_keycodes {
    TXT1 = SAFE_RANGE,
	TXT2,
	TXT3,
	EMDASH,
	CAPSW_ON, // 0x5da8 on
	CAPSW_OFF, // 0x5da9 off
	CAPSW_TG, // 0x5daa toggle
	OE_AE, 		// TAP Ø HOLD Æ
	COM_COL, 	// TAP , HOLD :
	APO_QUOT,	// TAP ' HOLD "
	PLS_EQ,		// TAP + HOLD =
	TESTKEY,
};

// LAYOUTS ------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* COLEMAK
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | CUT    | COPY   | PASTE  | F3     | F5     | +      | -      | *      | /      | QWERTY | GAME   | F11    | F12    | PRTSCR |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | TAB    | Q      | W      | F      | P      | B      | 7      | 8      | 9      | J      | L      | U      | Y      | Å      | Ø      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | BSPC   | A      | R      | S      | T      | G      | 4      | 5      | 6      | M      | N      | E      | I      | O      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SHFT \ | Z      | X      | C      | D      | V      | 1      | 2      | 3      | K      | H      | ,      | .      | UP     | -      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | CTRL   | WIN    | ALT    | DEL    | (SYM)  | SPACE  | 0      | ,      | ?      | SPACE  | SH ENT | (CODE) | LEFT   | DOWN   | RIGHT  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_CMK] = LAYOUT_ortho_5x15( /* COLEMAK */
        KC_ESC,         C(KC_X), C(KC_C),    C(KC_V),  KC_F3,          KC_F5,   D_PL_EQ,     KC_PMNS,  KC_PAST,       KC_PSLS,      KC_QUOT,        KC_F4,           KC_F11,  KC_F12,         KC_PSCR, //LT(0,PLS_EQ)
        KC_TAB,         KC_Q,    KC_W,       KC_F,     KC_P,           KC_B,    KC_7,        KC_8,     KC_9,          KC_J,         KC_L,           KC_U,            KC_Y,    D_AA_AE,        D_OE_AE,	//LT(0,OE_AE), //KC_SCLN,
        KC_BSPC,        KC_A,    KC_R,       KC_S,     KC_T,           KC_G,    KC_4,        KC_5,     KC_6,          KC_M,         KC_N,           KC_E,            KC_I,    KC_O,           D_AP_QT, //LT(0,APO_QUOT),
        LSFT_T(KC_EQL), KC_Z,    KC_X,       KC_C,     KC_D,           KC_V,    KC_1,        KC_2,     KC_3,          KC_K,         KC_H,           KC_COMM,         KC_DOT,  KC_UP,          KC_SLSH, //LT(0,COM_COL)
        KC_LCTL,        KC_LGUI, KC_LALT,    KC_DEL,   LT(_SYM,KC_SPC),KC_SPC,  KC_0,        D_CM_CL,  LSFT(KC_MINUS),D_BS_CBS,     LSFT_T(KC_ENT), MO(_COD),        KC_LEFT, KC_DOWN,        KC_RIGHT
    ),

    [_QWE] = LAYOUT_ortho_5x15( /* QWERTY */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    D_AA_AE,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    D_OE_AE, D_AP_QT,  //KC_QUOT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_N,    KC_M,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

	/* GAME
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        |   1    |   2    |   3    |   4    |   5    |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Shift  |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |  Space |        |        |  num.  |        | (SYM)  | ENTER  | (CODE) |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
	[_GAM] = LAYOUT_ortho_5x15( /* Code */
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_SCLN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_SPC,  _______, _______, KC_PDOT, _______, MO(_SYM),KC_ENT,  _______, _______, _______, _______
    ),
	
	// numlock layer for Blender modelling
    [_NUM] = LAYOUT_ortho_5x15(
		_______, _______,  _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, _______, _______, _______, _______,
        _______, _______,  _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, _______,
        _______, _______,  _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______,  _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______,
        _______, _______,  _______, _______, _______, _______, KC_P0,   KC_PDOT, _______, _______, _______, _______, _______, _______, _______
    ),
	
	/* CODE
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | Reset  |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | +      | -      | !      | =      | "      |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | {      | }      | (      | )      | ;      |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | CapsL  | <      | >      | [      | ]      | /      |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Cmb On | Cmb off|        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
	[_COD] = LAYOUT_ortho_5x15( /* Code */
        QK_BOOT, _______,    _______,      _______,    _______,    _______,        KC_NUM,  KC_SCRL, KC_PAUS, _______, TG(_QWE),  TG(_GAM),  TG(_NUM),   _______, _______,
        _______, KC_MINUS,   KC_SLASH,     LSFT(KC_1), LSFT(KC_0), LSFT(KC_2),     KC_F7,   KC_F8,   KC_F9,   _______, LGUI(KC_L),_______,   _______,    _______, _______,
        _______, RALT(KC_7), RALT(KC_0),   LSFT(KC_8), LSFT(KC_9), LSFT(KC_COMMA), KC_F4,   KC_F5,   KC_F6,   _______, _______,   LGUI(KC_E),_______,    _______, _______,
        KC_CAPS, KC_NUBS,    LSFT(KC_NUBS),RALT(KC_8), RALT(KC_9), KC_PSLS,        KC_F1,   KC_F2,   KC_F3,   _______, _______,   _______,   _______,    KC_VOLU, KC_CAPS,
        CM_ON,   CM_OFF,     _______,      _______,    _______,    _______,        KC_F10,  KC_F11,  KC_F12,  _______, _______,   _______,   _______,    KC_VOLD, KC_MPLY
    ),

	
	/* SYMBOLS
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        | TXT1   | TXT2   | TXT3   |        |        | =      |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Insert | "      | #      | ?      | |      | \      | P7     | P8     | P9     |        | £      | _      | —      | Æ      | Æ      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | @      | :      | /      | ~      | &      | P4     | P5     | P6     |        | ^      | =      | !      | ¨      | "      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | ¤      | *      | %      | $      | ´      | P1     | P2     | P3     |        | #      | <      | >      | PGUP   | ?      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | CAPSWRD| ComboTG|        |        |        |        | P0     | :      | !      |        |        |        | HOME   | PGDN   | END    |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
	[_SYM] = LAYOUT_ortho_5x15( /* SYMBOLS */
	
		// alternatives ARS: cut copy paste : @:/
		// RALT(KC_2), S(KC_DOT), KC_PSLS,
		// C(KC_X), C(KC_C),    C(KC_V)
        _______,  TXT1,       TXT2,      TXT3,        _______,       _______,        S(KC_0), _______,   _______, _______, _______,    _______,     _______,   _______, _______,
        KC_INS,   S(KC_2),    S(KC_3),   S(KC_MINUS), KC_GRAVE,      KC_EQUAL,       KC_P7,   KC_P8,     KC_P9,   XXXXXXX, RALT(KC_3), S(KC_SLASH), EMDASH,    KC_QUOT, KC_QUOT,
        _______,  RALT(KC_2), S(KC_DOT), KC_PSLS,     RALT(KC_RBRC), S(KC_6),        KC_P4,   KC_P5,     KC_P6,   XXXXXXX, S(KC_RBRC), S(KC_0),     S(KC_1),   KC_RBRC, S(KC_2),
        _______,  S(KC_4),    KC_PAST,   S(KC_5),     RALT(KC_4),    RALT(KC_EQUAL), KC_P1,   KC_P2,     KC_P3,   XXXXXXX, S(KC_3),    KC_NUBS,     S(KC_NUBS),KC_PGUP, LSFT(KC_MINUS),
        CW_TOGG,  CM_TOGG,    _______,   _______,     _______,       _______,        KC_P0,   KC_GT,     S(KC_1), _______, _______,    _______,     KC_HOME,   KC_PGDN, KC_END
    )

};

// COMBOS ----------------------------------------------------------------------------
enum combo_events {
  C_NAV_HOME,
  C_NAV_END,
  C_SEL_HOME,
  C_SEL_END,
  C_SEL_LINE,
  C_SEL_ALL,
  C_DELWORD,
  C_GAMEMODE,
  C_CAPSLOCK,
  C_CAPSWORD,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM c_nav_home[] = {KC_UP, KC_LEFT, COMBO_END};
const uint16_t PROGMEM c_nav_end[] = {KC_UP, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM c_sel_home[] = {KC_DOWN, KC_LEFT, COMBO_END};
const uint16_t PROGMEM c_sel_end[] = {KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM c_sel_line[] = {KC_LEFT, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM c_sel_all[] = {KC_UP, KC_DOWN, COMBO_END};
const uint16_t PROGMEM c_delword[] = {KC_TAB, KC_BSPC, COMBO_END};
const uint16_t PROGMEM c_gamemode[] = {KC_HOME, KC_END, COMBO_END};
const uint16_t PROGMEM c_capslock[] = {KC_TAB, KC_ESC, COMBO_END};
const uint16_t PROGMEM c_capsword[] = {KC_LCTL, KC_LGUI, COMBO_END};


combo_t key_combos[] = {
	[C_NAV_HOME] = COMBO(c_nav_home, KC_HOME), //check that combo works the same as combo_action
	[C_NAV_END] = COMBO(c_nav_end, KC_END),
    
	[C_SEL_HOME] = COMBO(c_sel_home, S(KC_HOME)),
	[C_SEL_END] = COMBO(c_sel_end, S(KC_END)),
	[C_SEL_LINE] = COMBO_ACTION(c_sel_line),
    [C_SEL_ALL] = COMBO(c_sel_all, C(KC_A)),
	
	[C_DELWORD] = COMBO(c_delword, C(KC_BSPC)),
	[C_GAMEMODE] = COMBO(c_gamemode, TG(_GAM)),
	[C_CAPSLOCK] = COMBO(c_capslock, KC_CAPS),
	[C_CAPSWORD] = COMBO(c_capsword, CW_TOGG),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
	  
	  case C_SEL_LINE:
	  if (pressed) {
		tap_code16(KC_HOME);
        tap_code16(S(KC_END));
	  }
	  break;
  }
}

// MACROS ---------------------------------------------------------------------------------



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_caps_word(keycode, record)) { return false; }
    switch (keycode) {
    case TXT1:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(TXTMACRO1);
        } else {
            // when keycode is released
        }
        break;
	case TXT2:
        if (record->event.pressed) {            
            SEND_STRING(TXTMACRO2);
        }
        break;	
	case TXT3:
		if (record->event.pressed) {
			SEND_STRING(TXTMACRO3);
		}
		break;
	case EMDASH:
        if (record->event.pressed) {            
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));
        }
        break;		
	case  TESTKEY:
		if (record->event.pressed) {            
			SEND_STRING("Keyboard: " QMK_KEYBOARD ", Keymap:" QMK_KEYMAP);
		}
		break;
	
	// end cases ------------------------
	}
    return true;
};

// RGB LIGHTING ------------------------------------------------------------------

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _CMK:
        rgblight_setrgb (0xFF,  0x66, 0x00);//0xFF,  0x66, 0x00 yellow   0xFF,  0x00, 0x88 pink
        break;
    case _QWE:
        rgblight_setrgb (0xFF,  0x66, 0x33);     
        break;
    case _GAM:
        rgblight_setrgb (0x00,  0xAA, 0xFF);
        break;
    case _COD:
        rgblight_setrgb (0xFF,  0x00, 0x88);
        break;
	case _SYM:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _NUM:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0xFF,  0x66, 0x00);
        break;
    }
  return state;
}


// TAP DANCE ----------------------------------------------------------------
// in keymap use TD(DANCE_0)

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[9];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

//--- REFACTOR DANCE ------------------------------------

void td_dance(int TAP, tap_dance_state_t *state);
void td_dance2(int TAP, int DBTAP, tap_dance_state_t *state);
void td_finished(int dstate, int TAP, int HOLD, tap_dance_state_t *state);
void td_reset(int dstate, int TAP, int HOLD, tap_dance_state_t *state);

void td_dance(int TAP, tap_dance_state_t *state)
{
    if(state->count == 2) { //3
        tap_code16(TAP);
        tap_code16(TAP);
        //tap_code16(TAP);
    }
    if(state->count > 2) { //3
        tap_code16(TAP);
    }
}

void td_dance2(int TAP, int DBTAP, tap_dance_state_t *state)
{
    if(state->count == 2) { //3
        tap_code16(DBTAP);
    }
    if(state->count > 2) { //3
        tap_code16(TAP);
    }
}

void td_finished(int dstate, int TAP, int HOLD, tap_dance_state_t *state)
{
    dance_state[dstate].step = dance_step(state);
    switch (dance_state[dstate].step) {
        case SINGLE_TAP: register_code16(TAP); break;
        case SINGLE_HOLD: tap_code16(HOLD); break;  //register
        case DOUBLE_HOLD: register_code16(TAP); break;
        //case DOUBLE_TAP: register_code16(TAP); register_code16(TAP); break;
        //case DOUBLE_SINGLE_TAP: tap_code16(TAP); register_code16(TAP);
    }
}

void td_reset(int dstate, int TAP, int HOLD, tap_dance_state_t *state)
{
    wait_ms(10);
    switch (dance_state[dstate].step) {
        case SINGLE_TAP: unregister_code16(TAP); break;
        //case SINGLE_HOLD: unregister_code16(HOLD); break;
        case DOUBLE_HOLD: unregister_code16(TAP); break;
        //case DOUBLE_TAP: unregister_code16(TAP); break;
        //case DOUBLE_SINGLE_TAP: unregister_code16(TAP); break;
    }
    dance_state[dstate].step = 0;
}

//---

//----------- DANCE 0 ------------------------------------------------

void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    td_dance(D0_TAP, state);
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    td_finished(0,D0_TAP,D0_HOLD,state);
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    td_reset(0,D0_TAP,D0_HOLD,state);
}

//----------- DANCE 1 ------------------------------------------------

void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    td_dance(D1_TAP, state);
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    td_finished(1,D1_TAP,D1_HOLD,state);
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    td_reset(1,D1_TAP,D1_HOLD,state);
}

//----------- DANCE 2 ------------------------------------------------

void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    td_dance(D2_TAP, state);
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    td_finished(2,D2_TAP,D2_HOLD,state);
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    td_reset(2,D2_TAP,D2_HOLD,state);
}

//----------- DANCE 3 ------------------------------------------------

void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

//double tap version
void on_dance_3(tap_dance_state_t *state, void *user_data) {
    td_dance2(D3_TAP, D3_DBTAP, state);
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    td_finished(3,D3_TAP,D3_HOLD,state);
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    td_reset(3,D3_TAP,D3_HOLD,state);
}

//----------- DANCE 4 ------------------------------------------------

void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    td_dance(D4_TAP, state);
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    td_finished(4,D4_TAP,D4_HOLD,state);
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    td_reset(4,D4_TAP,D4_HOLD,state);
}

//----------- DANCE 5 ------------------------------------------------

void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    td_dance(D5_TAP, state);
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    td_finished(5,D5_TAP,D5_HOLD,state);
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    td_reset(5,D5_TAP,D5_HOLD,state);
}

//-----------------------------------------------------------------

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        /*[DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),*/
};
