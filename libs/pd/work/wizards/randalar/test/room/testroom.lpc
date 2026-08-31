#include <locations.h>
//      from the Nightmare mudlib
//      an example workroom for new immortals

#include <std.h>
#include "../std/mydefs.h"

inherit ROOM;

#if 0 
object coon; // Testing on making a unique monster
#else
object *coons = ({ });
#endif

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The workroom of a new immortal");
    set_night_long("It is night outside.\nA new immortal works here.\n");
    set_day_long("It is day outside.\nA new immortal works here.\n");
    set_exits( ([
      "square" : SQUARE_LOC,
      "hall" : "/d/standard/adv_main",
    ]) );
    set_smell("default", "It smells like a new immortal in here.");
    set_listen("default", "You hear the sounds of code creation.");
}

void reset()
{
    ::reset(); // testing an idea of populating multiple monsters
#if 0 // Don't need this right now
    while (!present("raccoon 5", this_object()))
        new(TESTMON"/coon")->move(this_object());

    if (!coon)
    {
        coon = new(TESTMON"/coon");
        coon->move(this_object());
    }
#endif

#if 0
    if (sizeof(coons) < 5)
    // This will populate the first set of coons
        while (sizeof(coons) < 5)
        {
            object tempcoon;
            tempcoon = new(TESTMON"/coon");
            tempcoon->move(this_object());
            coons += ({ tempcoon }); // add him to the array
        }
    // This will run through the array. The first run
    // should add no more coons. Subsequent runs, if there
    // is a missing coon (dested or killed), it should add
    // a new coon.  This ensures no population explosion 
    // for wandering monsters. --Randalar
    for (int i = 0; i < 5; i++)
    {
        if (!coons[i])
        {
            coons[i] = new(TESTMON"/coon");
            coons[i]->move(this_object());
        }
    }
#endif
    for (int i = sizeof(children(TESTMON"/coon")); i < 6; i++)
        new(TESTMON"/coon")->move(this_object());
}
