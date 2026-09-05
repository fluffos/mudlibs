// Room: /d/beijing/west/xidan.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"西单"NOR);
	set("long",
CYN"这是北京城里各大商号最密集的地方，京城里许多上百年的老
字号都开在这里，而富商大贾，宗室大臣也大多喜欢在这里置办房
产。西边是宣武门，东边就是西长安街了。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xuanwumen",
  "east" : __DIR__"changanjie_w",
]));

	setup();
	replace_program(ROOM);
}
