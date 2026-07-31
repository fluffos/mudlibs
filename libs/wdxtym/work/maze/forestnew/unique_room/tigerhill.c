#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",HIY"»¢É½"NOR);
        set("long",@LONG
ºÃ¶à»¢°¡£¡
LONG);
        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");  
        set("outdoors", "necropolis");
                set("exits", ([ /* sizeof() == 3 */ 
                "south" : "maze/forestnew/unique_room/shenlin", 
		"east" : "maze/forestnew/unique_room/snakehole", 
                "west" : "maze/forestnew/unique_room/dragonland", 
        ])); 
        set("objects",([
                "/maze/forestnew/npc/tiger_king": 1,   
                "/maze/forestnew/npc/tiger_big": 5, 
                "/maze/forestnew/npc/tiger_baby": 5,   
                "/maze/forestnew/obj/box1": 1,       
        ]));
        setup();
}
