#include <pub.h>

#include <areas.h>
#include <room_defs.h>
#include <drink_defs.h>

#include <generic_items.h>

#define	NATURE	nature()

object top_list, lord_list, newspaper;
int text_time;

void
init_drinks()
{
    drinks = ({ ({ "beer" }), "bottle", "Bottle of Ogre IV beer", 2, 1, 48,
      "The manufacturing of the legendary Ogre IV beer is only known to mr. Bar\
 Tender who owns the famous pub 'Potato-Nosed Ogre'. This bottle of brown\
 glass holds about one pint of the liquid.",
      "You drink a pint of Ogre IV. Aahhhhh! That feels good", ({ "special" }),
      "bottle", "Special of the house", 8, 9, 390, "This drink is a mix of wine,\
 beer and stronger alcoholic beverages. The bottle which holds it is made\
 of clear glass, so you can see the very strange rainbow-coloured liquid\
 inside.", "SLURP!??! A strange feeling goes through your head",
      ({ "vodka", "finlandia" }), "bottle", "Bottle of Finlandia Vodka", 10, 15,
      630, "This excellent vodka is delivered from the Land of the Midnight Sun,\
 Finland (also known as Kaleva), by the magical tele-summoning spells of mr.\
 Bar Tender of the Potato-Nosed Ogre pub.", "A smooth but strong taste!\
 Very good.", ({ "firebreather", "fire", "breather" }), "bottle",
      "Firebreather", 12, 22, 900, "This liquid in a clear bottle seems to be\
 water. But you guess that it is not...", "ARGHH! Your mouth and throat are\
 on flames" });
}

string
query_drink_obj_object_name()
{
    return DRINK_FILE;
}

string
query_default_drink()
{
    return "firebreather";
}

status
check_hours()
{
    int hour;
    if ((hour = (int) NATURE -> query_24_hour()) >= 4 && hour < 8)
	return 0;
    return 1;
}

int
pub_open()
{
    object ob;
    if (!(ob = present("bartender", this_object())))
	return notify_fail("You can't see the bartender.\n"), 0;
    if ((int) this_player() -> query_crime_level() > 1)
	return notify_fail((string) ob -> query_name()
	  + " tells you: We do not trade with criminals!\n"), 0;
    return check_hours();
}

int
check_open()
{
    if (pub_open()) return 1;
    if (!this_player()) return 0;
    if (!check_hours()) {
	this_player() -> tell_me("We are closing the place for the\
 night. Would you please leave.");
	this_player()->move_player("east", AREA_TRISTEZA+"virtual/S7_9");
    }
    return 0;
}

void
create_pub()
{
    set_short("The Potato-Nosed Ogre");
    set_long("You are in the most popular pub of the City, the Potato-Nosed\
 Ogre. These drinks are known to be the best:\n\n" + list_drinks(0) + "\nYou\
 can 'fill bag' (or any container) with firebreathers - " + "or with some other\
 drink: for example 'fill bag with beer'.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(IN_CITY);
    //	set(NO_PK);  //Needs to be PK so players can defend the keeper - Germ
    set(NO_PK);
    set_exits(([
	"north"	: AREA_TRISTEZA+"virtual/S6_8", 
	"east"	: AREA_TRISTEZA+"virtual/S7_9" 
      ]));
    add_object(GENERIC_PLAYER_LIST , 0, 1);
    add_object(GENERIC_LORD_LIST, 0, 1);
    add_object(GENERIC_NEWSPAPER, 0, 1);
    add_monster( ({ AREA_TRISTEZA+"npc/shopkeeper",
	({ "set_name", "bartender" }),
	({ "set_id", ({ "bartender", "keeper", "pub keeper" }) }),
	({ "set_short", "Bartender the pub keeper" }),
	({ "set_long",
	  "Bar Tender is the merry owner of the Potato-Nosed Ogre.  He is a thin,\
 tall man with a red nose. He keeps his pub open almost all day and night." }),
	({ "set_random_pick", 0 })
      }), "Bartender arrives.", 1 );
}

void
extra_purchase_msg()
{
    if (text_time < time()) {
	(AREA_TRISTEZA+"virtual/S6_8")->tell_here(
	  "You hear merry voices from the south entrance.");
	(AREA_TRISTEZA+"virtual/S7_9")->tell_here(
	  "You hear merry voices from the west entrance.");
	text_time = time() + 10;
    }
}

void
init_pub()
{
    if (!interactive(this_player()) && present("shopkeeper", this_object())
      && !this_player() -> query_ctrl() && !this_player()->id("shopkeeper")) {
	tell_here(
	  "Bar Tender says: No monsters allowed!\n\
Bar Tender throws " + (string) this_player() -> query_name() + " out.");
	this_player() -> move_player(0, AREA_TRISTEZA+"virtual/S6_8");
    }
}
