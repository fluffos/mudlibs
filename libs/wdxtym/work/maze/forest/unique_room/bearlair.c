#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",HIB"–‹∂¥"NOR);
        set("long",@LONG
∫√∂‡–‹∞°£°
LONG);
        
        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");     
        
        set("objects",([
                "/d/maze/forest/npc/bear_king": 3,
                "/d/maze/forest/npc/bear_big": 5, 
                "/d/maze/forest/npc/bear_baby": 5,   
                "/d/maze/forest/obj/box1": 1, 
        ]));
        setup();
        // replace_program(ROOM);
}
