//by 游侠 ranger's ednpc tools.
// lianwuchangb.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","练武场");
	set("long","这里是练武场，管理员尚未设定本地详细描述。");
	set("fuben2",1);
	set("exits", ([
		"east" : __DIR__"lianwuchangd",
		"north" : __DIR__"lianwuchangc",
		"west" : __DIR__"xiuxishi",
	]));
	set("objects", ([
		__DIR__"npc/wuguan_dizi":5+random(2),
	]));
	setup();
}

