// Room: /d/xueshan/dating.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是寺内的大厅，几位有道的高僧在高声辩论。
LONG
);
	set("no_new_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/tielun" : 2,
  "/kungfu/class/xueshan/fawang" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zoulang2",
  "northeast" : __DIR__"chanshi",
  "northwest" : __DIR__"cangjingge",
  "east" : __DIR__"zoulang1",
]));

	setup();
	replace_program(ROOM);
}
