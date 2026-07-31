// Room: /d/lumaji/lu10.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一个路口，有一条向南的小路通向村外。路边种着一些
果树，看起来像是桃树。北面是一家肉铺。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s_kou",
  "west" : __DIR__"lu9",
  "east" : __DIR__"lu11",
  "north" : __DIR__"roupu",
]));
	set("objects", ([
		"/clone/npc/man" : 2,
	]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
