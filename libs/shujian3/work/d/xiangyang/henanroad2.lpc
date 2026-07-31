// /d/xiangyang/henanroad2.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在一条土路上，偶尔会有人骑着马匆匆而过，搞得尘土飞扬。这里已
经是河南地界，往西南进入湖北境内。向北边望可以看到嵩山横亘在远处。
LONG
	);
        set("outdoors", "河南");

	set("exits", ([
		"north" : "/d/nanyang/yidao",
		"southwest" : __DIR__"henanroad1",
	]));

	setup();
}
