//telnet_def.h
//the file is used for Telnet negotiation
//wings@HC

#ifndef _TELNET_DEF_H
#define _TELNET_DEF_H 1

/*
 * Definitions for the TELNET protocol.
 */
#define IAC     "\xFF"                       /* interpret as command: */
#define DONT    "\xFE"                       /* you are not to use option */
#define DO      "\xFD"                       /* please, you use option */
#define WONT    "\xFC"                       /* I won't use option */
#define WILL    "\xFB"                       /* I will use option */
#define SB      "\xFA"                       /* interpret as subnegotiation */
#define GA      "\xF9"                       /* you may reverse the line */
#define EL      "\xF8"                       /* erase the current line */
#define EC      "\xF7"                       /* erase the current character */
#define AYT     "\xF6"                       /* are you there */
#define AO      "\xF5"                       /* abort output--but let prog finish */
#define IP      "\xF4"                       /* interrupt process--permanently */
#define BREAK   "\xF3"                       /* break */
#define DM      "\xF2"                       /* data mark--for connect. cleaning */
#define NOP     "\xF1"                       /* nop */
#define SE      "\xF0"                       /* end sub negotiation */
#define EOR     "\xEF"                       /* end of record (transparent mode) */
#define ABORT   "\xEE"                       /* Abort process */
#define SUSP    "\xED"                       /* Suspend process */
#define xEOF    "\xEC"                       /* End of file: EOF is already used... */

#define SYNCH   "\xF2"                       /* for telfunc calls */

/*
 * telnet options.
*/
#define TELOPT_BINARY   "\x0"                   /* 8-bit data path */
#define TELOPT_ECHO     "\x01"                  /* echo */
#define TELOPT_RCP      "\x02"                  /* prepare to reconnect */
#define TELOPT_SGA      "\x03"                  /* suppress go ahead */
#define TELOPT_NAMS     "\x04"                  /* approximate message size */
#define TELOPT_STATUS   "\x05"                  /* give status */
#define TELOPT_TM       "\x06"                  /* timing mark */
#define TELOPT_RCTE     "\x07"                  /* remote controlled transmission and echo */
#define TELOPT_NAOL     "\x08"                  /* negotiate about output line width */
#define TELOPT_NAOP     "\x09"                  /* negotiate about output page size */
#define TELOPT_NAOCRD   "\x0A"                  /* negotiate about CR disposition */
#define TELOPT_NAOHTS   "\x0B"                  /* negotiate about horizontal tabstops */
#define TELOPT_NAOHTD   "\x0C"                  /* negotiate about horizontal tab disposition */
#define TELOPT_NAOFFD   "\x0D"                  /* negotiate about formfeed disposition */
#define TELOPT_NAOVTS   "\x0E"                  /* negotiate about vertical tab stops */
#define TELOPT_NAOVTD   "\x0F"                  /* negotiate about vertical tab disposition */
#define TELOPT_NAOLFD   "\x10"                  /* negotiate about output LF disposition */
#define TELOPT_XASCII   "\x11"                  /* extended ascii character set */
#define TELOPT_LOGOUT   "\x12"                  /* force logout */
#define TELOPT_BM       "\x13"                  /* byte macro */
#define TELOPT_DET      "\x14"                  /* data entry terminal */
#define TELOPT_SUPDUP   "\x15"                  /* supdup protocol */
#define TELOPT_SUPDUPOUTPUT "\x16"              /* supdup output */
#define TELOPT_SNDLOC   "\x17"                  /* send location */
#define TELOPT_TTYPE    "\x18"                  /* terminal type */
#define TELOPT_EOR      "\x19"                  /* end or record */
#define TELOPT_TUID     "\x1A"                  /* TACACS user identification */
#define TELOPT_OUTMRK   "\x1B"                  /* output marking */
#define TELOPT_TTYLOC   "\x1C"                  /* terminal location number */
#define TELOPT_3270REGIME "\x1D"                /* 3270 regime */
#define TELOPT_X3PAD    "\x1E"                  /* X.3 PAD */
#define TELOPT_NAWS     "\x1F"                  /* window size */
#define TELOPT_TSPEED   "\x20"                  /* terminal speed */
#define TELOPT_LFLOW    "\x21"                  /* remote flow control */
#define TELOPT_LINEMODE "\x22"                  /* Linemode option */
#define TELOPT_XDISPLOC "\x23"                  /* X Display Location */
#define TELOPT_OLD_ENVIRON "\x24"               /* Old - Environment variables */
#define TELOPT_AUTHENTICATION "\x25"            /* Authenticate */
#define TELOPT_ENCRYPT  "\x26"                  /* Encryption option */
#define TELOPT_NEW_ENVIRON "\x27"               /* New - Environment variables */
#define TELOPT_EXOPL    "\xFF"                  /* extended-options-list */

#define TELOPT_MXP      "\x5B"                  /* Mud eXtension Protocol option */

#endif/*_TELNET_DEF_H*/
