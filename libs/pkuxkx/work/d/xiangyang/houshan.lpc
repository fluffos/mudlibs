#include <ansi.h>
inherit ROOM;
void create ()
{
    set("short",BLK"后山"NOR);
    set("long",
 CYN"这里是土匪山寨的后山，是他们藏赃物的地方，地上放着一个木箱，
箱子盖开着，里面放着土匪们抢来的东西。\n"NOR
       );     
	set("objects", ([
		__DIR__"npc/obj/caibao" : 2,
        ]));  
	set("exits", ([

                "south"  : __DIR__"hszhai",
              
	]));         
        setup();
        
}                                                         


