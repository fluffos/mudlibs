//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "汉中");
        set("long", @LONG
汉中北倚秦岭，南屏大巴山，扼守着通往蜀地的蜀道。
LONG
        );

        set("exits", ([
               "northwest" : __DIR__"guandaow3",
               "southup" : "/d/chengdu/shudaon1",
               "east" : __DIR__"guandaosw5",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}

int valid_leave(object me, string dir)
{
	me->set_temp("shudao/last_go_time",time());
	return ::valid_leave(me, dir);
}