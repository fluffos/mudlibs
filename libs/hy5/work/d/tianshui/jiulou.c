// Room: /xiaozhen/jiulou.c

inherit ROOM;

void create()
{
	set("short", "醉仙阁");
	set("long", @LONG
醉仙楼在这里远近闻名，楼内高朋满座，食客们吆五喝六，
跑堂的小二进进出出端酒送菜，招呼客人，楼上是雅座。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"nroad1",
  "up" : __DIR__"jiulou2",
]));

	
	set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/paotang" : 1,
]));

	setup();
	replace_program(ROOM);
}
