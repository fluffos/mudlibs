// cangjingge1.c 藏经阁

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "藏经阁一楼");
        set("long", @LONG
这里是藏经阁一楼，靠墙是几排书架，摆满了道教的典籍。中央
有一个长方形的大桌子，上面也堆满了书。几个道童正在整理书籍。
LONG
        );

        set("exits", ([
                "out" : __DIR__"cangjingge",
                "up" : __DIR__"cangjingge2",
             ]));
        set("objects", ([
"/d/quanzhen/npc/daotong" : 2]));

        setup();
        
}
int valid_leave(object me, string dir)
{

        if( !present("letter", this_player()) && me->query("family/master_id")!="master qiu"        && (objectp(present("dao tong", environment(me)))) )
        {
                if (dir == "up" )
                {
                        return notify_fail("道童说道: 你未经许可，不能上二楼。\n");
                }
        }
        return ::valid_leave(me, dir);
}


