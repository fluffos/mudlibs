inherit ROOM;

void create()
{
	set("short", "测试房间四");
	set("long", @LONG
测试房间。
LONG);

	set("exits", ([
		"east" : __DIR__"room3",
		"north" : __DIR__"room1",
		]));
	
	setup();
}