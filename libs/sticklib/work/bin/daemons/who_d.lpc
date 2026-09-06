/*
**  /bin/daemons/who_d.c  - Tamarindo 1/1999
**
**  Inspired by channel_d.c coded by Graah & others at StickMUD.
**
*/

#include "/sys/interactive_info.h"

#include <mud_name.h>
#include <room_defs.h>
#include <coder_levels.h>
#include <invis_levels.h>

#define CAN_SEE_INVIS 21
#define HEAD1 "\n ___________________________________________________________________________"
#define HEAD2 "/\\__________________________________________________________________________\\"
#define HEAD3 "\\                                                                          \\"
#define FOOT "\\/__________________________________________________________________________/"

nomask int sort_em(object ob1, object ob2)
{
    int x1, x2;

    if (!objectp(ob2)) return 1;
    if (!objectp(ob1)) return -1;

    x1 = (int)ob1->query_coder_level();
    x2 = (int)ob2->query_coder_level();
    if (x1 < x2) return 1;
    if (x1 > x2) return -1;

    x1 = (int)ob1->query_level();
    x2 = (int)ob2->query_level();
    if (x1 < x2) return 1;
    if (x1 > x2) return -1;

    return 0;
}

nomask string *who_list(object me, object *who)
{
    string *who_list, tmp, level_field, name_field, title_field, status_field;
    object *who_member;
    int i, num, il, rc, me_coder, me_level, me_light, me_invis, coder_level;
    status isolated;

    who_member = ({});
    who = sort_array(who, #'sort_em, this_object());

    if (me && environment(me))
	isolated = (status)environment(me)->query(ROOM_ISOLATED);
    else
	isolated = 0;

    if (!isolated)
    {
	for(i = 0; i < sizeof(who); i++)
	{
	    if (who[i])
		who_member += ({ who[i] });
	}
    }
    else
	who_member = ({ me });

    who_list = ({ HEAD1, HEAD2, HEAD3 });

    tmp = sprintf(" |%^bold%^%^yellow%^%|73s%^reset%^|\n |%73s|\n |%|73s|\n |%73s|", 
      "-{-----   "+efun::implode(explode(MUD_NAME, ""), "  ")+"   -----}-",
      " ",
      "Local time is "+ctime(time()),
      " "
    );

    who_list += ({ tmp });

    me_coder = (int)me->query_coder_level();
    me_level = (int)me->query_level();
    me_invis = (int)me->query_invis();
    me_light = (member(({ "troll", "dark elf" }),
	(string)me->query_race()) != -1) ? 0 : 1;

    num = 0;

    for (i = 0; i < sizeof(who_member); i++)
    {
	il = (int)who_member[i]->query_invis();
	rc = (member(({ "troll", "dark elf" }),
	    (string)who_member[i]->query_race()) != -1) ? 0 : 1;

	// Don't show trolls and dark elves to other races on list to non-coders, and vice versa.

	if (me_light != rc && !me_coder) continue;

	// Don't show us if invis to people 10 levels below or more

	/*
		if (il && (int)who_member[i]->query_level() - 10 > me_level && !me_coder)
		    continue;

	*/
	/*
		if (me_coder || (!environment(who_member[i])->query(ROOM_ISOLATED)
		    && (!il || (il < IL_TOTALLY_INVISIBLE && me_level > 21))))
	*/
	if (who_member[i] == me || environment(who_member[i]) &&
	  !environment(who_member[i])->query(ROOM_ISOLATED) &&
	  (me_coder || !il) ||
	  ((me_level > CAN_SEE_INVIS) && (il < IL_TOTALLY_INVISIBLE)))
	{
	    if (!(coder_level = (int)who_member[i]->query_coder_level()))
		level_field = sprintf("%d", (int)who_member[i]->query_level());
	    else if (coder_level < 0)
		level_field = "Testchar";
	    else if (coder_level < LVL_APPRENTICE)
		level_field = "Divided";
	    else if (coder_level < LVL_NOVICE)
		level_field = "Apprentice";
	    else if (coder_level < LVL_CODER)
		level_field = "Novice Wizard";
	    else if (coder_level < LVL_SENIOR)
		level_field = "Wizard";
	    else if (coder_level < LVL_ELDER)
		level_field = "Senior Wizard";
	    else if (coder_level < LVL_ARCH)
		level_field = "Elder Wizard";
	    else if (coder_level < LVL_COADMIN)
		level_field = capitalize((string)who_member[i]->query_kingdom()) + " Arch";
	    else if (coder_level < LVL_ADMIN)
		level_field = "Co-Admin";
	    else
		level_field = "Admin";

	    name_field = capitalize(who_member[i]->query_real_name());

	    if (name_field == "Logon")
		continue;


	    if (il >= IL_TOTALLY_INVISIBLE)
		name_field = "<" + name_field + ">";
	    else if (il)
		name_field = "(" + name_field + ")";

	    title_field = (string)who_member[i]->query_title();

	    if (sizeof(title_field) > 33)
		title_field = title_field[0..29] + "...";

	    name_field += " " + title_field;

	    if ((int)who_member[i]->query_ghost())
		status_field = "R.I.P.";
	    if ((int)who_member[i]->query_frog())
		status_field = "Froggy";
	    else if (interactive_info(who_member[i], II_IDLE) > 300)
		status_field = "Idle";
	    else if (me_coder && (int)who_member[i]->is_fighting())
		status_field = "Fighting";
	    else if (interactive_info(who_member[i], II_EDITING))
		status_field = "Editing";
	    else
		status_field = "";

	    num++;

	    tmp = sprintf(" | %14s %-47s %-8s |", level_field, name_field, status_field);

	    who_list += ({ tmp });
	}
    }

    tmp = "Total of " + num + " gamer"+((num>1) ? "s": "")+" visible to you.";
    tmp = sprintf(" |%73s|\n_\\ %-72s \\", " ",tmp);

    who_list += ({ tmp });
    who_list += ({ FOOT });

    return who_list;
}

nomask string *who_quick(object me, object *who)
{
    string *who_list, name_field;
    object *who_member;
    int i, num, il, rc, me_coder, me_level, me_invis, me_light;
    status isolated;

    who_member = ({});
    who_list = ({});

    if (me && environment(me))
	isolated = (status)environment(me)->query(ROOM_ISOLATED);
    else
	isolated = 0;

    if (!isolated)
    {
	for(i = 0; i < sizeof(who); i++)
	{
	    if (who[i])
		who_member += ({ who[i] });
	}
    }
    else
	who_member = ({ me });

    me_coder = (int)me->query_coder_level();
    me_level = (int)me->query_level();
    me_invis = (int)me->query_invis();
    me_light = (member(({ "troll", "dark elf" }),
	(string)me->query_race()) != -1) ? 0 : 1;

    for (i = 0; i < sizeof(who_member); i++)
    {
	il = (int)who_member[i]->query_invis();
	rc = (member(({ "troll", "dark elf" }),
	    (string)who_member[i]->query_race()) != -1) ? 0 : 1;

	// Don't show trolls and dark elves to other races on list to non-coders, and vice versa.

	if (me_light != rc && !me_coder) continue;

	// Don't show us if invis to people 10 levels below or more

	if (il && (int)who_member[i]->query_level() - 10 > me_level && !me_coder)
	    continue;

	if (me_coder || (!environment(who_member[i])->query(ROOM_ISOLATED)
	    && (!il || (il < IL_TOTALLY_INVISIBLE && me_level > 21))))
	{
	    name_field = capitalize(who_member[i]->query_real_name());

	    if (name_field == "Logon")
		continue;

	    if (il >= IL_TOTALLY_INVISIBLE)
		name_field = "<" + name_field + ">";
	    else if (il)
		name_field = "(" + name_field + ")";

	    who_list += ({ name_field });
	}
    }

    return who_list;
}
