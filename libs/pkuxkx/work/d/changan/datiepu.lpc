
#include <ansi.h>
#include <localtime.h>
inherit ROOM;
void create()
{
        set("short", "打铁铺");
        set("long", @LONG
这是长安城里普通的一家打铁铺，以维修兵器著称。只要兵器没断，无论损坏程度如何，
都能给修好了。当然，价格也是不菲的。
LONG
        );

        set("exits", ([
               "east" : __DIR__"westmarket-2",
        ]));
        set("objects", ([
                "/d/hangzhou/npc/tiejiang":1,   
                "/d/hangzhou/npc/huoji":1             
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}