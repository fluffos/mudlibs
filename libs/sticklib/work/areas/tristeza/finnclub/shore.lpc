#include <room.h>
#include "../DEFS.h"

void
create_room()
{
    set_short("Lake shore");
    set_long(
      "You have mysteriously arrived into a shore of a Finnish lake in the \
middle of summer. The sun shines brightly and birds are singing. \
The water seems to be warm and clean. You notice a large wooden \
platform, about one metre high, to the north.");
    set_exits(([
	"north"	: CITY_PATH+"finnclub/dance_hall",
	"west"	: CITY_PATH+"finnclub/dressing"
      ]));

    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);
    set_commands(([
	"swim"	: "swim",
	"west"	: "west"
      ]));
    /* Not in city! This is in Finland, behind a magical teleport...
       set(IN_CITY);
       */
    set(NO_PK);
}

status
west()
{
    if (!this_player()) return 0;
    this_player()->tell_me("You step through a magical portal.");
    this_player()->move_player("west through a magical portal",
      CITY_PATH+"finnclub/dressing");
    return 1;
}

swim(str)
{
    int i;
    object ob;

    if(str) return 0;

    write("Ok. You swim for a while...\n");
    say(this_player()->query_name() + " goes swimming.\n");

    if (!present("sauna_sweat",this_player())) {
	i = random(3);

	if (i==0) this_player()->tell_me("Mmmm...quite refreshing!");
	if (i==1) this_player()->tell_me("You float around in the water a while\
 and relax...");
	if (i==2) this_player()->tell_me("You feel very clean and happy after\
 the bath.");
    } else {
	this_player()->tell_me("You wash away the dirt and sweat. Now you feel\
 really clean!");
	destruct(present("sauna_sweat",this_player()));
    }

    /* Cures the feet rash, if it isn't too developed already */
    if ((ob = present("feet_rash", this_player())))
	if ((int) ob->query_incubation() > 0)
	    destruct(ob);

	/* Wash away sewage */
    if ((ob = present("sewage", this_player())))
    {
	this_player()->tell_me("All the sewage is washed away, and you\
 finally feel clean again.");
	destruct(ob);
    }

    /* This does not wash Sunburn's flames off. They are magical. */
    /* Tell the player. */
    if ((ob = present("on_fire", this_player())))
    {
	this_player()->tell_me("The magical flames do not go \
out in water!");
    }

    return 1;
}
