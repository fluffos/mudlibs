// Room: /d/fengtian/guanlu1.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这条路是连接盛京西门和威远路的官道，这里没有市中心那
么繁华和嘈杂，官道上有不少进城和出城的人，再往西远远可以
看见盛京城的西门了。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"w_gate",
  "east" : __DIR__"wy1",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
