//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "朝阳洞");
	set("long", @LONG
你来到朝阳洞。洞深广数丈，相传是宁封子栖息处。这里也是观日好
去处，“古洞常临光照耀”，正是指旭日东升，霞光透过绿荫，射到洞口
，一片璀灿绚丽的景色。
LONG
);
	set("outdoors","qingcheng");
	set("exits", ([
		"westdown"  : __DIR__"zushidian",
		"northup"   : __DIR__"sanwanjiudao",
	]));
	set("objects", ([
		CLASS_D("qingcheng")+ "/hong" : 1,
	]));
	setup();
	replace_program(ROOM);
}

