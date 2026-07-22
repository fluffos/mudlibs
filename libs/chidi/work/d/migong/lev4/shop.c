#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"山洞"NOR);
	set("long", HIG @LONG
       这里是一个规模不大但种类齐全的铺子，从各种药物到
兵器，食物应有尽有，但价钱嘛...嘿嘿，命重要还是钱重要?
LONG NOR);
	set("exits", ([
		"west" : __DIR__"dong100",
                               	]));
         set("objects", ([
             __DIR__"npc/hygirl" : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
