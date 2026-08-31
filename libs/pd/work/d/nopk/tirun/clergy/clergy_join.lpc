#include <std.h>
#include <tirun.h>
inherit ROOM;
void create()
{
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"light"       : 2,
	"night light" : 2]) );
    set_short("The holy place of the Clergy");
    set_long("This temple was created as the holy place of the Clergy. Clergy all "
      "come here until they choose their path in life. Within this hall, Clergy "
      "of all beliefs are able to put aside their battles and train together, "
      "though this unity does not last once they leave the temple. Those newbie "
      "adventurerers who have not chosen a class can <become clergy> here, though "
      "you are recommended to <preview> first.");
    set_exits ( ([ "out" : ROOMS "ehonin4",
	"south": ROOMS "clergy_hall" ]) );
}
void reset()
{
    if (!present("trainer"))
	new(MOB "clergy_t")->move(this_object());
}
int preview() {
    if((string)this_player()->query_class() != "child") {
	write("This is not for you.\n");
	return 1;
    }
    say(this_player()->query_cap_name()+" seeks to learn about fighter.",
      this_player());
    write("Welcome, child!");
    write("Clergy are those people that believe in dedication of their "
      "lives to religion and to their holy, or unholy, beliefs.  The "
      "only uniting factor between all Clergy is that they are completely "
      "dedicated to their faith.  To become a clergy, type <become clergy> "
      "and strike out now and find your path in life, go and find the hall "
      "of the Cleric, the hall of the Druid, the hall of the Monk, or the "
      "hall of the Kataan.");
    return 1;
}
int go_east() {
    if (this_player()->query_class() != "clergy" && !wizardp(this_player()))
    { write("You cannot enter this place."); return 1; }
    return 0;
}
void init() {
    ::init();
    add_action("preview", "preview");
    add_action("go_east", "south");
}
