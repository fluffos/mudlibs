// Room: /d/hengshan/jinlongxia.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"金龙峡"NOR);
	set("long", @LONG
金龙峡又称唐峪，是进入恒山的入口。恒山一名太恒山，或称玄岳，是五
岳中的北岳，道教以之为“第五小洞天”。它横亘三百余里，如一队行进中的
队列，昔人以为“恒山如行”来相对“泰山如坐”，“华山如立”，“嵩山如
卧”和“衡山如飞”。
LONG
	);
	set("exits", ([
                "southdown"  : "/d/changan/northroad10",
                "southwest"  : __DIR__"cuipinggu1",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
	]));
        set("outdoors", "恒山");
        setup();
}
