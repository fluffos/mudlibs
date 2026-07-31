#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",HIC"…ﬂ∂¥"NOR);
        set("long",@LONG
∫√∂‡…ﬂ∞°£°
LONG);

        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");  
        
        set("objects",([
                "/d/maze/forest/npc/snake_king": 1,   
                "/d/maze/forest/npc/snake_big": 5, 
                "/d/maze/forest/npc/snake_baby": 5,   
                "/d/maze/forest/obj/box1": 1,      
        ]));
        setup();
}