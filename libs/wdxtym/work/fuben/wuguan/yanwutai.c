//by 游侠 ranger's ednpc tools.
// yanwutai.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","演武台");
	set("long","这里是演武台，管理员尚未设定本地详细描述。");
	set("fuben2",1);
	set("exits", ([
		"east" : __DIR__"lianwuchangj",
		"north" : __DIR__"lianwuchangf",
		"south" : __DIR__"lianwuchange",
	]));
	set("objects", ([
	__DIR__"npc/wuguan_jiaotou":5,
	//__DIR__"obj/baoxiang":1,	
	]));
	setup();
}

