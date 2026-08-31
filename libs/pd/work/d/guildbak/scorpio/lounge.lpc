#include <std.h>
#include <guild.h>

inherit ROOM;

void create() {
    ::create();
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );
    set_long("You have entered the Scorpio lounge. This is "
      "the place where members of Scorpio can buy food "
      "drinks, sit back and hang out. Just south of here "
      "is are the barracks, where members of Scorpio can "
      "sleep. You hear a lot of talking and laughing, and "
      "the strong smell of alcohol lingers in the air.");
    set_name("Scorpio Lounge");
    set_short("The lounge of the Scorpio");
    set_exits((["up":SCORPIO"treasury","south":SCORPIO"barracks",]));
}

void reset() {
    ::reset();
    if(!present("barkeeper")) 
        new(SCORPIO"barkeeper")->move(this_object());
}

