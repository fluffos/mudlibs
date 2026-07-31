//by 秦始皇 qsh ednpc tools.
// zhudian.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY"皇陵主殿"NOR);
	set("long","这里是皇陵主殿，管理员尚未设定本地详细描述。");
	set("exits", ([
		"north" : __DIR__"chukou",
		"east" : __DIR__"huangling12",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/dihun":5,	
	]));
	setup();
}

