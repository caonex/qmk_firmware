# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DNO_USB_STARTUP_CHECK -DENABLE_FACTORY_TEST
OPT_DEFS += -DKC_BLUETOOTH_ENABLE

SRC += matrix.c

include keyboards/keychron/bluetooth/bluetooth.mk

# Custom 
TAP_DANCE_ENABLE = yes
#COMBO_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
#COMMAND_ENABLE = no
#CONSOLE_ENABLE = yes
