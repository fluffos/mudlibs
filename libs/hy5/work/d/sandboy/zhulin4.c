// Room: /d/sandboy/zhulin4.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
一片静谧的竹林，翠绿的竹叶盈盈欲滴，东南方传来砍竹子的咔咔声，
打破了这片宁静，北面有座小尼庵，传出佛呐深唱。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhulin2",
  "north" : __DIR__"zizhuan",
]));

	setup();
	replace_program(ROOM);
}
