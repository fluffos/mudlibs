// Room: /d/fengtian/guanlu2.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这条路是通向盛京南门的官道，这里没有市中心那么繁华和
嘈杂，官道上有不少进城和出城的人，再往南远远可以看见盛京
城的南门了。
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guanlu3",
  "north" : __DIR__"lukou",
]));

	set("objects",([
		"/clone/npc/man" : 2,
]));

	setup();
	replace_program(ROOM);
}
