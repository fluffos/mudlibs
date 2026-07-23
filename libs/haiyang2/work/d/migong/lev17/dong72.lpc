#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"水裂山谷"NOR);
	set("long", WHT @LONG
    你一个神秘的地方，此处是一个四周都围绕著高山峻岭的山谷
山谷的的中央有一个漂亮的湖，湖的四周有许多的垂杨，并且遍地
鲜花绿草，并且从此望去天空明晰可见，这里真是个世外桃源。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+3),
		"east" : __DIR__"dong7"+(random(4)+1),
		"south" : __DIR__"dong7"+(random(4)+3),
		"north" : __DIR__"dong71",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+1),
		"east" : __DIR__"dong73",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
