// Room: /d/yandang/shandong3.c

inherit ROOM;

void create()
{
	set("short", "含珠洞");
	set("long", @LONG
进入含珠洞,你仔细观看的话,会在石壁上看到一个巨大的太极图,
在两个极眼上,隐隐有点点的光茫发出,走近去,却一无所见,传说这是当
初天神所化.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shandong4",
  "westdown" : __DIR__"shandong1",
]));

	setup();
	replace_program(ROOM);
}
