
#include <cmd.h>
#include <daemons.h>
#include <gender.h>

// Public command: levels
// Written by Graah, 27-Sep-96.
// Syntax:
//   levels
//   levels lord
//   levels troll
//   levels darkelf  (etc.)

varargs nomask status
levels_cmd(string s, object me)
{
    string *n, *r;
    int i, rn;

    if (!me && !(me = this_player())) return 0;

    r = (string *)LEVELS_D->query_races();

    // No liches yet...
    r -= ({ "lich" });

    if (s && s != "lord" &&
      (rn = member(r, s)) == -1)
    {
	notify_fail("Usage: levels [lord, " + implode(r, ", ", " or ") + "].\n");
	return 0;
    }

    n = ({
      sprintf(" %3s. %28s %28s %12s", "Lvl", "Male Title", "Female Title",
	"Experience")
    });

    n += ({
      "============================================================================="
    });

    if (s != "lord")
	for (i = 1; i <= 24; i++)
	    n += ({ sprintf(" %3d. %28s %28s %12d",
		i,
		(string)LEVELS_D->query_title_for_level(i, G_MALE, s),
		(string)LEVELS_D->query_title_for_level(i, G_FEMALE, s),
		(int)LEVELS_D->query_exp_for_level(i - 1))
	    });
    else
	for (i = 25; i <= 121; i++)
	    if (i < 63)
		n += ({ sprintf(" %3d. %28s %28s %12d",
		    i,
		    (string)LEVELS_D->query_pretitle(0, i - 24, G_MALE),
		    (string)LEVELS_D->query_pretitle(0, i - 24, G_FEMALE),
		    (int)LEVELS_D->query_exp_for_level(i - 1))
		});
	    else
		n += ({ sprintf(" %3d. %28s %28s %12d(%d)",
		    i,
		    (string)LEVELS_D->query_pretitle(0, i - 24, G_MALE),
		    (string)LEVELS_D->query_pretitle(0, i - 24, G_FEMALE),
		    (int)LEVELS_D->query_exp_for_super_level(i - 1),
		    (int)LEVELS_D->query_exp_times_for_level(i - 1)) });

    TP->more(n);

    return 1;
}
