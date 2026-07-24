#include <room.h>
#include <ansi.h>
inherit ROOM; 

void create() 
{ 
	set("short", HIY"测试入口"NOR);
	set("long", HIY @LONG
测试入口
LONG NOR);
                        
        set("outdoors", "forest"); 
        set("no_magic",1);
  set("magicroom",1);
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
set("sleep_room",1);
     
        set("exits", ([ /* sizeof() == 3 */ 
                "south":__DIR__"maze/entry",
//"north":__DIR__"maze4/exit",
        ])); 
                        
        setup();
        // replace_program(ROOM); 
} 

int valid_leave(object me, string dir)
{
        object *inv, obj;
        if (dir == "out")
        {
                tell_object(me, "check!\n");
                inv = all_inventory(me);
                if (inv && sizeof(inv)>0)
                        foreach(obj in inv) {
                                if (obj && obj->query("maze_item"))
                                        destruct(obj);
                        }
        }
        return 1;
}

