// Room: /d/fengtian/guanlu3.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这条路是通向盛京南门的官道，这里没有市中心那么繁华和
嘈杂，官道上有不少进城和出城的人，再往南远远可以看见盛京
城的南门了，路的东面是巡捕营。
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"s_gate",
  "east" : __DIR__"xunbu",
  "north" : __DIR__"guanlu2",
]));

	setup();
	replace_program(ROOM);
}
