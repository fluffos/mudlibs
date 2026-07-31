//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "左家大门");
	set("long", @LONG
	左家是这儿的大户， 一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮
子立在了大门两侧，朱漆大门足足有三寸厚。门上挂着两个灯笼，写着“左”字。 听说
左家的主人左轻候炒的一手好糖醋鱼。不知道你有没有这个运气。
几个家丁站在门口。   
LONG
	);
	set("exits", ([
		"north" : __DIR__"wroad1",
		"west" : __DIR__"zuojia2",
]));                                      
	set("objects", ([
		__DIR__"npc/jiading" : 2,
]));
	setup();
	replace_program(ROOM);
}
