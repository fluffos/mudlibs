// Room: /d/mr/cl6-1.c
// this is made by beyond
// update 1997.6.20
// Lklv 2001.9.20

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"长廊"NOR);
	set("long", @long
这是一条长廊，上面画着江南秀美的油彩画。绿色的柱子朱红色的琉璃瓦，
使得你不由得对江南工匠的艺术创造惊叹不已。在长廊里面，丫鬟、家丁们走
来走去，正在忙着招呼客人，不敢有一点怠慢。长廊东面是厢房，南面和西面
是长廊的延伸。
long);
	set("exits", ([
		"south" : __DIR__"cl6-2",
		"east" : __DIR__"xiangfang3",
		"north" : __DIR__"cl6-0",
		"west" : __DIR__"cl6-3",
	]));

	set("objects",([
		__DIR__"../npc/puren" : 2,
	]));
	setup();
}