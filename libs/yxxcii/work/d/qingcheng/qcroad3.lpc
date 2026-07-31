//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在青石大道上。远远传来细细的水声，掩盖在路边密密树林的风
声中。望北可以看到一座大山了，苍苍翠翠，象一块清清纯纯的碧玉。
LONG
);
	set("outdoors","qingcheng");
	set("exits", ([
		"south"  : __DIR__"qcroad2",
		"north"  : __DIR__"xiaoqiao",
	]));
	setup();
	replace_program(ROOM);
}

