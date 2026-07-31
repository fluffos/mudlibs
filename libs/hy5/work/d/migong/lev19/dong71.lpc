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
		"north" : __DIR__"dong19",
		"east" : __DIR__"dong6"+(random(7)+1),
		"south" : __DIR__"dong5"+(random(7)+1),
		"west" : __DIR__"dong72",
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong19",
		"west" : __DIR__"dong72",
		"south" : __DIR__"dong5"+(random(7)+1),
		"north" : __DIR__"dong6"+(random(7)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(3)+1),
		"east" : __DIR__"dong19",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+1),
		"north" : __DIR__"dong19",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : 5,
              __DIR__"npc/lev4" : 5,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
