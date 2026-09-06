/* (Starbyt's code) */
#include "/sys/driver_info.h"

#include <cmd.h>
#include <mud_name.h>

nomask int
sysinfo_cmd()
{
    if (!CHECK) return 0;

    write(MUD_NAME+" at " + query_host_name() + "\n");
#ifdef COMPAT_FLAG
    write("LP " + version() + " COMPAT.\n");
#else
    write("LP " + version() + ".\n")
#endif
    write(ctime(time()) + "\n");
    write(driver_info(DI_LOAD_AVERAGE_COMMANDS) + " commands.\n");
    write(driver_info(DI_LOAD_AVERAGE_LINES) + " lines.\n");
    write(sizeof(users()) + " interactives.\n");
    write(sizeof(call_out_info()) + " callouts pending.\n");
    write((int)nature()->query_sizeof_req() + " timerequests pending.\n");

    return 1;
}
