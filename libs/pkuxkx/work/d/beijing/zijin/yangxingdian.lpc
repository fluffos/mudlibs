// Room: /d/beijing/zijin/yangxingdian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"养性殿"NOR);
	set("long",
HIC"养性殿上部正中为重檐歇山式，四面各有抱厦，
为单檐卷棚式。复以黄琉璃瓦、绿剪边，飞檐翘角，
极富变化。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"leshoutang",
  	"south" : __DIR__"yangxingmen",
]));

	setup();
	replace_program(ROOM);
}
