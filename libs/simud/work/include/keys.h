#ifndef _KEYS_H_
#define _KEYS_H_

#define MAX_KEY_INDEX  299

#define KEY_NONE       -2
#define KEY_UNKNOWN    -1
#define KEY_F1         11
#define KEY_F2         12
#define KEY_F3         13
#define KEY_F4         14
#define KEY_F5         15
#define KEY_F6         16
#define KEY_F7         17
#define KEY_F8         18
#define KEY_F9         19
#define KEY_F10        20
#define KEY_F11        21
#define KEY_F12        22
#define KEY_CTRL_A     100
#define KEY_HOME       100
#define KEY_CTRL_B     101
#define KEY_CTRL_C     102
#define KEY_CTRL_D     103
#define KEY_CTRL_E     104
#define KEY_END        104
#define KEY_CTRL_F     105
#define KEY_CTRL_G     106
#define KEY_CTRL_H     107
#define KEY_BACKSPACE  107
#define KEY_CTRL_I     108
#define KEY_TAB        108
#define KEY_CTRL_J     109
#define KEY_LF         109
#define KEY_CTRL_K     110
#define KEY_CTRL_L     111
#define KEY_CTRL_M     112
#define KEY_CR         112
#define KEY_CTRL_N     113
#define KEY_CTRL_O     114
#define KEY_CTRL_P     115
#define KEY_CTRL_Q     116
#define KEY_CTRL_R     117
#define KEY_CTRL_S     118
#define KEY_CTRL_T     119
#define KEY_CTRL_U     120
#define KEY_PGUP       120
#define KEY_CTRL_V     121
#define KEY_PGDN       121
#define KEY_CTRL_W     122
#define KEY_CTRL_X     123
#define KEY_CTRL_Y     124
#define KEY_CTRL_Z     125
#define KEY_UP         200
#define KEY_DOWN       201
#define KEY_LEFT       202
#define KEY_RIGHT      203
#define KEY_DELETE     207
#define KEY_INSERT     210

#define KEY_NAMES ([ \
  KEY_F1: "function1", \
  KEY_F2: "function2", \
  KEY_F3: "function3", \
  KEY_F4: "function4", \
  KEY_F5: "function5", \
  KEY_F6: "function6", \
  KEY_F7: "function7", \
  KEY_F8: "function8", \
  KEY_F9: "function9", \
  KEY_F10: "function10", \
  KEY_F11: "function11", \
  KEY_F12: "function12", \
  KEY_CTRL_B: "control-b", \
  KEY_CTRL_C: "control-c", \
  KEY_CTRL_D: "control-d", \
  KEY_CTRL_F: "control-f", \
  KEY_CTRL_G: "control-g", \
  KEY_BACKSPACE: "backspace", \
  KEY_TAB: "tab", \
  KEY_LF: "linefeed", \
  KEY_CTRL_K: "control-k", \
  KEY_CTRL_L: "control-l", \
  KEY_CR: "carriage-return", \
  KEY_CTRL_N: "control-n", \
  KEY_CTRL_O: "control-o", \
  KEY_CTRL_P: "control-p", \
  KEY_CTRL_Q: "control-q", \
  KEY_CTRL_R: "control-r", \
  KEY_CTRL_S: "control-s", \
  KEY_CTRL_T: "control-t", \
  KEY_CTRL_W: "control-w", \
  KEY_CTRL_X: "control-x", \
  KEY_CTRL_Y: "control-y", \
  KEY_CTRL_Z: "control-z", \
  KEY_UP: "move-up", \
  KEY_DOWN: "move-down", \
  KEY_LEFT: "move-left", \
  KEY_RIGHT: "move-right", \
  KEY_PGDN: "move-page-down", \
  KEY_PGUP: "move-page-up", \
  KEY_DELETE: "delete-right", \
  KEY_END: "end-of-line", \
  KEY_HOME: "start-of-line", \
  KEY_INSERT: "insert-mode" \
])

