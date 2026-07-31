// Room: /jingzhou/dongdajie1.c
// congw 980829

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条宽阔的青石板街道，南边是一座简朴的院子，半月形的大门上
方写着“萧湘书院”四个烫金大字，苍劲有力。里面不时地传来学生们抑扬顿挫
的读书声。北边是一座几层高的白塔，相传是过去一位状元为报母养育之恩而建
造的。
LONG
	);
        set("outdoors", "jingzhou");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"shuyuan",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"baita",
	]));

	setup();
	replace_program(ROOM);
}

