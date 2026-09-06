
#include <treasure.h>
#define POISON_D "/guilds/thieves/poison_d"

status filled;
int strength;

void create_treasure()
{
    filled = 0;
    strength = 0;
    set_name("poison vial");
    set_short("A small, clear vial. (empty)");
    set_long("A small, see through vial.  Wonder what would go \
in here!");
    set_id( ({ "vial", "poison vial", "t_vial", "save_pvial" }) );
    set_weight(0);
    set_value(0);
}
query_thief_item() { return 1; }
status drop() { return 1; }
void init_treasure()
{
    add_action("apply_cmd","apply");
}
status apply_cmd(string what)
{
    string stuff, t_object;
    object p_object;

    if (!what)
    {
	notify_fail("Apply what to what?\n");
	return 0;
    }
    if (!filled)
    {
	notify_fail("The vial is empty, what did you plan \
on using?\n");
	return 0;
    }
    if (sscanf(what,"%s to %s",stuff, t_object) != 2)
    {
	if (stuff && stuff == "poison")
	{
	    notify_fail("Apply poison to what?\n");
	    return 0;
	}
	else
	{
	    notify_fail("Apply what to what?\n");
	    return 0;
	}
    }
    if (stuff != "poison")
    {
	notify_fail("Why would you apply " + stuff +
	  " to anything?\n");
	return 0;
    }
    if (!p_object = present(t_object,this_player()))
    {
	notify_fail("You don't seem to have any " +
	  t_object + ".\n");
	return 0;
    }
    this_player()->tell_me("Ok.  You apply the poison to " +
      p_object->query_name() + ".");
    environment(this_player())->tell_here(this_player()->query_name() +
      " applies a strange substance to " +
      p_object->query_name() + ".",this_player());
    POISON_D->add_poisoned_thing(p_object,strength);
    filled = 0;
    set_short("A small, clear vial (empty)");
    set_long("A small, clear, empty vial.");
    strength = 0;
    return 1;
}
status set_filled()
{
    if (filled) return 0;
    filled = 1;
    set_short("A small, clear vial (full)");
    set_long("A small vial containing some thick substance.");
    return 1;
}
status set_strength(int p_strength)
{
    if (p_strength < 0) p_strength = 0;
    strength = p_strength;
    return 1;
}

status query_filled()
{
    return filled;
}
status query_strength()
{
    return strength;
}
string
query_auto_load()
{
    return "/guilds/thieves/obj/p_vial:";
}


