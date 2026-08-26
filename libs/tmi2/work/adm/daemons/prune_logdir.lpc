//  File    :  /adm/daemons/prune_logdir.c
//  Creator :  Robocoder@TMI
//
//  This daemon prunes the files in the /log directory.
//  At the moment it ignores the contents of subdirectories,
//    such as /log/harass.
//
//  This file loosely modelled after Watcher's clean_dir.c

#include <config.h>
#include <mudlib.h>
#include <daemons.h>
#include <uid.h>

inherit DAEMON;

#ifndef MAX_BYTE_TRANSFER
#define MAX_BYTE_TRANSFER 10000
#endif

#ifndef MAX_LOG_FILE_SIZE
// Set threshhold for maximum log file size (at 100K)
// Should be smaller than "maximum log size" (specified in config file)
#define MAX_LOG_FILE_SIZE (100 * 1024)
#endif

#ifndef MAX_LOG_DAYS
// Set maximum number of days to keep daily backups of "log" & "debug.log"
// A week of logs is fairly sufficient.  Feel free to adjust it according
// to disk space available (more or less).
#define MAX_LOG_DAYS 7
#endif

void backup_debug_log();
void what_log_days();

#define SECS_IN_DAY (60*60*24)
string *log_days;

#define PROTECT ({                                                  \
                   /*                                               \
                    * Special get_dir() stuff                       \
                    */                                              \
                   ".", "..",                                       \
                                                                    \
                   /*                                               \
                    * Don't trim these text files                   \
                    */                                              \
                   "README", "ChangeLog",                           \
                   "BUGS", "IDEAS", "PRAISES", "TYPOS", "QUERIES",  \
                                                                    \
                   /*                                               \
                    * Redirected output                             \
                    * (check your startmud/stopmud scripts)         \
                    */                                              \
                   "driver.log", "driver.err",                      \
                   "aserver.log", "aserver.err",                    \
                })

int prune_logdir() {
    mixed *dir;
    int i, j, s;
    int l, max;
    string what, oldwhat;
    string blk;

    //  Check euid of initiator to confirm correct permissions
    if (geteuid( previous_object() ) != ROOT_UID &&
          !adminp(geteuid( previous_object() )))
        return 0;

    //  Get directory contents array
    dir = get_dir( LOG_DIR "*" );
    if (!dir || !sizeof( dir ))
        return -1;

    //  Ignore protected files
    dir -= PROTECT;

    s = sizeof(dir);
    for (i = 0; i < s; i++) {
        what = LOG_DIR + dir[i];

        //  Skip directories
        if (file_size( what ) == -2)
            continue;

        //  Ignore ".old" and ".bak" files
        l = strlen( what );
        if (l >= 4 && (what[l-4 .. l-1] == ".old" || what[l-4 .. l-1] == ".bak"))
            continue;

        //  Archive "big" files
        if (file_size( what ) >= MAX_LOG_FILE_SIZE) {
            oldwhat = what + ".old";
            if (file_size( oldwhat ) >= 0)
                rm( oldwhat );
            if (file_size( oldwhat ) != -2)
                rename( what, oldwhat );
        }
    }

    //  Special handling for ChangeLog
    //  Create backups in the form:
    //      ChangeLog.1, ChangeLog.2, ChangeLog.3, ...
    if (file_size( LOG_DIR "ChangeLog" ) >= MAX_LOG_FILE_SIZE) {
        dir = get_dir( LOG_DIR "ChangeLog*" );
        dir -= ({ "ChangeLog" });

        s = sizeof( dir );
        for (max = 0, i = 0; i < s; i++) {
            l = strlen( dir[i] );
            if (l > 10 && sscanf( dir[i][10..l-1], ".%d", l ) && l > max)
                max = l;
        }
        max++;

        rename( LOG_DIR "ChangeLog", LOG_DIR "ChangeLog." + max );
    }

#if 0
    //  Special handling for "debug.log"
    //  Create backups in /log/DEBUGS/ of the form:
    //    feb27, feb28, mar01, mar02, ...
    if (file_size( LOG_DIR "DEBUGS" ) == -1)
        mkdir( LOG_DIR "DEBUGS" );
    if (file_size( LOG_DIR "DEBUGS" ) == -2) {
        what_log_days();

        dir = get_dir( LOG_DIR "DEBUGS/*" );
        dir -= ({ ".", ".." });

        i = sizeof(dir);

        // back it up only if today's log doesn't already exist;
        // for example, rescheduled prune_logdir for later that same day
        if (!i || (i && file_size( LOG_DIR "DEBUGS/" + log_days[0]) == -1)) {
            l = 0;
            // back up the difference from yesterday's log
            if ( uptime() > SECS_IN_DAY ) {
                s = file_size( LOG_DIR "DEBUGS/" + log_days[1]);
                if (s >= 0 && s < (max = file_size( LOG_DIR "debug.log" ))) {
                    j = 0;
                    while (s < max) {
                        l = max - s;
                        if (l > MAX_BYTE_TRANSFER)
                             l = MAX_BYTE_TRANSFER;
                        blk = read_bytes( LOG_DIR "debug.log", s, l );
                        if (blk) {
                            write_bytes( LOG_DIR "DEBUGS/" + log_days[0], j, blk );
                            j += l;
                            s += l;
                        } else {
                            l = 0;
                            break;
                        }
                    }
                }
            }
            // just copy the file
            if (!l)
                cp(LOG_DIR "debug.log", LOG_DIR "DEBUGS/" + log_days[0]);
        }

        // remove "older" logs
        while (i--) {
            if (strlen(dir[i]) < 5 ||
                  member_array(dir[i][0..4], log_days) == -1)
                rm( LOG_DIR "DEBUGS/" + dir[i] );
        }
    }
#endif

    return 1;
}

// For shutdown calls;
//  Create backups in /log/DEBUGS/ of the form:
//    feb27.010033, feb27.024523, ...
void backup_debug_log() {
    string s;

#if 0
    if (file_name(previous_object()) != SHUTDOWN_D)
        return;

    what_log_days();

    s = ctime(time());
    cp(LOG_DIR "debug.log", sprintf( LOG_DIR "DEBUGS/%s.%s%s%s",
        log_days[0], s[11..12], s[14..15], s[17..18]));
#endif
}

void what_log_days() {
    string s;
    int i, t;

    if (log_days)
        return;

    if (MAX_LOG_DAYS <= 0) {
        log_days = ({ });
        return;
    }

    log_days = allocate(MAX_LOG_DAYS);
    t = time();
    for (i = 0; i < MAX_LOG_DAYS; i++) {
        s = ctime(t);
        log_days[i] = lower_case(sprintf("%s%c%c", s[4 .. 6 ],
                                         s[8] == ' ' ? '0' : s[8], s[9]));
        t -= SECS_IN_DAY;
    }
}
