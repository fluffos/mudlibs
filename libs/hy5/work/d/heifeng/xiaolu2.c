// Room: /d/heifeng/xiaolu2.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是黑风寨后面的一条小路，四周静悄悄的似乎这里很少
有人来，路边生满了野草。偶尔能碰到一两个寨丁，也是匆匆忙
忙的路过。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"first",
  "west" : __DIR__"xiaolu1",
  "east" : __DIR__"xiaolu3",
]));

	set("outdoors","heifeng");

	setup();
	replace_program(ROOM);
}
