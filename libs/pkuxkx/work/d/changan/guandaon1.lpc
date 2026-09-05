//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "官道");
        set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。路上行人纷纷，部分
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！南面就是大明宫
的北大门玄武门，两边羽林军拱卫，还是不要接近为妙。北面是渭水河畔，
顺着渭水就能看到黄河了。
LONG
        );

        set("exits", ([
               "north" : __DIR__"guandaon2",
               "south" : __DIR__"xuanwumen",
               "west" : __DIR__"xiaodaon3",
               "east" : __DIR__"xiaodaon4",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
