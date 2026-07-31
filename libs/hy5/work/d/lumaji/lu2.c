// Room: /d/lumaji/lu2.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
一条狭小的黄土小路斜斜的弯延着，两旁长着高低不齐的杂
草，透过杂草，你可以看到东面的森林。路的左侧歪斜着插着一
个木牌，上面写着“鹿马集”。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lu3",
  "north" : __DIR__"lu1",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
