// Room: /d/lumaji/lu6.c

inherit ROOM;

void create()
{
	set("short", "碎石小径");
	set("long", @LONG
你走在碎石路上，不时有村民从你身边经过。路的右边是一
座大院，不时传出马叫的声音。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu7",
  "east" : __DIR__"yuan",
  "north" : __DIR__"lu5",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
