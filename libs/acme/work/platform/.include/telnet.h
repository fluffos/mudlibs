#ifndef _TELNET_H
#define _TELNET_H

#include "sys/telnet.h"

#define TELCMDS         ({                      \
                          "EOF",                \
                          "SUSP",               \
                          "ABORT",              \
                          "EOR",                \
                          "SE",                 \
                          "NOP",                \
                          "DMARK",              \
                          "BRK",                \
                          "IP",                 \
                          "AO",                 \
                          "AYT",                \
                          "EC",                 \
                          "EL",                 \
                          "GA",                 \
                          "SB",                 \
                          "WILL",               \
                          "WONT",               \
                          "DO",                 \
                          "DONT",               \
                          "IAC",                \
                        })

#define  TELCMD_FIRST   xEOF
#define  TELCMD_LAST    IAC
#define  TELCMD_OK(x)   ((x) <= TELCMD_LAST && (x) >= TELCMD_FIRST)
#define  TELCMD(x)      TELCMDS[(x)-TELCMD_FIRST]

#define TELOPTS         ({                                                 \
                          "BINARY", "ECHO", "RCP", "SUPPRESS GO AHEAD",    \
                          "NAME", "STATUS", "TIMING MARK", "RCTE", "NAOL", \
                          "NAOP", "NAOCRD", "NAOHTS", "NAOHTD", "NAOFFD",  \
                          "NAOVTS", "NAOVTD", "NAOLFD", "EXTEND ASCII",    \
                          "LOGOUT", "BYTE MACRO", "DATA ENTRY TERMINAL",   \
                          "SUPDUP", "SUPDUP OUTPUT", "SEND LOCATION",      \
                          "TERMINAL TYPE", "END OF RECORD", "TACACS UID",  \
                          "OUTPUT MARKING", "TTYLOC", "3270 REGIME",       \
                          "X.3 PAD", "NAWS", "TSPEED", "LFLOW",            \
                          "LINEMODE",                                      \
                        })

#define TELOPT_FIRST    TELOPT_BINARY
#define TELOPT_LAST     TELOPT_LINEMODE
#define TELOPT_OK(x)    ((x) <= TELOPT_LAST && (x) >= TELOPT_FIRST)
#define TELOPT(x)       TELOPTS[(x)-TELOPT_FIRST]

#endif  // _TELNET_H
