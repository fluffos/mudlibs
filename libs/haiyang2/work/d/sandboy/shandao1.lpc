// Room: /d/sandboy/shandao1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条幽静的山道。太阳暖洋洋地在头上，溪水活泼泼地在脚边流过。
小鸟儿唧唧叫着飞过不远的树林，路的东面有个破庙。
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("item_desc", ([ /* sizeof() == 3 */
  "树林" : "一片杂树林，大约有好几十棵。
",
  "破庙" : "远看去，这间破庙摇摇欲坠，随时都可能蹋下来。
",
  "溪水" : "山泉从高处流下，形成的小溪流。
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"pomiao",
  "north" : __DIR__"shandao",
]));

	setup();
}
void init()
{
  tell_room(__DIR__"pomiao",HIC+"庙门外传来一阵脚步声!\n"+NOR);
}
