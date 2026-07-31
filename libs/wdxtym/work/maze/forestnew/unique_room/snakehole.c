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
set("exits", ([ /* sizeof() == 3 */ 
                "west" : "maze/forestnew/unique_room/tigerhill", 

        ]));         
        set("objects",([
                "/maze/forestnew/npc/snake_king": 1,   
                "/maze/forestnew/npc/snake_big": 5, 
                "/maze/forestnew/npc/snake_baby": 5,   
                "/maze/forestnew/obj/box1": 1,      
        ]));
        setup();
}
