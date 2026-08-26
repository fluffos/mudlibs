//Main Street 5
//Coded by Layertes
//12/18/95

#include <std.h>
#include "/d/ruindar/inherit/laydef.h"

inherit ROOM;

int x = 0;

void init() {
    ::init();
    add_action("get","get");
}


void create() {
    ::create();
    set_property("light", 1);
    set_property("outdoors", 2);
    set_short("Main Street");
    set_long(
@TEXT
    Main street comes to an end at the low wall that surrounds the
village. The grass is taller here than in the rest of the village, it
grows wild and untamed and it's likely that not many people travel
here.
TEXT
    );
    set_exits( 
      ({
      LAYDIR + "main4"
    }),
      ({
      "west"

    }) );

    set_items ( ([
      "wall":"There is a hole in the wall where it looks as if the villagers were trying to install another gate.",
      "hole":"It may be big enough for a person, though it is filled with gray ash.",
      "grass":"It is tall, wild, and untamed.",
      "end":"You are at a dead end.",
    ]) );
}

int get(string ash) {
    if(x==1) {
        notify_fail("There is no more left.\n");
	write("You can't get that.");
	return 0;
    }
    x = 1;
    write("You take some of the ash.");
    new(OBJDIR+"ash")->move(this_player());
    return 1;
}
