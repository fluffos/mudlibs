// Room: /d/heifeng/xiaolu4.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这里是黑风寨后面的一条小路，四周静悄悄的似乎这里很少
有人来，路边生满了野草。偶尔能碰到一两个寨丁，也是匆匆忙
忙的路过。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lin4",
  "south" : __DIR__"xiaolu3",
  "east" : __DIR__"lin5",
  "north" : __DIR__"houshan",
]));
        set("objects", ([
             __DIR__"npc/toumu2" : 2,

        ]));
	set("outdoors","heifeng");

	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("tou mu", environment(me))) && 
		dir == "north")
		return notify_fail("强盗头目说道:后山禁地，禁止入内。\n");


	return ::valid_leave(me, dir);
}
