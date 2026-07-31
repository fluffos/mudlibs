// Room: /d/heifeng/ling5.c

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
  "northup" : __DIR__"ling4",
  "westdown" : __DIR__"ling6",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
