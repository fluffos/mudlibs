// Room: /d/lumaji/lu14.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走到这里，只见一些村妇正拿着盆在路边洗衣服，看到你
过来，冲你笑了笑又低下头忙自己的事了。还有一些小孩子正在
路边玩耍。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu12",
  "east" : __DIR__"lu15",
  "south" : __DIR__"caifeng",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
