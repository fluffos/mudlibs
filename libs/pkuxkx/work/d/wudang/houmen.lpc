// houmen.c 后门
// by llin

inherit ROOM;

void create()
{
	set("short", "后门");
	set("long", 
"这儿是一道残旧的小木门，门上漆迹斑驳，满是灰尘。可\n"
"以看到门外是一片隐隐郁郁的山林，据说林中有一条小路可到\n"
"天柱峰下，但是数十年来都没听说有人去过。\n"
	);
	set("exits", ([
		"south"  : __DIR__"houyuan",
                "north"  : "/newbiequest/wudang/milin/milin1",
	]));
	setup();
	replace_program(ROOM);
}

