/* summontoggle command //Frobozz 3.6.1994 */
// Moved to /bin/pub 17-oct-95. -+ Doomdark +-

#include <player_defs.h>

status
summontoggle_cmd(string what, object me)
{
    int allow_summon;
    if (!me && !(me = this_player())) return 0;
    switch(what)
    {
    case "on":
	allow_summon = 1;
	break;
    case "off":
	allow_summon = 0;
	break;
    default:
	allow_summon = !(me -> query(PLR_ALLOW_SUMMON));
    }

    me->set(allow_summon ? PLR_ALLOW_SUMMON : PLR_PREVENT_SUMMON);
    me->tell_me(sprintf(
	"Now you %s be summoned easily.", (allow_summon ? "can" : "cannot")));
    return 1;
}
