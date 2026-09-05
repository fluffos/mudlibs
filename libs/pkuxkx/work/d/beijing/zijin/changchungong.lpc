// Room: /d/beijing/zijin/changchungong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"长春宫"NOR);
	set("long",
HIC"这原本是后妃们居住的地方。但当今皇上年纪尚轻，尚未婚配。
因此偌大一间屋子里空空荡荡，没什么东西。只有几个太监偶尔来
打扫一下。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
//  	"north" : __DIR__"yiqingshuwu",
  	"south" : __DIR__"tiyuandian",
  	"east" : __DIR__"yikungong",
]));

	setup();
	replace_program(ROOM);
}
