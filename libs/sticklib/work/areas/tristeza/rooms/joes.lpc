// EAT AT JOE'S!

#include <room.h>
#include <areas.h>

object ob;

void
create_room()
{
    set_short("Joe's");
    set_long("This is Joe's restaurant. So you popped in for \
dinner? Wait here for Joe. Or exit this place to the south.");

    set_light_level(LT_LIGHTS);
    set(NO_PK);
    set(IN_CITY);
    set(ROOM_WD, WD_INDOORS);

    add_exit("south", AREA_TRISTEZA + "virtual/S2_4");

    this_object()->reset_room();
}

void
reset_room()
{
    if (ob) return;

    ob = clone_object(AREA_TRISTEZA + "obj/joe");
    ob->start_move();
}

void
init_room()
{
    call_out("eat", 1);
}

void
eat()
{
    object *inv, s;
    int i;

    if (!present("joe the bear", this_object())) return;

    call_other(AREA_TRISTEZA + "rooms/joes_stomach", "???");
    s = find_object(AREA_TRISTEZA + "rooms/joes_stomach");
    if (!s) return;

    inv = all_inventory(this_object());

    for (i = sizeof(inv) - 1; i >= 0; i--)
    {
	if ((inv[i] != ob)
	  && living(inv[i]) &&
	  !inv[i]->is_npc())
	{
	    inv[i]->tell_me("\nSuddenly, Joe the Bear grabs you, \
swallows you whole in a one big gulp, and burps loudly!");
	    tell_here(":Joe the Bear swallows %<me.capname>% whole!",
	      0,0,({inv[i]}),inv[i],0,0);

	    move_object(inv[i], s);

	    s->tell_here(":%<me.capname>% falls into this place!",
	      0,0,({inv[i]}),inv[i],0,0);
	}
    }
}
