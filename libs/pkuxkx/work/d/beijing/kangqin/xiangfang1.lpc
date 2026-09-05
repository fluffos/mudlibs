// Room: /d/beijing/kangqin/xiangfang1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"厢房"NOR);
	set("long",
MAG"这里是康亲王请来的武师们住的地方。房间里摆设不
多，但很齐全。这里经常有仆人来打扫，窗明几亮。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"south" : __DIR__"xiaoyuan",
]));
	set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
