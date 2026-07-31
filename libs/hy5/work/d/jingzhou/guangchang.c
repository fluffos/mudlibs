// Room: /d/jingzhou/guangchang
// netkill /98/8/14/        congw /98/08/29 modify


inherit ROOM;

void create()
{
        set("short", "荆州中心" );
        set("long", @LONG
这里是荆州的中心要十字路口，人来人往，很是热闹，南边住着一些
本城的富人，北边是官府，真是一个好地方啊。许多从四川来的人都在此
落脚，休息以后再赶路。
LONG
        );
        set("exits", ([
		"east" : __DIR__"dongdajie1",
 		"west" : __DIR__"xidajie1",
		"north" :__DIR__"beidajie1",
 	        "south" :__DIR__"nandajie1",
	]));
	//set("no_fight",1);

//set("objects", ([
//	"/tudi":1,//测试任务系统使用 JackyBoy
//        "/d/npc/bukuai" : 1,
//  ]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
//	call_other("/clone/board/quest_b","???");
        replace_program(ROOM);
}

