// Room: /u/jpei/thd/guojia.c

inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
这是一座废弃已久的民房，家具摆设一应俱全，只是都附着一层灰土。屋
子中间是一张小桌，桌上的杯碗还都没有撤去，看来主人去的很匆忙。
LONG
	);

	set("exits", ([
		"south" : __DIR__"njroad2.c",
	]));

	setup();
	replace_program(ROOM);
}
