// Room: /d/jingcheng/fliang.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m丰记粮店[2;37;0m");
	set("long", @LONG
这是一家生意兴隆的粮店。丰老板坐在柜台后面笑容可鞠地接待
着客人。活计们在一边忙忙碌碌地工作着。如果你身无分文，你
还可以在这里向丰老板打一些零工，以赚一些钱。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhq9",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/feng" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