#define DEFAULT_KEYS ([ \
   "\27\79\65":KEY_UP, \
   "\27\79\66":KEY_DOWN, \
   "\27\79\68":KEY_LEFT, \
   "\27\79\67":KEY_RIGHT, \
   "\27\91\65":KEY_UP, \
   "\27\91\66":KEY_DOWN, \
   "\27\91\68":KEY_LEFT, \
   "\27\91\67":KEY_RIGHT, \
   "\27\65":KEY_UP, \
   "\27\66":KEY_DOWN, \
   "\27\68":KEY_LEFT, \
   "\27\67":KEY_RIGHT, \
   "\27\91\54\126":KEY_PGDN, \
   "\27\91\53\126":KEY_PGUP, \
   "\127":KEY_BACKSPACE, \
   "\27\91\51\126":KEY_DELETE, \
   "\27\91\52\126":KEY_END, \
   "\27\91\49\126":KEY_HOME,\
   "\27\91\50\126":KEY_HOME,\
   "\27\91\56\126":KEY_END, \
   "\27\79\72":KEY_HOME, \
   "\27\79\70":KEY_END, \
   "\27\91\55\126":KEY_HOME, \
   "\27\91\72":KEY_HOME, \
   "\27\91\70":KEY_END, \
   "\27\91\76":KEY_INSERT, \
   "\27\64":KEY_INSERT, \
   "\27\91\49\49\126":KEY_F1, \
   "\27\91\49\50\126":KEY_F2, \
   "\27\91\49\51\126":KEY_F3, \
   "\27\91\49\52\126":KEY_F4, \
   "\27\91\49\53\126":KEY_F5, \
   "\27\91\49\54\126":KEY_F6, \
   "\27\91\49\55\126":KEY_F7, \
   "\27\91\49\56\126":KEY_F8, \
   "\27\91\49\57\126":KEY_F9, \
   "\27\91\49\58\126":KEY_F10, \
   "\27\91\49\59\126":KEY_F11, \
   "\27\91\49\60\126":KEY_F12, \
   "\27\91\91\65":KEY_F1, \
   "\27\91\91\66":KEY_F2, \
   "\27\91\91\67":KEY_F3, \
   "\27\91\91\68":KEY_F4, \
   "\27\91\91\69":KEY_F5, \
   "\1":KEY_HOME, \
   "\2":KEY_CTRL_B, \
   "\3":KEY_CTRL_C, \
   "\4":KEY_CTRL_D, \
   "\5":KEY_END, \
   "\6":KEY_CTRL_F, \
   "\7":KEY_CTRL_G, \
   "\8":KEY_CTRL_H, \
   "\9":KEY_CTRL_I, \
   "\10":KEY_LF, \
   "\11":KEY_CTRL_K, \
   "\12":KEY_CTRL_L, \
   "\13":KEY_CTRL_M, \
   "\14":KEY_CTRL_N, \
   "\15":KEY_CTRL_O, \
   "\16":KEY_CTRL_P, \
   "\17":KEY_CTRL_Q, \
   "\18":KEY_CTRL_R, \
   "\19":KEY_CTRL_S, \
   "\20":KEY_CTRL_T, \
   "\21":KEY_PGUP, \
   "\22":KEY_PGDN, \
   "\23":KEY_CTRL_W, \
   "\24":KEY_CTRL_X, \
   "\25":KEY_CTRL_Y, \
   "\26":KEY_CTRL_Z, \
   "\27\79\80":KEY_F1, \
   "\27\79\81":KEY_F2, \
   "\27\79\82":KEY_F3, \
   "\27\79\83":KEY_F4, \
   "\27\79\116":KEY_F5, \
   "\27\79\117":KEY_F6, \
   "\27\79\118":KEY_F7, \
   "\27\79\108":KEY_F8, \
   "\27\79\119":KEY_F9, \
   "\27\79\120":KEY_F10, \
   "\27\79\121":KEY_F11, \
   "\27\79\122":KEY_F12, \
   "\27\91\77":KEY_F1, \
   "\27\91\78":KEY_F2, \
   "\27\91\79":KEY_F3, \
   "\27\91\80":KEY_F4, \
   "\27\91\81":KEY_F5, \
   "\27\91\82":KEY_F6, \
   "\27\91\83":KEY_F7, \
   "\27\91\84":KEY_F8, \
   "\27\91\85":KEY_F9, \
   "\27\91\86":KEY_F10, \
   "\27\91\87":KEY_F11, \
   "\27\91\88":KEY_F12 \
])

#endif