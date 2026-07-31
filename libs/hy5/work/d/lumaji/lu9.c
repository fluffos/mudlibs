// Room: /d/lumaji/lu9.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条土路，一些农户经常往路上波一些水，以免过往的
车马扬起太多的尘土。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu8",
  "east" : __DIR__"lu10",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
