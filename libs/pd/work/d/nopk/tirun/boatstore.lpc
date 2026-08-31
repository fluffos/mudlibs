#include <std.h>
#include <tirun.h>
inherit ROOM;
void create()
{
    ::create();
    set_short("John's Boat Store");
    set_long("John's Boat Shop.\n"
      "The shop is clean and tidy. John looks to be busy in the "
      "back of the store assembling boats. There is an assortment "
      "of large and small lumber stacked up against the wall. "
      "Torches on the wall light up the store. An old paper has been "
      "tacked to the wall.  There is a small hallway going north.");
    set_exits( ([ "out" : ROOMS "pier" ,
	"hall" : ROOMS "wand/swashbuckler/swashbuckler_join"]) );
    set_properties( ([ "light" : 2, "night light":2, "no attack":1,
	"no bump":1, "indoors":1]) );
}
int sign(string str) {
    if (!str) return 0;
    if (str != "paper" && str != "sign") return 0;
    write("John provides the following services:  \n");
    write("   <buy ship>    : New ships are 20,000.  You cannot buy a new \n"
      "                     ship if yours is sunk.");
    write("   <view status> : Tells you the current damage of your ship.");
    write("   <repair ship> : This repairs 5% damage that is inflicted \n"
      "                   on your ship.");
    write("   <rescue ship> : This will rescue your sunken ship.\n");
    write("   <set [describe]> : This will allow you to change the \n"
      "                      description of your ship.");
    return 1;
}
void init() {
    ::init();
    add_action("sign", "read");
}
void reset()
{
    if (!present("john"))
	new(MOB "john")->move(this_object());
}
