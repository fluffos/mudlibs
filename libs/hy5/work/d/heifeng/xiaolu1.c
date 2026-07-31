// Room: /d/heifeng/xiaolu1.c

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
  "south" : __DIR__"two",
  "west" : __DIR__"shanquan",
  "east" : __DIR__"xiaolu2",
]));
        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));

	set("outdoors","heifeng");

	setup();
	replace_program(ROOM);
}
