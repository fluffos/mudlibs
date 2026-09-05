// Room: /d/beijing/zijin/tiyuandian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"体元殿"NOR);
	set("long",
HIC"与该殿后檐相连的戏台即长春戏台,慈禧太后五十寿辰时,同宫内
的妃嫔及命妇每天在此看戏,长达半月之久。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"changchungong",
  	"south" : __DIR__"taijidian",
]));

	setup();
	replace_program(ROOM);
}
