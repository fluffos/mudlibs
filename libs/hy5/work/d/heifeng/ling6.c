// Room: /d/heifeng/ling6.c

inherit ROOM;

void create()
{
	set("short", "陡峭山路");
	set("long", @LONG
这是一条陡峭的小路，窄得只能容一个人走，左面是万丈悬
崖，右面是长满藤蔓的石壁。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"ling5",
  "west" : __DIR__"ling7",
]));

	set("objects",([
	__DIR__"npc/cutter" : 1,
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
