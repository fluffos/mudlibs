// Room: /d/beijing/zijin/leshoutang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"乐寿堂"NOR);
	set("long",
HIC"此处为皇帝归政后园庭憩息之所。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"west" : __DIR__"huayuan",
  	"south" : __DIR__"yangxingdian",
 	 "north" : __DIR__"yihexuan",
]));

	setup();
	replace_program(ROOM);
}
