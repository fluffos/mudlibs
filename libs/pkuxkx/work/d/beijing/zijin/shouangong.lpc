// Room: /d/beijing/zijin/shouango.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"寿安宫"NOR);
	set("long",
HIC"这是紫禁城中一间寻常宫室，因为年代久远，整个宫室显得
相当阴暗．不时吹来一阵冷风让人毛发倒竖，四壁宫墙似乎要诉
说什么久已遗忘的故事．北面就是英华殿。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"houdian",
  	"north" : __DIR__"yinghuadian",
]));

	setup();
	replace_program(ROOM);
}
