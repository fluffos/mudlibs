// Room: /d/beijing/kangqin/xiaoyuan.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"小院"NOR);
	set("long",
MAG"这是一个僻静的小院子，中间种着一棵老槐树，树下有一口井。
周围都是平房，不时传来吆喝之声。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"xiangfang3",
  	"west" : __DIR__"xiangfang2",
  	"north" : __DIR__"xiangfang1",
 	 "east" : __DIR__"zhoulang8",
]));

	setup();
	replace_program(ROOM);
}
