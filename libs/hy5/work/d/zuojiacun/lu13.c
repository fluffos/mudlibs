// Room: /d/zuojiacun/lu13.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条坑坑洼洼小路，你一脚深一脚浅地走在上面，路边
几个妇女正在家门口洗衣，看到你走路的样子，抬着头嬉笑了起
来。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu14",
  "west" : __DIR__"business",
  "east" : __DIR__"ju2",	
  "north" : __DIR__"lu12",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
