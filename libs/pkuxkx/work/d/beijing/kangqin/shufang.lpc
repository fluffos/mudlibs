#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()

{

	set("short", HIC"康亲王书房"NOR);

	set("long",
MAG"这里是康亲王书房，房中书架上整整齐齐地堆放着很多书。不过书上积了
一些灰尘，显然是很久没有动过了。而书橱里的几件精巧玉器却更显得玲珑剔
透，光彩照人。\n"NOR
	);

	set("exits", ([

		"north" : __DIR__"garden2",

	]));

	set("objects", ([

		"/d/beijing/npc/kang" : 1,

	]));

	setup();

	replace_program(ROOM);

}



