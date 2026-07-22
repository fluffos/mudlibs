// Room: /d/city/dongdajie2.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。东边不时地传来金属撞击
声，西边人声嘈杂。北边是一座简朴的院子，半月形的大门上方写着“白鹿书
院”四个烫金大字，苍劲有力。里面不时地传来学生们抑扬顿挫的读书声。南
边是一家杂货铺。
LONG
	);
        set("outdoors", "扬州");

        set("objects", ([
                CLASS_D("gaibang") + "/kong" : 1,
        ]));

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"zahuopu",
	        "west" : __DIR__"dongdajie3",
		"north" : __DIR__"shuyuan",
	]));

	set("coor/x",110);
  set("coor/y",-10);
   set("coor/z",0);
   setup();
}

