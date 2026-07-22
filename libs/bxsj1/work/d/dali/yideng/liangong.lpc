// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是练功房，地下凌乱地放着几个蒲团，房间内摆放着各种武器，房间
左侧凌乱堆放着一些沙袋，看来是用来练习高深指法用的。
LONG
	);
	set("exits", ([
		"west" : __DIR__"houyuan",
	]));

	set("objects", ([
		BINGQI_D("sword") : 1,
	]));

	setup();
}
