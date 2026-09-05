//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小道");
        set("long", @LONG
这是长安城北面宫墙下的小道，小道在宫墙一路向东北延伸。
LONG
        );

        set("exits", ([
               "west" : __DIR__"xiaodaonw3",
               "northeast" : __DIR__"xiaodaon2",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}
