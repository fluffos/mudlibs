// Room: /d/xiaoyao/shulin1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼天
大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出的声响。
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  "/d/mengpai/xydizi" : 3,
]));
	set("outdoors", "xiaoyao");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xiaodao4",
  "north" : __DIR__"shulin1",
  "east" : __DIR__"shulin2",
  "south" : __DIR__"shulin1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
