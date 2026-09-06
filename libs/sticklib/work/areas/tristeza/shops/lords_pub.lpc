#include <pub.h>

#include <areas.h>
#include <room_defs.h>
#include <city_name.h>
#include <generic_items.h>

#define	LORDLIST "/log/LORD_LIST"

void
init_drinks()
{
    drinks = ({ ({ "beer" }), "bottle", "Bottle of Royal beer", 2, 0, 100,
      "Royal beer is brewed by the Royal Brewery of " CITY_NAME ". It is the best known beer,\
 and the most expensive too.", "Mmmmaaaahhhh! Very good!",
      ({ "special" }), "bottle", "Special of the Lords", 12, 12, 450,
      "Take some beer, tabasco sauce, firebreather, juice squashed from a genuine\
 Finnish Vihta, one herring, icky green stuff from the cauldron of the thieve's\
 guild and Kalevalan cow shit, mix them and you have a Special of the Lords.\
 The amazing thing is that some people actually drink this stuff!",
      "You feel like someone had just crushed your skull with a bar of gold wrapped\
 in lemon peels!", ({ "brandy", "bottle of brandy" }), "bottle",
      "Bottle of Lordly Brandy", 15, 25, 900, "Lordly Brandy is carefully distilled\
 from ingredients from the South, kept in oak barrels and mixed. The result is\
 quite shocking. Well, perhaps they learn to do it some day.",
      "A shock wave runs through your body", ({ "firebreather", "fire", "breather" }),
      "bottle", "Firebreather", 17, 30, 1500, "This liquid in a clear bottle seems\
 to be water. But you guess that it isn't...", "AAAAARGHH! Flames burst\
 from your mouth and nostrils!" });
}

string
query_default_drink()
{
    return "firebreather";
}

void
extra_handle_drink(object drink)
{
    if (drink) drink -> set_type(1);
}

int
pub_open()
{
    if ((int) this_player() -> query_crime_level() > 1) return
	notify_fail("We do not trade with criminals!\n"), 0;
    if (this_player() && !this_player() -> query_lord()) return
	notify_fail("How dare you! A non-lord!\n"), 0;
    return 1;
}

void
create_pub()
{
    object bboard;
    set_short("Lord's Pub");
    set_long("You are in the Lord's Pub, with the following drinks\
 available:\n\n" + list_drinks(0) + "\nThe Lord's Guild Hall is to the south.\
 The 'fill' command is now also available here (check Potato Nosed Ogre for\
 infomation).\nThere's lord's top 30 list here, 'read list' to read it.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set_exits(([
	"northeast" : AREA_TRISTEZA+"virtual/S6_8",
	"south"	: AREA_TRISTEZA+"rooms/lords_guild",
	"west"	: AREA_TRISTEZA+"shops/lords_shop"
      ]));
    set_items(([ 
	({ "list", "top", "top lords", "top ladies", "list of top lords",
	  "list of top ladies", "top list" }) :
	"It's the list of top lords and ladies. Maybe you should read it?"
      ]));
    set(NO_PK);
    set(IN_CITY);
    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, 0, "lord_pub_board", 0 }),
      }), 0, 1);
}

int read_cmd(string str)
{
    if (!str || str != "list")
	return 0;

    say(capitalize(this_player()->query_name())+" reads the "
      "top lords list.");
    return this_player()->more(LORDLIST), 1;
}

