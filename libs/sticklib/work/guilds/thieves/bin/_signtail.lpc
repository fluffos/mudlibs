#include <room_defs.h>
#include "../dirs.h"
#include "../ranks.h"

status
signtail_cmd(object mark, object who, string arg)
{
    if (!who || !mark) return 0;

    if (environment(who)->query(ROOM_ISOLATED))
    {
	notify_fail("Nothing on sign log.\n");
	return 0;
    }

    if ((int)mark->query_guildmaster() < TR_ENFORCER)
	return notify_fail("You can't read sign log!\n"), 0;

    tail(GDIR + "SIGN_LOG");

    return 1;
}
