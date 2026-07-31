//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

int do_out(string arg);

void create()
{
	set("short", "小桥");
	set("long",@LONG
这是一座破旧的石桥，桥下是护城河缓缓的流水。水看上去很清，这
里是进皇宫后门的必经之路。
LONG
);
	set("outdoors", "city2");
	set("exits", ([
		"north" : __DIR__"di_anmen",
	]));

	setup();
	replace_program(ROOM);
}


