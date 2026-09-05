/*
 * /sys/logger.h
 * Defines for logger.c
 */
#ifndef _sys_logger_h
#define _sys_logger_h

#include "server.h"

/* For flags used in read_log */
#define L_OBJECT              -100  /* Next index the playername */
#define L_SHOWALL             -101  /* Show all logs (all of player) */
#define L_SHOWOLD             -102  /* Show also the *.old-file */
#define L_HEADER              -103  /* Include a header above the list */

/* Flags in main of logread */
#define L_NO_HEADER           -200
#define L_LOGONNEWS           -201
#define L_HASDAEMON           -202

/* internal defines */
#define L_MAX_LOGLINES        300  /* Maximum lines in *.log */
#define L_MAX_OLDLINES        500  /* Maximum lines in *.old */
#define L_MAX_SWAPLINES       200  /* Maximum lines to swapout */

#define SYSTEMLOG             "logsystem"

/* Mapping-Keys for receive_news */
#define L_INDEX               "log_index"     /* Index of the logdirectory */
#define L_FILE                "log_file"      /* Name of the logfile */
#define L_LTIME               "log_time"      /* Time of logentry */
#define L_OBJNAME             "log_objname"   /* Name of the ob thats logged */
#define L_OBJLEVEL            "log_objlevel"  /* its level */
#define L_TEXT                "log_text"      /* The text of the logentry */

/* Mapping-Keys for read_log */
#define LR_TEXT               "log_read_text" /* text of the logentry */
#define LR_LTIME              "log_read_time" /* time of the logentry */
#define LR_OBJNAME            "log_read_objname"  /* objectname of logentry */
#define LR_OBJLEVEL           "log_read_objlevel" /* level of the object */
#define LR_ERROR              "log_read_error"    /* Error's of logread */

/* return values */
#define L_B_SUCCESS           -100            /* Operation successfull */
#define L_B_NOINDEX           -101            /* No index with this name */
#define L_B_NOWRITEPRIVILEGE  -102            /* No write privilege */
#define L_B_NEWENTRYSTOPPED   -103            /* No new entrys */
#define L_B_ALREADY_IN_USE    -104            /* index name aleready ... */
#define L_B_NO_SUCH_PATH      -105            /* Given path didn't exist */
#define L_B_NO_WRITE_PERMISSIONS  -106
#define L_B_DIRECTORY_NOT_FREE    -107        /* Dir already in use for
                                               * another index           */

#endif
