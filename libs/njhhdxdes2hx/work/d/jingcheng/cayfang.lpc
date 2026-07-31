// Room: /d/jingcheng/cayfang.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m长安乐坊[2;37;0m");
	set("long", @LONG
这里是长安城一家有名的娱乐场所。当夜幕降临后，这里就
格外热闹。进进出出的客人有达官贵人，南来北往的商旅，
浪迹天涯的游子，三五成群的兵士，有时也能看见一些作俗
客打扮的僧人或道士。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"yfangup",
  "west" : __DIR__"baih6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youke" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
