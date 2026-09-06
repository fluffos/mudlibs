#ifndef __LOCAL_TELNET_H__
#define __LOCAL_TELNET_H__
#ifndef TELNET_H__
#include "driver/telnet.h"
#endif

#define TELCMDS ({\
    "EOF", "SUSP", "ABORT", "EOR", \
    "SE", "NOP", "DMARK", "BRK", "IP", "AO", "AYT", "EC", \
    "EL", "GA", "SB", "WILL", "WONT", "DO", "DONT", "IAC", \
})

/* backward starting with IAC == 255 */
#define TELCMD2STRING(x) (((256-x)<sizeof(TELCMDS))?TELCMDS[<(256-x)]:(""+x))

#define TELOPTS ({\
    "BINARY", "ECHO", "RCP", "SUPPRESS GO AHEAD" \
  , "NAME", "STATUS", "TIMING MARK", "RCTE" \
  , "NAOL", "NAOP", "NAOCRD", "NAOHTS" \
  , "NAOHTD", "NAOFFD", "NAOVTS", "NAOVTD" \
  , "NAOLFD", "EXTEND ASCII", "LOGOUT", "BYTE MACRO" \
  , "DATA ENTRY TERMINAL", "SUPDUP", "SUPDUP OUTPUT", "SEND LOCATION" \
  , "TERMINAL TYPE", "END OF RECORD", "TACACS UID", "OUTPUT MARKING" \
  , "TTYLOC", "3270 REGIME", "X.3 PAD", "NAWS" \
  , "TSPEED", "LFLOW", "LINEMODE", "XDISPLOC" \
  , "ENVIRON", "AUTH", "ENCRYPT", "NEWENV" \
  , "TELOPT 40", "TELOPT 41", "CHARSET", "TELOPT 43" \
  , "TELOPT 44", "TELOPT 45", "STARTTLS", "KERMIT" \
  , "SEND_URL", "TELOPT 49", "TELOPT 50", "TELOPT 51" \
  , "TELOPT 52", "TELOPT 53", "TELOPT 54", "TELOPT 55" \
  , "TELOPT 56", "TELOPT 57", "TELOPT 58", "TELOPT 59" \
  , "TELOPT 60", "TELOPT 61", "TELOPT 62", "TELOPT 63" \
  , "TELOPT 64", "TELOPT 65", "TELOPT 66", "TELOPT 67" \
  , "TELOPT 68", "TELOPT 69", "MSSP", "TELOPT 71" \
  , "TELOPT 72", "TELOPT 73", "TELOPT 74", "TELOPT 75" \
  , "TELOPT 76", "TELOPT 77", "TELOPT 78", "TELOPT 79" \
  , "TELOPT 80", "TELOPT 81", "TELOPT 82", "TELOPT 83" \
  , "TELOPT 84", "MUD COMPRESS", "MUD COMPRESS2", "TELOPT 87" \
  , "TELOPT 88", "TELOPT 89", "MUD SOUND", "MUD EXTENSION" \
  , "TELOPT 92", "ZMP", "TELOPT 94", "TELOPT 95" \
  , "TELOPT 96", "TELOPT 97", "TELOPT 98", "TELOPT 99" \
  , "TELOPT 100", "TELOPT 101", "MUSHCLIENT", "TELOPT 103" \
  , "TELOPT 104", "TELOPT 105", "TELOPT 106", "TELOPT 107" \
  , "TELOPT 108", "TELOPT 109", "TELOPT 110", "TELOPT 111" \
  , "TELOPT 112", "TELOPT 113", "TELOPT 114", "TELOPT 115" \
  , "TELOPT 116", "TELOPT 117", "TELOPT 118", "TELOPT 119" \
  , "TELOPT 120", "TELOPT 121", "TELOPT 122", "TELOPT 123" \
  , "TELOPT 124", "TELOPT 125", "TELOPT 126", "TELOPT 127" \
  , "TELOPT 128", "TELOPT 129", "TELOPT 130", "TELOPT 131" \
  , "TELOPT 132", "TELOPT 133", "TELOPT 134", "TELOPT 135" \
  , "TELOPT 136", "TELOPT 137", "TELOPT 138", "TELOPT 139" \
  , "TELOPT 140", "TELOPT 141", "TELOPT 142", "TELOPT 143" \
  , "TELOPT 144", "TELOPT 145", "TELOPT 146", "TELOPT 147" \
  , "TELOPT 148", "TELOPT 149", "TELOPT 150", "TELOPT 151" \
  , "TELOPT 152", "TELOPT 153", "TELOPT 154", "TELOPT 155" \
  , "TELOPT 156", "TELOPT 157", "TELOPT 158", "TELOPT 159" \
  , "TELOPT 160", "TELOPT 161", "TELOPT 162", "TELOPT 163" \
  , "TELOPT 164", "TELOPT 165", "TELOPT 166", "TELOPT 167" \
  , "TELOPT 168", "TELOPT 169", "TELOPT 170", "TELOPT 171" \
  , "TELOPT 172", "TELOPT 173", "TELOPT 174", "TELOPT 175" \
  , "TELOPT 176", "TELOPT 177", "TELOPT 178", "TELOPT 179" \
  , "TELOPT 180", "TELOPT 181", "TELOPT 182", "TELOPT 183" \
  , "TELOPT 184", "TELOPT 185", "TELOPT 186", "TELOPT 187" \
  , "TELOPT 188", "TELOPT 189", "TELOPT 190", "TELOPT 191" \
  , "TELOPT 192", "TELOPT 193", "TELOPT 194", "TELOPT 195" \
  , "TELOPT 196", "TELOPT 197", "TELOPT 198", "TELOPT 199" \
  , "ATCP", "GMCP", "TELOPT 202", "TELOPT 203" \
  , "TELOPT 204", "TELOPT 205", "TELOPT 206", "TELOPT 207" \
  , "TELOPT 208", "TELOPT 209", "TELOPT 210", "TELOPT 211" \
  , "TELOPT 212", "TELOPT 213", "TELOPT 214", "TELOPT 215" \
  , "TELOPT 216", "TELOPT 217", "TELOPT 218", "TELOPT 219" \
  , "TELOPT 220", "TELOPT 221", "TELOPT 222", "TELOPT 223" \
  , "TELOPT 224", "TELOPT 225", "TELOPT 226", "TELOPT 227" \
  , "TELOPT 228", "TELOPT 229", "TELOPT 230", "TELOPT 231" \
  , "TELOPT 232", "TELOPT 233", "TELOPT 234", "TELOPT 235" \
  , "TELOPT 236", "TELOPT 237", "TELOPT 238", "TELOPT 239" \
  , "TELOPT 240", "TELOPT 241", "TELOPT 242", "TELOPT 243" \
  , "TELOPT 244", "TELOPT 245", "TELOPT 246", "TELOPT 247" \
  , "TELOPT 248", "TELOPT 249", "TELOPT 250", "TELOPT 251" \
  , "TELOPT 252", "TELOPT 253", "TELOPT 254", "EXOPL" \
})

