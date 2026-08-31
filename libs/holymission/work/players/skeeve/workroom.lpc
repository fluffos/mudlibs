#define NAME "skeeve" 

#define CNAME   capitalize(NAME)

#include "/players/skeeve/area.h"

inherit "room/room";

reset (arg) {
    if (arg) return ;

    dest_dir = ( {
        "obj/tick"          ,"tick",
        "room/church"       ,"church",
        "room/adv_guild"    ,"guild", 
        "room/post"         ,"post",
        ROAD + "northgate"  ,"ng",
        ROAD + "southgate"  ,"sg",
        LAND + "clearing"   ,"cot",
        LAND + "rest"       ,"rest",
        LAND + "shop"       ,"shop",
        MAZE + "chapel"     ,"chapel"       
    });

    property=({ "has_fire" });

    set_light (1);

    short_desc = CNAME +"'s workroom";
    long_desc   = "This is the workroom of "+CNAME+".\n"
            + "It looks empty ...\n";
}
