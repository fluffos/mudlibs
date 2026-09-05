// Room: /d/beijing/zijin/jingshifang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"敬事房"NOR);
	set("long",
HIC"这是宫殿监办事处,也是总管各处太监事务的敬事房。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"nanshufang",
  	"east" : __DIR__"qianqingmen",
]));

	setup();
	replace_program(ROOM);
}
