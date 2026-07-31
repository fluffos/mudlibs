// Room: /open/dt/yeweizhai.c

inherit ROOM;

void create()
{
	set("short", "野味斋");
	set("long", @LONG
这里的生意特别红火，因为烧制野味的师父据说以前是皇宫
里的御厨，专门给皇帝烧制野味的，轩主人花了很大的代价把他
从皇宫里请出来，如今普通的老百姓也能够吃到风味绝佳的野味
了。这里的野味全部是城里的一个猎人周喜儿送来的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"youfujie2",
]));

	setup();
	replace_program(ROOM);
}
