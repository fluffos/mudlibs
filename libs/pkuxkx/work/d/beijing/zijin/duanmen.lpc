#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"端门"NOR);
	set("long",
HIC"这是一个极大的广场，侍卫们经常在此操练。广场边上是紫禁城
的护城河。向北走便是紫禁城的南大门午门。\n"NOR
	);


	set("exits", ([
		"north" : __DIR__"wumen",
		"south" : __DIR__"tiananmen",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
