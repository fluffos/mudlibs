#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"屠宰场"NOR);
	set("long",
CYN"这里是屠宰场，空气中弥漫着猪的气味。偶尔一阵热风吹过，
顿时一股臭气袭来，直熏得人作呕。一个中年人手握屠刀，指挥
着伙计们杀猪去毛。这就是京城最大的屠宰场，据说宫里所有的
猪肉都是从这里送去的。\n"NOR
 );
	set("exits", ([
		"southwest" : __DIR__"tianqiao",
        "northeast" : __DIR__"changjie",
	]));
   set("objects", ([
		__DIR__"npc/lilishi":1,
		__DIR__"npc/qianlaoben":1,
		__DIR__"npc/huoji1":2,
	]));

	setup();
	replace_program(ROOM);
}
