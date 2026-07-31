
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"灼热的深渊"NOR);
	set("long", RED @LONG
  毒气，硫磺！这是一片火红的大地，灼热的地面上
升起一阵一阵的毒烟!无际的大沙漠。而四下的怪物
更是对你虎视眈眈，随时都会扑过来，咬断你的咽喉
，撕裂你的身躯。
LONG NOR);
set("magicroom",1);
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong51",
		"east" : __DIR__"dong53",
		"south" : __DIR__"dong5"+(random(4)+3),
		"north" : __DIR__"dong5"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+1),
		"east" : __DIR__"dong5"+(random(4)+3),
		"south" : __DIR__"dong5"+(random(4)+1),
		"north" : __DIR__"dong5"+(random(6)+3),
	]));
        set("objects", ([
              __DIR__"npc/lev2" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

