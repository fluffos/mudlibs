inherit ROOM;

void create()
{
	set("short", "测试房间二");
	set("long", @LONG
测试房间。
LONG);

	set("exits", ([
		"west" : __DIR__"room1",
		"south" : __DIR__"room3",
		]));
	
	setup();
}