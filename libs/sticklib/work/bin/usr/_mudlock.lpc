#include <cmd.h>
#include <daemons.h>
#include <mud_name.h>
#include <coder_levels.h>

#define LOCK_MSG "\n\n"+MUD_NAME+" is now locked to new logins for maintenance.\n\n"
#define UNLOCK_MSG "\n\n"+MUD_NAME+" is now unlocked and open to new logins.\n\n"

nomask int mudlock_cmd()
{
    if (!interactive(this_player()) || this_player()->query_coder_level() <= LVL_SENIOR)
	return notify_fail("Must be a senior wizard or higher to lock the mud.\n"), 0;

    MUDLOCK_D->toggle_mudlock();

    return shout(MUDLOCK_D->query_mudlock() ? LOCK_MSG : UNLOCK_MSG), 1;
}
