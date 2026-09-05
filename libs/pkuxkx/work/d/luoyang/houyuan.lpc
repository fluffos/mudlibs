//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"客店"+HIB"客房"NOR);
        set("long", @LONG
这里有几间很大的客房，陈设不算豪华。靠墙放了十几张小木床，
不少客人正和衣而卧，满屋子都是呼呼的打酣声。西边有张床是空的，
你蹑手蹑脚地走了过去。
LONG
        );
        set("sleep_room", "1");
        set("no_fight", "1");
        set("hotel",1);

        set("item_desc", ([
        ]) );

        set("exits", ([
//               "east" : __DIR__"houyuan",  
               "west" : __DIR__"kezhan",            
        ]));
        set("objects", ([
//                __DIR__"npc/xiaoer" : 1,
        ]));

//        set("outdoors", "luoyang");
        setup();
}
int valid_leave(object me, string dir)
{
        if ( dir == "west" ) me->delete_temp("lyrent_paid");

        return ::valid_leave(me, dir);
}

