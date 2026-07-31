// Room: /u/zqb/tiezhang/shangu-1.c

inherit ROOM;

void create()
{
	set("short", "山谷");
	set("long", @LONG
    你走在一条狭窄的山谷之中，两旁山峰壁立，直插云霄。鸟鸣猿 
啼之声，回荡在寂静的空谷之中。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"shangu-2",
  "southwest" : __DIR__"pingtai",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}
