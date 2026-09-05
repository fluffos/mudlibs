// Room: /d/beijing/zijin/wuyingdian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"武英殿"NOR);
	set("long",
HIC"这里是皇帝斋戒及召见大臣的地方，后殿的群房是宫廷画家们作画
的场所。后来这里成为修书处,为皇家刻印了大批书籍,称为殿版。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"guang3",
  	"north" : __DIR__"jingsidian",
]));

	setup();
	replace_program(ROOM);
}
