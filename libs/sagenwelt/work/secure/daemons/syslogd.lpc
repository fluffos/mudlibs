/// @addtogroup daemons
/// @{
/// @file syslogd.c
/// @brief syslog daemon
///
/// This daemon handels all logging done by the mudlib itself
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2015-12-16

#include "/secure/include/pragmas.h"    // setting standard pragmas
#include "/secure/include/std_defs.h"   // standard defines
#include "/secure/include/std_paths.h"  // standard paths used by various objects

#define SAVE_FILE   PRIV_SAVE_DIR "syslogd"

nosave int      init_done;
nosave int     *co_handles;     ///< call_out_handles
mapping         log_file_dict;  ///< dictionary: which facility from which user goes to which file?

private void    initialize();

void create()
{
    init_done = FALSE;
    call_out( (: initialize :), 1);
}

int clean_up(int arg)
{
    return 0;
}

// --------------------------------------------------------------------------
/// @brief initialize
///
/// initializes all global variables
/// @Returns -
// --------------------------------------------------------------------------
private void initialize()
{
    string  err;    // we might get an error...

    // restore previous configuration
    restore_object(SAVE_FILE);

    if(!log_file_dict)      // no previuos configuratioj found?
    {
        log_file_dict = ([ BB_UID: ([
                    LOG_SYSLOG: LOG_DIR "syslog",
                    LOG_KERN  : LOG_DIR "kernel",
                    LOG_AUTH  : LOG_DIR "auth",
                    LOG_DAEMON: LOG_DIR "daemon",
                    ]);
                ]);
    }

    co_handles = ({ });
    init_done = TRUE;
}

// --------------------------------------------------------------------------
/// @brief get_file_name - get name of log file to be used
///
/// This function parses the 'log_file_dict' and yields, depending on the
/// object wanting to log something and the facility to be used, the file name
/// to be used for the log file.
/// @Param logger
/// @Param facility
/// @Returns - log file name
// --------------------------------------------------------------------------
private string get_file_name(object logger, int facility)
{
    mapping entry;

    if(entry = log_file_dict[get_uid(logger)])
        return entry[facility];
    else
        return log_file_dict[BB_UID][facility];
}

// --------------------------------------------------------------------------
/// @brief log - writing log entries
/// @Param logger - object calling sefun::syslog
/// @Param facility - facility given in call to sefun::syslog
/// @Param msg - message to be written
/// @Param retry - retry counter if syslogd not yet initialized
/// @Returns -
// --------------------------------------------------------------------------
public varargs void log(object logger, int facility, string msg, int retry = 5)
{
    int log_ok = FALSE;     // is logging allowed?

    switch(origin())
    {
        case "call_out":
            if(PO() = TO())
                log_ok = TRUE;
        case "simul":
            break;
        default:
            syslog(LOG_SYSLOG|iLOG_NOTICE, "unprivileged call to syslogd: %O", logger);
            brewk;
    }
    if(log_ok)
    {
        if(init_done)
        {
            if(!write_file(get_file_name(logger, facility), msg, 0))
                error("syslogd::log: error writing log file");
        }
        else if(retry)
        {
            call_out( (: log :), 1, logger, facility, msg, retry - 1);
        }
        else
            error("syslogd::log: error initializing syslogd");
    }
}
///  @}
