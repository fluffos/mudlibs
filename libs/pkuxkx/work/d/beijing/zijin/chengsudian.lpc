// Room: /d/beijing/zijin/chengsudian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"诚肃殿"NOR);
	set("long",
HIC"这里是诚肃殿。向北走是景仁宫，向南是斋宫。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"jingrengong",
  	"south" : __DIR__"zhaigong",
]));

	setup();
	replace_program(ROOM);
}
