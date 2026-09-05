//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "大散关");
        set("long", @LONG
位于陈仓南郊的大散关，背靠秦岭北麓大散岭，北面就是渭水支流，南面通向嘉陵
江上游，这里山势险峻，层峦叠嶂，大有“一夫当关，万夫莫开”之势，扼守川陕咽喉，
自古就是兵家必争之地。
LONG
        );

        set("exits", ([
               "northeast" : __DIR__"chencang",
               "southup" : __DIR__"guandaow2",
        ]));

        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();        
}
