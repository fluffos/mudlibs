// Room: /d/beijing/zijin/neizuomen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"内左门"NOR);
	set("long",
HIC"这是通往东六宫的重要门户,由此往里是皇帝和后妃们居住的地方。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
 	"west" : __DIR__"rijingmen",
  	"north" : __DIR__"tongdao4",
 	"east" : __DIR__"zhaigong",
// 	"southwest" : __DIR__"qianqingmen",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
