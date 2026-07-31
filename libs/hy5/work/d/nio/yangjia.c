// Room: /u/jpei/thd/yangjia.c

inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
这是一座废弃已久的民房，家具摆设一应俱全，只是都附着一层灰土。屋
子中间是一张小桌，桌上的杯碗还都没有撤去，看来主人去的很匆忙。墙上挂
着一杆铁枪。
LONG
	);

	set("item_desc", ([
		"qiang" : "一杆用旧了的铁枪，看起来原来应该有一对的，不知为何只剩了一杆。",
		"tieqiang" : "一杆用旧了的铁枪，看起来原来应该有一对的，不知为何只剩了一杆。",
	]) );

	set("exits", ([
		"south" : __DIR__"njroad3.c",
	]));

	setup();
	replace_program(ROOM);
}
