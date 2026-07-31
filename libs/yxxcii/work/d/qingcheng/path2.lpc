//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "青城山路");
	set("long", @LONG
你走在青城山路上。山木蔽日，幽静宜人。西上就是天师洞，东边是
天然图画。
LONG
);
	set("outdoors","qingcheng");
	set("exits", ([
		"westup"   : __DIR__"tianshidong",
		"eastdown" : __DIR__"tianran",
	]));

	setup();
	replace_program(ROOM);
}

