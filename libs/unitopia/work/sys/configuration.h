// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/configuration.h
// Description: Defines fuer configure_*-Efuns.
// Author:      Driver
//
// $Log: configuration.h,v $
// Revision 1.6  2016/03/21 12:47:47  gnomi
// Neue Dateien von LDMud 3.5.0 eingespielt.
//
// Revision 1.5  2015/08/26 21:40:31  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.4  2013/03/16 16:08:48  gnomi
// Driver-Update.
//
// Revision 1.3  2011-04-28 15:35:13  gnomi
// Vom 3.5.0 eingespielt.
//
// Revision 1.2  2009-06-17 08:04:06  gnomi
// Neue Version von 3.3.719.
//
// Revision 1.1  2009-04-21 11:52:02  gnomi
// Vom 3.3.718 eingespielt
//

#ifndef LPC_CONFIGURATION_H_
#define LPC_CONFIGURATION_H_

/* Definition of argument values for the configure_*() efuns.
 */

/* Possible options for configure_interactive().
 */
#define IC_MAX_WRITE_BUFFER_SIZE         0
#define IC_SOCKET_BUFFER_SIZE            1
#define IC_COMBINE_CHARSET_AS_STRING     2
#define IC_COMBINE_CHARSET_AS_ARRAY      3
#define IC_CONNECTION_CHARSET_AS_STRING  4
#define IC_CONNECTION_CHARSET_AS_ARRAY   5
#define IC_QUOTE_IAC                     6
#define IC_TELNET_ENABLED                7
#define IC_MCCP                          8
#define IC_PROMPT                        9
#define IC_MAX_COMMANDS                 10
#define IC_MODIFY_COMMAND               11

/* Possible options for configure_object().
 */
#define OC_COMMANDS_ENABLED    0
#define OC_HEART_BEAT          1

/* Possible options for configure_driver().
 */
#define DC_MEMORY_LIMIT                  0
#define DC_ENABLE_HEART_BEATS            1
#define DC_LONG_EXEC_TIME                2
#define DC_DATA_CLEAN_TIME               3
#define DC_TLS_CERTIFICATE               4
#define DC_TLS_DHE_PARAMETER             5
#define DC_TLS_CIPHERLIST                6
#define DC_EXTRA_WIZINFO_SIZE            7
#define DC_DEFAULT_RUNTIME_LIMITS        8
#define DC_SWAP_COMPACT_MODE             9

#endif /* LPC_CONFIGURATION_H_ */
