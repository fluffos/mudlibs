#include <std.h>
#include <tirun.h>
inherit ROOM;
int go_north();
void init() {
    ::init();
    add_action("go_up","up");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"light"       : 2,
	"night light" : 2 ]) );
    set("short", "Entrance of the Wanderer Hall");
    set("long", 
      "The Hall of Wanderers is decorated with ornate objects from all over "
      "the world.  The hall is mostly deserted, since wanderers like to be "
      "out having fun.  Young people visit here hoping to hear stories of "
      "the adventurous members.  Children may <preview> what it is like to be "
      "a wanderer.");
    set_items(([
	"hall" : "This is the single wanderer class hall.",
      ]));
    set_exits(
      (["south" : ROOMS"nwganthus1",
	"up" : "(: go_up :)" ]));
}
void reset()
{
    if (!present("trainer"))
	new(MOB "wanderer_t")->move(this_object());
}
int preview() {
    if((string)this_player()->query_class() != "child") {
	write("This is not for you.");
	return 1;
    }
    say(this_player()->query_cap_name()+" seeks to learn about wanderers.", this_player());
    write("Welcome, child!\n");
    write("Wanderers are those people who have chosen to spend the rest "
      "of their lives traveling and moving about. All wanderers have at least two "
      "things in common: their love of fun and pranks and their overwhelming "
      "wanderlust. Some wanderers choose to spend their time with others "
      "who wander about in groups, while others will travel alone from town "
      "to town telling jokes and entertaining peasants for a few coins. "
      "Wanderers are sometimes looked down upon because they have a "
      "tendancy towards theft.  To become a wanderer, type <become wanderer> "
      "and strike out now and find your path in life, go and find the hall "
      "of the Bard, the hall of the Gypsy, the hall of the Jester, "
      "or the hall of the Swashbuckler.");
    return 1;
}
int go_up() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
    } else
    if((string)this_player()->query_class() != "wanderer") {
	write("You are no wanderer!");
    say(this_player()->query_cap_name()+" attempts to enter the wanderer's sanctuary.", this_player());
	return 1;
    }
    this_player()->move_player(ROOMS"wanderer_hall", "through a passage of light.");
    return 1;
}
