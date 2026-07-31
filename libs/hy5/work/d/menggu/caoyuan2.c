// Room: /d/menggu/caoyuan2.c

inherit ROOM;

void create()
{
	set("short", "蒙古草原");
	set("long", @LONG
广袤无垠的漠北草原,成群的牛羊的白云下奔跑,骑着骏马的游牧人
挥舞着手中的长鞭,塞北的草原.南边去是到中原,北面过去就是铁木真的
营帐.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"caoyuan3",
  "north" : __DIR__"caoyuan",
]));

	setup();
	replace_program(ROOM);
}