#define TELOPT2STRING(x) ((x<sizeof(TELOPTS))?TELOPTS[x]:(""+x))
#define  TELQUAL_INFO   2

#define TELQUAL2STRING(x) (x<3?({"IS","SEND","INFO"})[x]:""+x)
#define  MODE_SOFT_TAB   0x08
#define  MODE_LIT_ECHO   0x10
#ifdef MODE_MASK
#undef MODE_MASK
#endif
#define  MODE_MASK       (MODE_EDIT|MODE_TRAPSIG|MODE_ACK|MODE_SOFT_TAB|MODE_LIT_ECHO)
#define  SLC_MCL    19
#define  SLC_MCR    20
#define  SLC_MCWL   21
#define  SLC_MCWR   22
#define  SLC_MCBOL  23
#define  SLC_MCEOL  24
#define  SLC_INSRT  25
#define  SLC_OVER   26
#define  SLC_ECR    27
#define  SLC_EWR    28
#define  SLC_EBOL   29
#define  SLC_EEOL   30
#ifdef NSLC
#undef NSLC
#endif /* NSLC */
#define  NSLC       30
#ifdef SLC_NAMES
#undef SLC_NAMES
#endif /* SLC_NAMES */
#define SLC_NAMES       ({"0", "SYNCH", "BRK", "IP", "AO", "AYT", "EOR", \
                        "ABORT", "EOF", "SUSP", "EC", "EL", "EW", "RP", \
                        "LNEXT", "XON", "XOFF", "FORW1", "FORW2", \
                        "MCL", "MCR", "MCWL", "MCWR", "MCBOL", "MCEOL", \
                        "INSRT", "OVER", "ECR", "EWR", "EBOL", "EEOL"})
