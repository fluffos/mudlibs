// Room: /d/lumaji/lu8.c

inherit ROOM;

void create()
{
	set("short", "碎石小径");
	set("long", @LONG
这是一条碎石小路，路上来往的行人不少。前面不远处就是
客马店，那是一家小客栈。南面是一家书堂。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lu9",
  "north" : __DIR__"lu7",
  "south" : __DIR__"shutang",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
