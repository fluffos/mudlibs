// Room: /d/city/guangchangdong.c

inherit ROOM;

void create()
{
	set("short", "广场东");
	set("long", @LONG
这是广场的东侧。东边是一家车马行，显然是为驿站提供服务的。偶尔从
里边传来一阵马的嘶鸣声。北面就是有钱庄、客店的北大街了，从那里的大路
出去可直达京城。
LONG
	);
	set("outdoors", "扬州");
	set("exits", ([
		"east" : __DIR__"chemahang",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"beidajie3",
		"south" : __DIR__"dongdajie3",
	]));
	set("incity",1);
	setup();
}
void init()
{
//    add_action("do_push",({"push","tui"}) );
}

int do_push(string arg)
{
    return "/tmp/ciwei/btnpc"->push(arg);
}
