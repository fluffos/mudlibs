// Room: /d/heifeng/lu9.c

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
这是一片浓密的小树林，树影婆娑，偶尔一阵山风吹来树叶
沙沙做响，使人不寒而颤。北面浓密的树木间隐约有一条向上的
小道黑漆漆的不知通往哪里。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"lu8",
  "northup" : __DIR__"lu10",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