#define SLC2STRING(x) ((x)<sizeof(SLC_NAMES)?SLC_NAMES[x]:sprintf("%02x",x))
#define SLC_FLAGNAMES    ({ "NOSUPPORT", "CANTCHANGE", "VARIABLE", "DEFAULT" })
#define  ENV_VAR         0
#define  ENV_VALUE       1
#define  ENV_ESC         2
#define  ENV_USERVAR     3

// CHARSET suboptions
#define  CS_REQUEST          1
#define  CS_ACCEPTED         2
#define  CS_REJECTED         3
#define  CS_TTABLE_IS        4
#define  CS_TTABLE_REJECTED  5
#define  CS_TTABLE_ACK       6
#define  CS_TTABLE_NAK       7

#define  CS_FLAGNAMES   ({ "REQUEST", "ACCEPTED", "REJECTED", "TTABLE_IS", \
                           "TTABLE_REJECTED", "TTABLE_ACK", "TTABLE_NAK" })

#define  CS_FLAGNAME(x) ((x)>0 && (x)<sizeof(CS_FLAGNAMES) ? \
                        CS_FLAGNAMES[x-1] : ""+x)

// AUTHENTICATE methods
#define AUTH_METHOD_NULL                 0
#define AUTH_METHOD_KERBEROS_V4          1
#define AUTH_METHOD_KERBEROS_V5          2
#define AUTH_METHOD_SPX                  3
#define AUTH_METHOD_MINK                 4
#define AUTH_METHOD_SRP                  5
#define AUTH_METHOD_RSA                  6
#define AUTH_METHOD_SSL                  7
#define AUTH_METHOD_LOKI                10
#define AUTH_METHOD_SSA                 11
#define AUTH_METHOD_KEA_SJ              12
#define AUTH_METHOD_KEA_SJ_INTEG        13
#define AUTH_METHOD_DSS                 14
#define AUTH_METHOD_NTLM                15

// AUTHENTICATE subnegotiations
#define AUTH_SB_IS                       0
#define AUTH_SB_SEND                     1
#define AUTH_SB_REPLY                    2
#define AUTH_SB_NAME                     3

// AUTHENTICATE modifiers
#define AUTH_WHO_MASK                    1
#define AUTH_WHO_CLIENT_TO_SERVER        0
#define AUTH_WHO_SERVER_TO_CLIENT        1

#define AUTH_HOW_MASK                    2
#define AUTH_HOW_ONE_WAY                 0
#define AUTH_HOW_MUTUAL                  2

#define AUTH_ENCRYPT_MASK               20
#define AUTH_ENCRYPT_OFF                 0
#define AUTH_ENCRYPT_USING_TELOPT        4
#define AUTH_ENCRYPT_AFTER_EXCHANGE     16
#define AUTH_ENCRYPT_RESERVED           20

#define AUTH_INI_CRED_FWD_MASK           8
#define AUTH_INI_CRED_FWD_OFF            0

// AUTH_METHOD_SSL codes
#define AUTH_SSL_START                   1
#define AUTH_SSL_ACCEPT                  2
#define AUTH_SSL_REJECT                  3


#endif /* __LOCAL_TELNET_H__ */
