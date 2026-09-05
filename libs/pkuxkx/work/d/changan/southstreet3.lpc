
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "朱雀大街");
        set("long", @LONG
这是繁华的朱雀大街，两边都是高官富商的宅邸，隐隐听闻四周
寺院道观里面的诵唱声音。北面是皇城的南门朱雀门，南面通向
明德门。
LONG        );
        
        set("exits", ([
                "east"  : __DIR__"daciensi",
                "west"  : __DIR__"xuanduguan",
                "south" : __DIR__"southgate",
                "north" : __DIR__"southstreet",
                
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}


