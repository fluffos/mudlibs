inherit ROOM;

void create()
{
	set("short", "测试房间一");
	set("long", @LONG
测试房间。
LONG);

	set("exits", ([
		"east" : __DIR__"room2",
		"south" : __DIR__"room4"
		]));
	
	setup();
}