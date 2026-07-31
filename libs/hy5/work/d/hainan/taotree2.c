// Room: /d/hainan/taotree2.c

inherit ROOM;

void create()
{
	set("short", "桃花林");
	set("long", @LONG
绚烂的桃花开得正艳,你却再也看不清回去的路了.眼前只是一片粉 
红色的花海.听天由命吧,走到哪算哪了......咦,你好象听到哪儿传来一 
阵女子的嬉笑声. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"taotree3",
  "south" : __DIR__"taotree1",
  "west" : __DIR__"taotree1",
  "east" : __DIR__"taotree1",
]));
	set("outdoors", "/d/hainan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/huaban.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
