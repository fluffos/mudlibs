#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",HIR"ÁúÑ¨"NOR);
        set("long",@LONG
ºÃ¶àÁú°¡£¡
LONG);

        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");
        set("exits", ([ /* sizeof() == 3 */ 

		"east" : "maze/forestnew/unique_room/tigerhill", 

        ]));  
        set("objects",([
                "/maze/forestnew/npc/dragon": 1,  
                "/maze/forestnew/npc/dragon_baby": 5,    
                "/maze/forestnew/obj/box2": 1, 
        ]));        
        setup();
}
