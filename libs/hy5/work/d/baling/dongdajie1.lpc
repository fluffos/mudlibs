// baling/dongdajie1
// Room in 龟兹 
// laowuwu 99/04/11 

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西边人声嘈杂。北
边是一座简朴的院子，半月形的大门上方写着“燕山书屋”四个大字，
苍劲有力。里面不时地传来学生们抑扬顿挫的读书声。南边是一家客栈。
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"east" : __DIR__"dongmen",
		"west" : __DIR__"guangchang",
		"south" : __DIR__"kedian",
		"north" : __DIR__"shuyuan",
	]));
          set("objects", ([
              "/clone/misc/dache" : 1,
        ]) );
	setup();
	replace_program(ROOM);
}

