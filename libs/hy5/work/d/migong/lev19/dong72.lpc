#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"飞船之遗迹"NOR);
	set("long", CYN @LONG
   传说这是一艘叫做天马号的飞船，是魔法王国的遗物，据说以前是
一座飞在天空的城市，不知什么时候掉到了这里。你说在的地方依稀还
看的到是甲板的样子，附近雾气重重，雾中的杀气越来越浓了。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+1),
		"east" : __DIR__"dong7"+(random(4)+3),
		"south" : __DIR__"dong7"+(random(4)+1),
		"north" : __DIR__"dong71",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+3),
		"east" : __DIR__"dong7"+(random(3)+2),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+2),
		"north" : __DIR__"dong7"+(random(3)+1),
	]));

         set("objects", ([
              __DIR__"npc/lev3" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
