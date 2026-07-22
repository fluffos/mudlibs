// neiyuan.c 内园

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "内园");
        set("long", @LONG
迎面是一座大假山，奇石林立，堆叠多姿，形像各异，石峰间种着黄杨、石
榴、白皮松等植物。假山四周老树横卧，修簧数竿，回廊盘曲，环境幽绝。园二
边有几间厢房,几个道童持剑站在门外。
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "northwest" : __DIR__"yunjiyuan",
                "west" : __DIR__"xiangfang1",
                "east" : __DIR__"xiangfang2",
                "south" : __DIR__"waishi",
        ]));
        setup();
        
}

/*
int valid_leave(object me, string dir)
{
        int skill;

        skill = me->query_skill("taoism", 1);
        if (!wizardp(me) && skill < 80)
        {
                if (dir == "south" )
                {
                        return notify_fail("\n");
                }
        }
        return ::valid_leave(me, dir);
}
*/
