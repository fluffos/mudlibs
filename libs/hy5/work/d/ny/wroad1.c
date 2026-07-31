
// Room: /d/snow/wroad1.c

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long",
"往西去是兰若寺，向东北有条小路通往竹林，东南有条小路，路上杂草丛生荆棘密布，一股\n"
"淡淡的雾气笼罩在你周围。\n"
);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"wroad2",
  "northeast" : __DIR__"wroad0",
  "west" : __DIR__"wroad3",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/crazy_dog":1,]));
	setup();
	replace_program(ROOM);
}
