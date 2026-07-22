// Room: /chengdu/qingshidadao2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "青石大道");
	set("long", @LONG
这里是一条青石大道，青石缝中长满了绿油油的青草，道
路两旁整整齐齐的栽着几棵粗壮的柳树。道路上时常有些江湖
人士来来去去，有时还有装有很多箱子的大车经过。从这里往
西便是成都。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "west" : __DIR__"qingshidadao3",
                "east" : __DIR__"qingshidadao1",
	]));

	setup();
	replace_program(ROOM);
}

