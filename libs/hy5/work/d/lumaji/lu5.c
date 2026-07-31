// Room: /d/lumaji/lu5.c

inherit ROOM;

void create()
{
	set("short", "碎石小径");
	set("long", @LONG
一条碎石铺成的小路，中间长着一些杂草。路的左边是一户
农房，住得是当地的村民。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nongju",
  "south" : __DIR__"lu6",
  "north" : __DIR__"lu4",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
