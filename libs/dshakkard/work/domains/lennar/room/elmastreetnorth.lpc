#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("North Elma Street");
    SetLong("This is a long north-south street that bisects Lennar. To the south is a large city square with a statue. To the north is a large mansion with guards patrolling the walls.");
    SetItems(([
        ({ "statue", "large statue" }) : "It's a large statue of a portly middle-aged man sitting on a throne. His face looks stern.",
      ]));
    SetExits(([
        "south" : "/domains/lennar/room/everettsquare",
	"north" : "/domains/lennarmanor/room/start",
      ]));

    SetClimate("indoors");

}
void init(){
    ::init();
}
