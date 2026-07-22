// Room: /d/changle/bajiao.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR"八角亭"NOR);
	set("long", @long
这是花园中一个小巧的亭子，供赏花时休息之用。亭中石桌石凳俱全，石
桌上还摆放着几盘点心。院中花卉暗香浮动。几个假山做得甚是别致。
long
	);

	set("exits", ([
		"west" : __DIR__"huayuan",
	]));

	set("objects", ([
		__DIR__"npc/ding": 1,
	]));

	set("outdoors", "长乐帮");
	setup();
}
