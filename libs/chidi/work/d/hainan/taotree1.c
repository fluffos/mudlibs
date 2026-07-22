// Room: /d/hainan/taotree1.c

inherit ROOM;

void create()
{
	set("short", "桃花林");
	set("long", @LONG
绚烂的桃花开得正艳,你却再也看不清回去的路了.眼前只是一片粉
红色的花海.听天由命吧,走到哪算哪了......
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"outtree",
  "east" : __DIR__"taotree1",
  "north" : __DIR__"taotree1",
  "west" : __DIR__"taotree2",
]));

	setup();
	replace_program(ROOM);
}
