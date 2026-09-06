#include <daemons.h>
#include <generic_rooms.h>

#define TP this_player()

int i;
object *what, purgatory;
string *who, *earth, *fire, *wind, *water, *drifters, *linkdead;

status filter_earth(object ob);
status filter_fire(object ob);
status filter_wind(object ob);
status filter_water(object ob);
status filter_drifter(object ob);

nomask status who3_cmd(string arg)
{
    if (!arg)
    {
	TP->more((string *)WHO_D->who_list(TP, users()));
	return 1;
    }

    if (member(({"q", "k", "l", "r", "c", "g", "d"}), arg) == -1)
	return notify_fail("Syntax: "+query_verb()+" [ q | k | l | r | c | g | d ]\n"), 0;

    switch (arg)
    {
    case "q":
	who = (string *)WHO_D->who_quick(TP, users()); 
	TP->tell_me(sprintf("\nTotal of %d players visible to you:\n\n%s.", 
	    sizeof(who), 
	    implode(who, ", ", " and ")));
	break;
    case "r":
	call_other(do_find_object("/bin/pub/_who_old"), "who_cmd", "r");
	break;
    case "c":
	call_other(do_find_object("/bin/pub/_who_old"), "who_cmd", "c");
	break;
    case "g":
	call_other(do_find_object("/bin/pub/_who_old"), "who_cmd", "g");
	break;
    case "d":
	call_other(do_find_object("/bin/pub/_who_old"), "who_cmd", "d");
	break;
    case "k":
	earth = filter(users(), #'filter_earth, this_object());
	fire = filter(users(), #'filter_fire, this_object());
	wind = filter(users(), #'filter_wind, this_object());
	water = filter(users(), #'filter_water, this_object());
	drifters = filter(users(), #'filter_drifter, this_object());

	if (sizeof(earth))
	    TP->tell_me("\nEarth: "+
	      implode((string *)WHO_D->who_quick(TP, earth), ", ", " and "));
	if (sizeof(fire))
	    TP->tell_me("\n Fire: "+
	      implode((string *)WHO_D->who_quick(TP, fire), ", ", " and "));
	if (sizeof(wind))
	    TP->tell_me("\n Wind: "+
	      implode((string *)WHO_D->who_quick(TP, wind), ", ", " and "));
	if (sizeof(water))
	    TP->tell_me("\nWater: "+
	      implode((string *)WHO_D->who_quick(TP, water), ", ", " and "));
	if (sizeof(drifters))
	    TP->tell_me("\n None: "+
	      implode((string *)WHO_D->who_quick(TP, drifters), ", ", " and "));
	break;
    case "l":
	linkdead = ({});

	if (purgatory = find_object(GENERIC_ROOM_PURGATORY));
	{
	    what = all_inventory(purgatory);

	    for (i =  0; i < sizeof(what); i++)
		if (object_name(what[i])[0..9] == "lib/player")
		    linkdead += ({ capitalize(what[i]->query_real_name()) });
	}

	if (sizeof(linkdead))
	    TP->tell_me("Linkdead: "+implode(linkdead, ", ", " and "));
	else
	    TP->tell_me("No linkdead players.");
    }         
    return 1;
}

status filter_earth(object ob)
{
    return (int)ob->query_kingdom("earth");
}

status filter_fire(object ob)
{
    return (int)ob->query_kingdom("fire");
}

status filter_wind(object ob)
{
    return (int)ob->query_kingdom("wind");
}

status filter_water(object ob)
{
    return (int)ob->query_kingdom("water");
}

status filter_drifter(object ob)
{
    return (member(({ "fire", "earth", "water", "wind" }),
	ob->query_kingdom()) == -1) ? 1 : 0;
}
