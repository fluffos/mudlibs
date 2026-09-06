#include <room.h>

#include <areas.h>
#include <generic_rooms.h>
#include <generic_items.h>
#include <mud_name.h>

#define RACE_ROOM "/room/path"

void
create_room()
{
    set_short("Hall of Races");
    set_long("This large hall is brightly lit by magical light. You feel\
 presence of Adminstrational Magic; this is the place where the players may\
 choose their race. There is a sign on the wall.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(IN_CITY);
    set(NO_PK);
    set_exits(([
	"south"	: AREA_TRISTEZA+"virtual/S8_6",
	"north" : RACE_ROOM,
	"west"	: GENERIC_ROOM_CHURCH
      ]));
    set_items(([ "sign" :
	"It's made of pure magic. But perhaps you can read it?"
      ]));
    set_commands(([ "choose" : "choose_cmd",
	"holocaust" : "disallow",
	"purify" : "disallow" ]));
}

status
read_cmd(string s)
{
    if (s != "sign" && s != "more") return notify_fail("Read what?\n"), 0;
    tell_here((string) this_player() -> query_name() + " reads the sign.", this_player());
    if (s == "sign") {
	this_player() -> tell_me(
	  " \t\tThe Races of " MUD_NAME "\n\n\
\tHumans\t\t-\tThe most common and flexible\n\
\tElves\t\t-\tThe mightiest fairy magicians\n\
\tDwarves\t\t-\tStrong, tough bearded folk\n\
\tHobbits\t\t-\tThe quick and stealthy halflings\n\
\tHalf-Orcs\t-\tThe toughest and strongest warriors\n\
\tTrolls\t\t-\tHideous monsters of darkness\n\
\tDark Elves\t\tEvil elves, outcasts of the surface world\n\n\
\tType 'read more' to get more information.\n\
\tThink carefully and read helps before choosing a race!");
	return 1;
    }
    this_player() -> tell_me("Before choosing your race, you really should\
 think about it: only first level characters can change their race freely. You\
 should also read all documents about the races ('help races', 'help elves' etc.)\
 before choosing. Other players might also have suggestions about which race to\
 choose. All the races have their good points, but all have some weaknesses\
 too.\n\nWhen you think you have chosen your race and are absolutely sure\
 about it, type 'choose [name of the race]' to begin the transformation.");
    return 1;
}

status
choose_cmd(string arg)
{
    object trob;
    string r;

    if (!arg) return notify_fail("What did you want to choose?\n"), 0;
    arg = lower_case(arg);
    if (member(({ "human", "elf", "dark elf", "dwarf",
	  "hobbit", "half-orc", "troll" }), arg) == -1)
	return
	notify_fail("Hmm, perhaps " + arg + " is not one of possible\
 choices.\nTry reading the sign first.\n"), 0;

    r = (string)this_player()->query_race();

    if (arg == r)
    {
	this_player()->tell_me("Hey, you already are a member of that race!");
	return 1;
    }

    if (r
      && ((((int)this_player() -> query_level() > 1)
	  || ((int) this_player() -> query_ep() > 1000))))
    {
	this_player()->tell_me("A voice whispers: You have already chosen \
your race.");
	return 1;
    }

    log_file("race_log", ctime(time()) + ": " +
      capitalize((string)this_player()->query_real_name()) + ": " +
      (r ? r : "*human*") + " -> " + arg + "\n");

    if ( trob = clone_object(GENERIC_RACE_TRANSFORMER))
    {
	this_player()->tell_me("The physical world dissolves around you.");
	this_player() -> move_player("X", trob);
	if (!trob -> transform(this_player(), arg)) {
	    this_player() -> tell_me("Ouch. Something went wrong. Notify \
(co)admins about this.");
	    this_player() -> move_player("foo", this_object());
	}
    }
    else this_player()->tell_me("Error - Notify a co-admin please.");
    return 1;
}

status
disallow(string arg)
{
    this_player()->tell_me("Tim the Enchanter glares at you.");
    return 1;
}
