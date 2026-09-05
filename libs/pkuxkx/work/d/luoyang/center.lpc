//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"洛阳"+HIC"中心广场"NOR);
        set("long", @LONG
这里就是古都洛阳，眼前一片繁华，一条条宽敞明净的大道，熙熙
攘攘的人群，热闹的集市，充分展示了这座最古老的城市的生机。街上满
是来这里观光游览的游客，想必吸引他们的是大名鼎鼎的洛阳唐三彩和中
国第一古刹白马寺吧！当然建在这里的洛阳行宫也是许多别处的官员常来
膜拜的地方，而金刀王家的大名更是引来了无数的武林人士的拜访。广场
上好像刚刚下过雨，空气很清新，地上湿漉漉的，整个广场给人的感觉就
是古老而赋有生机，就像是这座古城的一个缩影。
LONG
        );

        set("exits", ([
               "east" : __DIR__"dongdajie1",
               "west" : __DIR__"xidajie1",
               "north" : __DIR__"beidajie1",
               "south" : __DIR__"nandajie1",   
							 "southeast":__DIR__"pl_hockshop2",
        ]));
        set("objects", ([
                "/clone/npc/jicun":1,
            "/clone/npc/camel1": 0,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}


