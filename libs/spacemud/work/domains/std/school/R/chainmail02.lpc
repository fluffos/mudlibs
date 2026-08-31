#include "../school.h";
inherit INDOOR_ROOM;

void setup(){
    set_brief("Extras for basic armour");
    set_long(@MAY

Starting with chainmail, as in previous room:

Within setup(), add custom wear messages
Use set_resist() for strength adjustment against different damage types.


    set_resist("slashing", 2); // a little better against blades
    set_wearmsg( "$N $vput on a $o." );
    set_slot("torso");
}

MAY
    );
    set_exits( ([
	"finish" : R "armoury",
	"backward" : "chainmail02",
      ]) );
    set_objects( ([
    "/domains/std/armour/chainmail" : 1,
      ]) );
}
