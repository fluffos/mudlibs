// Room: /d/tianshui/eroad2.c

inherit ROOM;

void create()
{
	set("short", "小镇东街");
	set("long", @LONG
这条街道熙熙攘攘，操着南腔北调的行人来来往往，很多人
向西边的广场走去。北面是一家镖局，门口立着两个石狮子。南
面是一家铁匠铺，不时传出叮叮当当的打铁声。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"biaoju",
  "south" : __DIR__"tiejiangpu",
  "west" : __DIR__"eroad1",
  "east" : __DIR__"eroad3",
]));
	set("objects",([
	__DIR__"npc/cleaner" : 1,
]));
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
