
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "函谷书肆");
        set("long", @LONG
这是函谷八友的老三苟读开办的书肆，专门售卖各类文房四宝，
古今书籍。
LONG
        );

        set("exits", ([
               "west" : __DIR__"westmarket-3",
        ]));
        set("objects", ([
                __DIR__"npc/goudu":1
        ]));

        setup();
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
}