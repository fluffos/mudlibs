// by XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "皮货药材店");
	set("long", @LONG
这是古浪城里唯一的一家店铺，一踏进铺内就可闻到一股淡淡的膻味，隐
隐可以看见堆放在后院翻晒的各式皮货，怕有不下千余件。在西墙边，立了一
个大红木药柜，里面盛放了草药。
LONG );
	set("exits", ([
		"west" : __DIR__"gulang",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));

	setup();
}
