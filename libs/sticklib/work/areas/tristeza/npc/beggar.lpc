/* Official City Beggar */

#include <npc.h>

#include <disease_defs.h>

void
create_monster()
{
    object disease;

    set_name("beggar");
    set_level(2 + random(4));
    set_money(random(10) * level);
    set_alignment(query_level() * 50);
    set_race("human");
    set_gender(1 + random(2));
    set_long("A really filthy looking poor beggar.");
    set_random_pick(7);
    set_wander(6);

    if(random(100) < 30) {
	disease = clone_object(GENERIC_DISEASE_PLAGUE);
	move_object(disease,this_object());
    }
}

void
give_object_by(object who, mixed what)
{
    int i;

    if (intp(what))
    {
	if (who)
	    environment()->tell_here("Beggar croaks: Thank you, great " +
	      (string)who->query_name() + ", may Boccob bless you!");

	/* Give some good alignment. However, also rise the
	   beggar's alignment! This way it is not too good to
	   just give them money, then kill them. */
	i = what / 10;
	if (i > 500) i = 500;
	who->add_alignment(i);
	this_object()->add_alignment(i);

	return;
    }

    if (!objectp(what)) return;

    if (what->is_drink())
    {
	for (i = 0; i < 6; i++)
	    if (what) init_command("drink " + (string)what->query_name());
	for (i = 0; i < 6; i++)
	    if (what) init_command("quaff " + (string)what->query_name());
	init_command("drop bottle");
	return;
    }

    if (what->is_food())
    {
	for (i = 0; i < 6; i++)
	    if (what) init_command("eat " + (string)what->query_name());
	return;
    }

    init_command("drop " + (string)what->query_name());
    return;
}
