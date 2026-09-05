#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIG"程氏诊所"NOR);
	set("long", @LONG
   这里是神医程灵素的家,程姑娘医术高超,不知救了多少人的命,屋子里面
摆满了坛坛罐罐,空气中充满了药味,墙上挂着一面金匾:妙手回春.
LONG
	);

	set("exits", ([
		"east" : __DIR__"xysouth1"          
	]));

	set("objects", ([
		__DIR__"npc/clsu" : 1,
        ]));

	setup();
}

