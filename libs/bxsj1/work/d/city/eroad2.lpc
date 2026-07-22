// Room: /d/city/eroad2.c

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶着大
车的马夫，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞驰而过，扬起
一路尘埃。马上的人个个身着劲装，衣甲鲜明，有的还随身佩带着刀剑。看来
都是些习武的江湖人。道路两旁是整整齐齐的杨树林。
LONG
	);

	set("exits", ([
		"west" : "/d/group/entry/yzeroad1",
		"southeast" : "/d/changle/road1",
	]));

	set("objects",([
		__DIR__"npc/tangzi" : 2,
                __DIR__"npc/wang" : 1,
                __DIR__"npc/mmr" : 1,
	]));

	set("outdoors", "扬州");
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "caikuang shifu" &&  dir != "west" ) return 0;
	return ::valid_leave(me, dir);
}
