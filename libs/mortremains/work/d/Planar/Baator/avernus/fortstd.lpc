#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("short","Halls of the Iron Fortress");
    set ("long", @EndText
You are in the halls of a great iron fortress. Every one of the gigantic 
walls, ceilings, floors and doors are solid iron. The only light is from
iron torches set in iron sconces in the iron walls.
EndText
    );
}
