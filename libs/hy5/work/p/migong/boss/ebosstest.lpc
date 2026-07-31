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
                "lev1":__DIR__"evrm_0000/exit",
                "lev2":__DIR__"evrm_0001/exit",
                "lev3":__DIR__"evrm_0002/exit",
                "lev4":__DIR__"evrm_0003/exit",
                "lev5":__DIR__"evrm_0004/exit",
                "lev6":__DIR__"evrm_0005/exit",
                "lev7":__DIR__"evrm_0006/exit",
                "lev8":__DIR__"evrm_0007/exit",
                "lev9":__DIR__"evrm_0008/exit",
                "lev10":__DIR__"evrm_0009/exit",
                "lev11":__DIR__"evrm_0010/exit",
                "lev12":__DIR__"evrm_0011/exit",

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

