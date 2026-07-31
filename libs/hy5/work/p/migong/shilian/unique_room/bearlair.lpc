#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",HIB"熊洞"NOR);
        set("long",@LONG
好多熊啊！
LONG);
        
        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");     
        
        set("objects",([
                "/p/migong/shilian/npc/bear_king": 1,   
                "/p/migong/shilian/npc/bear_big": 5, 
                "/p/migong/shilian/npc/bear_baby": 5,   
                "/p/migong/shilian/obj/box1": 1, 
        ]));
        setup();
        // replace_program(ROOM);
}
