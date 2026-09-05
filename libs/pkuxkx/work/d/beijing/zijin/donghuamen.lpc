#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"东华门"NOR);
	set("long",
HIC"这是紫禁城的一个偏门，经常可以看见有人在这进进出出。门口
有几个侍卫在站岗，但仔细一看，发现他们在打盹。北方不时传来一
声声马嘶。\n"NOR
	);

	set("exits", ([
		"west" : __DIR__"wenhuamen",
//		"north" : "/d/beijing/dongchang/gate",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
