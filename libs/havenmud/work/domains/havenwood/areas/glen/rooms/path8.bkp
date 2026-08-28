#include <lib.h>
#include "path.h"
inherit LIB_ROOM;
static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("an earthen clearing");
    SetLong("This is a large earthen clearing on the east edge of "
               "the glen.  A large bonfire burns in the middle of the "
               "clearing and a very rundown shack stands at the edge "
               "of the clearing.  The ancient forest huddles up around "
               "the clearing, nearly enveloping it in darkness.");
    SetItems( ([({"large earthen clearing","earthen clearing","clearing"}) : 
                            "The clearing has been formed by a combination " 
                            "of heat from the fire and the shuffling of tiny " 
                            "gelfling feet.",
                 ({"rundown shack","shack"}) : 
                            "The shack is built of wood and seems about ready "
                            "to collapse." ,
                 ({"bonfire","fire"}) :
                            "The bonfire burns hot.  It appears to be used "
                            "for cooking something, as it has a large kettle "
                            "hanging over it.",
                 ({"large kettle","kettle"}) :
                            "The large black kettle is full of something "
                            "you don't even want to begin to identify.",
                 ({"wood"}) :
                            "The wood is old and splintered.",
                 ({"ancient forest","forest"}) :
                            "The ancient forest is dark and sinister looking.",
                 ({"darkness"}) :
                            "It is very shadowy."
                                   ]) );
    SetListen( (["default" : "A fire snaps and crackles."]));
    SetSmell(  (["default" : "A smokey smell hangs in the air."]));
    SetExits( ([ "west" : GLEN + "/rooms/path3"]));
    SetObviousExits("west");
    SetEnters( ([
              "shack"          : GLEN + "/rooms/shack" ,
              "rundown shack"  : GLEN + "/rooms/shack" ]) );
    SetInventory(([GLEN + "/npc/oldwoman": (1)]) );
}
