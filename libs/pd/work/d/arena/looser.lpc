#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("The vanquished room.");
    set_long("Being defeated is never easy.  What happened?  How "
      "did your opponent get the upper hand?  You know many "
      "have passed through this room before you and many more "
      "shall pass after you have gone.\n\n"
      "Leave knowing you have shamed the generations of "
      "gladiators that have past before.");
    set_exits( ([ "out" : "/d/arena/bet" ]) );
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no teleport" : 1,
	"night light" : 2 ]) );
}

void init() {
    ::init();
    add_action("out","out");
}

int out(string str) {
    if(this_player()->query_hp() < 10)
	this_player()->set_hp(10);
    // stop bleeding wounds to prevent free kills
    if (this_player()->query_bleeding()) 
	this_player()->set_bleeding(0);
    return 0;
}
