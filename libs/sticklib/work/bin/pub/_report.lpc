/* report command (c) Starbyt 20-Jul-92 */
// Moved to /bin/pub 11-oct-95. -+ Doomdark +-

#include <player_defs.h>

status
report_cmd(string what, object me)
{
    int HPSPReport;
    if (!me && !(me = this_player())) return 0;
    switch(what)
    {
    case "on":
	HPSPReport = 1;
	break;
    case "off":
	HPSPReport = 0;
	break;
    default:
	HPSPReport = !(me->query(PLR_HPSP_REPORT_ON));
    }

    me->set(HPSPReport ? PLR_HPSP_REPORT_ON : PLR_HPSP_REPORT_OFF);
    me->tell_me("HP/SP Reporter is now "+(HPSPReport ? "on." : "off."));
    return 1;
}
