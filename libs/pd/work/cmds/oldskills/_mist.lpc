#include <std.h>
#include <daemons.h>

inherit DAEMON;

int spell();
int cast_mist(object, object *);
int end_mist(object);

int
cmd_mist(string str)
{
    if (!spell())
	return notify_fail("What?\n");

    if (this_player()->query_disable())
	return notify_fail("You are busy.\n");

    if (this_player()->query_mp() < 50)
	return notify_fail("Your magic powers are exhausted.\n");

    if (environment(this_player())->query_property("no magic"))
	return notify_fail("A mysterious force prevents you from casting this spell.\n");

    this_player()->add_mp(-30 - random(50));
    write("A steamy mist forms around you...");
    message("info", "A mist slowly starts to form around "+this_player()->query_cap_name()+"!",
      environment(this_player()), this_player());
    this_player()->set_magic_round();
    this_player()->set_disable();

    call_out("cast_mist", 1, environment(this_player()), all_inventory(environment(this_player())));

    return 1;
}

int
cast_mist(object env, object *all)
{
    int count = 0, i= sizeof(all);
    while(i--) {
	if (all[i] == this_object())
	    continue;
	if (all[i]->query_invis() && !wizardp(all[i])) {
	    if (present(all[i], env))
		count++;
	    else
		switch(random(3) + 1) {
	    case 1:
		message("info", "A shadow trys to outrun the mist but is still seen.", env);
		break;
	    case 2:
		break;
	    case 3:
		message("info", "A shadow runs out from the mist!", env);
		break;
	    }
	}
    }
    switch(count) {
    case 0:
	break;
    case 1:
	write("In the mist there appears to be a faint shadow...");
	break;
    default:
	write("There are several clear shadows in the mist!");
	break;
    }
    call_out("end_mist", 2, env);
}

int
end_mist(object env)
{
    message("info", "The mist clears...", env);
}

void
help()
{
    write("Syntax: <mist>\n"
      "This conjuring spell creates a mist in your area, allowing you to detect "
      "what may be hiding in the shadows...");
}

int
spell()
{
    if (this_player()->query_class() == "mage" && this_player()->query_level() >= 10)
	return 1;
    return 0;
}
