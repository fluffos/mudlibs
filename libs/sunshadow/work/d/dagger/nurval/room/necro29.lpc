#include "../tomb.h"

inherit NECROPOLIS;

void create(){
        ::create();
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^The road leads from the north to the south.
");
        set_exits(([
                "north":ROOMS+"/necro30",
                "northwest":ROOMS+"/necro27",
                "west":ROOMS+"/necro26",
                //"southwest":ROOMS+"/necro35",
                //"south":ROOMS+"/necro34",
                //"southeast":ROOMS+"/necro33",
                "east":ROOMS+"/village",
                //"northeast":ROOMS+"/necro32",
                ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO))
       new("/d/common/obj/misc/street_light")->move(TO);
}
