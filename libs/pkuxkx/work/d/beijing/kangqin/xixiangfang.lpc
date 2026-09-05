
// Room: /d/beijing/kangqin/xixiangfang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"西厢房"NOR);
	set("long",
MAG"这是一间很宽敞的房间。靠窗口有一张炕，上面铺着锦被。炕
边有张桌子，上面放着一盏油灯。地面很干净，显然经常有人打扫。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"east" : __DIR__"tingyuan",
]));

	setup();
	replace_program(ROOM);
}
