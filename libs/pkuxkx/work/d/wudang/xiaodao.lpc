// xiaodao.c 小道
// by llin

inherit ROOM;

void create()
{
	set("short", "小道");
	set("long", 
"一条碎石小道，北面是灵霄宫的院墙，可以看到墙外郁郁\n"
"葱葱的松树，墙下是一汪泉眼，泉水绕着墙根潺潺的流着。好\n"
"一处怡静的所在。西面是一座阁楼，里面一片寂静。\n"
	);

	set("exits", ([
		"west" : __DIR__"jingxiu",
		"east" : __DIR__"houtang",
	]));
	setup();
	replace_program(ROOM);
}

