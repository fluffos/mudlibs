// Room: /d/beijing/zijin/guang4.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"空旷广场"NOR);
	set("long",
HIC"这是空旷一个的广场，便于练习可跑马射箭。
清代武士殿试在此演示，皇帝便在南边的箭亭阅技
。由此往东是一排平房。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"west" : __DIR__"jingyunmen",
 	"north" : __DIR__"fengxiandian",
 	"south" : __DIR__"jianting",
 	"east" : __DIR__"ningshoumen",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
