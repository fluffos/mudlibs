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
        
		set("exits", ([ /* sizeof() == 3 */ 
                "west" : "maze/forestnew/unique_room/shenlin", 
        ])); 

        set("objects",([
                "/maze/forestnew/npc/bear_king": 3,
                "/maze/forestnew/npc/bear_big": 5, 
                "/maze/forestnew/npc/bear_baby": 5,   
                "/maze/forestnew/obj/box1": 1, 
        ]));
        setup();
        // replace_program(ROOM);
}
