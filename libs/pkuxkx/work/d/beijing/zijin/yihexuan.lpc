// Room: /d/beijing/zijin/yihexuan.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"颐和轩"NOR);
	set("long",
HIC"这里为皇帝归政后的憩息之所。“颐和”的名称是皇
帝预祝他自己老年幸福。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"leshoutang",
  	"north" : __DIR__"hougongmen",
]));

	setup();
	replace_program(ROOM);
}
