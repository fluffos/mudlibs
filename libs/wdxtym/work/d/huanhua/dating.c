//dating.c

inherit ROOM;

void create()
{
	set("short", "厅堂");
	set("long", @LONG
这里是浣花剑派接待一般来访江湖人物的地方，几张红木太师椅和小几
分列南北两边，两边有几个小童垂手而立，不时过来端茶添水。
LONG
	);

	set("exits", ([
		"east" : __DIR__"guanyuge",
		"west" : __DIR__"xiangfang",
		]));
	set("objects", ([
		  __DIR__"npc/ma" : 1,
	]));


	set("coor/x",60);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
//      replace_program(ROOM);
        "/clone/board/huanhua_b"->foo();
}
