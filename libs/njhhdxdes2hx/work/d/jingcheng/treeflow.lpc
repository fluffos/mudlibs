// Room: /d/jingcheng/treeflow.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m三花堂总堂[2;37;0m");
	set("long", @LONG
三花堂是近年江湖中兴起的一个帮派，靠替人打架及绑票为营生
赚钱。到处找幕地痞流氓，打砸烧抢．但由于找不道足够证据，
官家又拿其无可奈何。屋里围了一帮人，阴渗渗的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xw1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liumang" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
