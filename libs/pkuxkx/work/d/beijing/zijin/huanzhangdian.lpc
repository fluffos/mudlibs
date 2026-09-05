#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"焕章殿"NOR);
	set("long",
HIC"这是训练新兵的地方。地上散落着各种各样的兵器，两个教官在
认真的和士兵对打，从这儿出去的新兵基本功非常的扎实。\n"NOR
	);

	set("exits", ([
        "east" : __DIR__"guang3",
	]));
	set("objects", ([
		"/d/beijing/npc/shiwei" + (5 + random(2)) : 4,
	]));
	setup();
	replace_program(ROOM);
}
