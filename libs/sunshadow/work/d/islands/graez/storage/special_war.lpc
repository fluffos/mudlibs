#include <std.h>
#include "../graez.h"

inherit ROOM;


string faction_name;

void create() {
    ::create();
    set_name("special war room");
    set_short("special war room");
    set_long("This is LoKis special war room \n");

}


int something_died(int rank, int faction){
        tell_room(ETP,"Somthing Died...\n");
        tell_room(ETP,"It was a "+rank+" from "+faction+"...\n");
}

