// Room: /d/lumaji/lu1.c

inherit ROOM;

void create()
{
	set("short", "鹿马集北口");
	set("long", @LONG
一条狭小的黄土小路斜斜的弯延着，两旁长着高低不齐的杂
草，透过杂草丛，东面的森林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : "/d/kunming/nanmen",
  "south" : __DIR__"lu2",
]));
	set("outdoors", "lumaji");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
