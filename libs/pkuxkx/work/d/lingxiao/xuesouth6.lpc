//吴起
//xuesouth6.c
//03-7-14

#include <room.h>;
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "卦馆"NOR);
	set("long", @LONG
一进入这间小屋，一股阴冷潮湿之气扑面而来。靠着一张小桌，是两个幌子
，上面有一副对联，上联是“袖里乾坤大”，下联是“壶中日月长”，很普通的
一对。雪山派的弟子一般都不屑于来这里的，即使来也都偷偷摸摸的，不愿意被
师兄弟看到。
LONG);
	
	set("indoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"xuejie6",
	]));
	set("objects", ([
		__DIR__"npc/skgua" : 1,
	]));

	setup();
}

