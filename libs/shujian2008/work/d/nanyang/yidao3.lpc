// Room: /d/nanyang/yidao3.c

inherit ROOM;
void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶着大
车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身
边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。东面有一条小路
通向树林深处。
LONG
	);
	set("outdoors", "南阳");
	set("exits", ([
		"south" : __DIR__"nanyang",
		"north" : "/d/shaolin/ruzhou",
                "east" : __DIR__"yidao4",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && me->query_temp("sljob"))
		return notify_fail("那处强盗出没，比较危险，还是走大道吧。\n");
	return ::valid_leave(me, dir);
}
