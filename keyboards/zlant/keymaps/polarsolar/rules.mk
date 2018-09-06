RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
TAP_DANCE_ENABLE = yes
COMBO_ENABLE ?=yes # Enable key combinations
EXTRAKEY_ENABLE = no
CONSOLE_ENABLE = no


ifndef QUANTUM_DIR
	include ../../../../Makefile
endif