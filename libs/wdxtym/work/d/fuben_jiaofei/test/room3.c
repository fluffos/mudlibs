inherit ROOM;

void create()
{
	set("short", "测试房间三");
	set("long", @LONG
测试房间。
LONG);

	set("exits", ([
		"west" : __DIR__"room4",
		"north" : __DIR__"room2",
		]));
	
	setup();
}