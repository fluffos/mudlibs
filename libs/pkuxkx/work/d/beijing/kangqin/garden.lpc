// Room: /d/beijing/kangqin/garden.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"后花园"NOR);
	set("long",
MAG"这里是康府后花园，西首是一个厨房。北边通往后堂
东边是一个武器库。南边是一间石屋。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"shiwu",
  	"west" : __DIR__"chufang",
  	"north" : __DIR__"houtang",
  	"east" : __DIR__"wuqiku",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
