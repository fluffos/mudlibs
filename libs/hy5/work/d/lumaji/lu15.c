// Room: /d/lumaji/lu15.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走到这里，只看见路边堆着一垛垛干柴，柴堆北面有一间
平房。再向东去，则是一片树林。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu14",
  "east" : __DIR__"lu16",
  "north" : __DIR__"ws_home",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
