// Room: /d/sandboy/zhulin5.c

inherit ROOM;

void create()
{
	set("short", "翠微亭");
	set("long", @LONG
这是一座小巧的竹亭，完全用附近天然的竹子搭建而成，几株粗壮
的紫竹就是支撑亭子的主力，亭中一张竹编的矮几上还摆了几枝鲜花。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhulin2",
  "east" : __DIR__"zhulin3",
]));
	set("outdoors", "/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yingwu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
