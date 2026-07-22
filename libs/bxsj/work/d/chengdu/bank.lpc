// Room: bank.c
// Looklove y2k/4/10
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"墨玉斋"NOR);
        set("long", @LONG
这里是热闹的成都城里的一家大钱庄，生意看起来很不错，人来人往，看
来住在附近的人都比较富裕。这个钱庄可以兑换通行全国的银票。
LONG
        );

        set("exits", ([
                "east" : __DIR__"nandajie2",
        ]));

        set("objects", ([
                __DIR__"npc/banker" : 1,
          
        ]));
 
        set("incity",1);
	setup();
}

