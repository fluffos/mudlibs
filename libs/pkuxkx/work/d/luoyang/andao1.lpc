#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"天地会暗道"NOR);
	set("long",
HIC"这是一条黑漆漆的地道，曲曲折折地通向前方。两边都是
土墙，隐约可以听到上面脚底落地的声音。空气中弥漫着潮湿
的泥土气息，令人感到十分凉爽。一个道人站在这里，守卫着
上面的两个出口。\n"NOR
	);
	set("exits", ([
		"north" : __DIR__"andao2",
		"south" : __DIR__"andao3",
		"westup" : __DIR__"guancai2",
	]));
	set("objects", ([
		CLASS_D("tiandihui") + "/xuanzhen" : 1 ]));
	setup();
}



