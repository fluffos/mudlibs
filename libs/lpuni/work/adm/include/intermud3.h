/* intermud3.h

 Tricky @ LPUniversity
 17-AUG-2006
 Intermud3 include file

 Last updated: August 25th, 2006 by Tricky @ LPUniversity
 Last updated: October 4th, 2006 by Tricky @ LPUniversity

*/

#ifndef __intermud_3__
#define __intermud_3__

#include <logs.h>

#define I3LOG(m)        log_file(LOG_I3, sprintf("%s:%s", ctime(time())[4..18], m))

/* Intermud 3 data file location */
#define I3_DATA_FILE    "/data/daemons/chmodules/i3"

/* How many line of history for each channel to keep */
#define HISTORY_SIZE    500

/* The base directory for the channel histories
   Each channel has it's own file */
#define HISTORY_DIR     "/data/daemons/chmodules/i3_history"

#define CHANINDEX_FILE  "/data/daemons/chmodules/chanindex"

#define I3_FILE_DIR     "/ftp"

/* Define this to create the i3raw channel */
#define I3RAW
#undef I3RAW

/* Define this to announce to the lpuni channel when
   a new LPUniLib mud is created.

   This is experimental. Do not turn it on unless you want
   to annoy lpuni channel listeners. :)

   I'm not sure it works to be honest. 
*/
#define CHECK_NEW_LPUNI_MUD
#undef CHECK_NEW_LPUNI_MUD

/* The base I3 packet */
#define SERVICE         0    /* name of requested service */
#define HOPS            1    /* ttl */
#define O_MUD           2    /* origination mudname */
#define O_USER          3    /* origination username */
#define D_MUD           4    /* destination mudname */
#define D_USER          5    /* destination username */

#endif /* intermud_3 */
