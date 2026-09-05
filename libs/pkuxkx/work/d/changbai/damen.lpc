// /guanwai/damen.c

inherit ROOM;
#include "/d/changbai/caishen.h";

void create()
{
	set("short", "达门");
	set("long", @LONG
天池三面壅注不流，惟独北面偏东一线斜垂，白练飞舞，这就是达门。
池水经达门外流，水流清冷，在石壁间冲撞有声。据说在这周围的杂草
之中就生长着人参，不知道搜索一下能否有所发现。
LONG );
	set("exits", ([
		"southwest"  : __DIR__"longmf",
//		"northwest"  : __DIR__"pubu",
	]));
	set("objects", ([

//		"/d/city4/npc/pettrainer4":1,
	]));
	set("outdoors", "changbai");

        set("count", random(3) + 1);
        set("beast", random(5) + 1);

	setup();

}
