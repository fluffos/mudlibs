inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城外。
南边显得很繁忙。东边是一座两层的楼阁，名为春在楼。西面是一座庙庵，
南面是一条笔直的大街，十分繁华。
LONG
	);
        set("outdoors", "suzhou");

	set("exits", ([
		"east" : __DIR__"chunzailou",
		"south" : __DIR__"beidajie1",
                "west" : __DIR__"zijinan",
                "north" : __DIR__"northgate",
	]));

	set("coor/x",110);
  set("coor/y",-200);
   set("coor/z",0);
   set("incity",1);
	setup();
}

