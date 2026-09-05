#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", GRN "柳树林" NOR);
        set("long", @LONG
江南水乡之地到处河泊纵横，这片柳树林便生在一条小河旁，柳条
随风飘摆，宛如仙子起舞。时不时还有一两只林中鸟兽从你身前跑过，
当真是个好地方。前面小河拦路，无法再行。
LONG);
 
        set("no_sleep_room", 1);

        set("objects", ([
                         __DIR__"npc/guairen" : 1,
                         
    
        ]));       

        set("exits", ([
              "east" : __DIR__"river",
        ]));

        set("no_task",1);
        setup(); 

//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (objectp(present("guai ren", environment(me))) && 
            dir == "east" && this_player()->query("id")!="murong pantu")
                return notify_fail("忽听呼的一声响，怪人从你头顶跃过，落在你身前。\n");
        return ::valid_leave(me, dir);
}
