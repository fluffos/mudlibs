#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",HIW"¿«—®"NOR);
        set("long",@LONG
∫√∂‡¿«∞°£°
LONG);
        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");  
		set("exits", ([ /* sizeof() == 3 */ 

				"east" : "maze/forestnew/unique_room/shenlin", 

        ])); 
        set("objects",([
                "/maze/forestnew/npc/wolf_king": 1,   
                "/maze/forestnew/npc/wolf_big": 5, 
                "/maze/forestnew/npc/wolf_baby": 5,   
                "/maze/forestnew/obj/box1": 1,       
        ]));
        setup();
}
