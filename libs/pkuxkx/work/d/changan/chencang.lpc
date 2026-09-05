//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "陈仓");
        set("long", @LONG
陈仓背靠秦岭山脉，扼守着蜀地通往中原的交通要冲，
四周层峦叠嶂，风景优美。西南面就是关中四关之一：大
散关，北面就是险峻的六盘山。
LONG
        );

        set("exits", ([
               "southwest" : __DIR__"dasanguan",
               "east" : __DIR__"guandaow1",
               "northup" : "/d/xingxiu/shanlu1"
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
