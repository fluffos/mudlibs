// Room: /d/beijing/zijin/chuanxin.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"传心殿"NOR);
	set("long",
HIC"这是文渊阁的偏殿，里面空无一物，地上落满了灰尘，靠墙处有几个大书架，
不知道是放的什么书．这里看起来好久没有人打扫了。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"west" : __DIR__"wenhuadian",
]));

	setup();
	replace_program(ROOM);
}
