RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
TAP_DANCE_ENABLE = yes
CONSOLE_ENABLE = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
