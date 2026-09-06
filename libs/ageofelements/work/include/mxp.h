#ifndef MXP_H
#define MXP_H

/* strings */

#define MXP_BEG "\x03"    /* becomes < */
#define MXP_END "\x04"    /* becomes > */
#define MXP_AMP "\x05"    /* becomes & */

/* characters */

#define MXP_BEGc '\x03'    /* becomes < */
#define MXP_ENDc '\x04'    /* becomes > */
#define MXP_AMPc '\x05'    /* becomes & */

/* constructs an MXP tag with < and > around it */

#define MXPTAG(arg) sprintf("%s%s%s", MXP_BEG, arg, MXP_END)

#define ESC "\x1B"  /* esc character */

#define MXPMODE(arg) sprintf("%s[%dz", ESC, arg)

#endif // MXP_H
