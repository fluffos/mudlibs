// Room: /d/sandboy/reed.c

inherit ROOM;

void create()
{
	set("short", "芦苇荡");
	set("long", @LONG
一片绿色的芦苇荡,密密麻麻的芦苇顶上开出了白色的芦花,微风吹过,
白色的芦花漫天飞舞.南面是一片杂草丛.
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"inreed",
  "south" : __DIR__"inturf",
]));

	setup();
	replace_program(ROOM);
}
