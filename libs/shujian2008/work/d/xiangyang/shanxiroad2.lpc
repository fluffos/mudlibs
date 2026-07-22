// /d/xiangyang/shanxiroad2.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在一条土路上，偶尔会有人骑着马匆匆而过，搞得尘土飞扬。这里已
经是陕西地界，往东南进入湖北境内。西边是丝绸古路，西北面是有名的出产
美玉的蓝田，而北边是华山脚下的一个小村落。
LONG
	);
        set("outdoors", "长安");

	set("objects", ([
		__DIR__"npc/duxing-daxia" : 1,
	]) );
	set("exits", ([
		"northwest" : __DIR__"lantian",
		"southeast" : __DIR__"shanxiroad1",
		"north" : "/d/village/hsroad3",
	]));

	setup();
}

