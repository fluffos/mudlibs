//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "呼应亭");
	set("long", @LONG
呼应亭高居彭祖峰顶，是青城最高处。登临长啸，余音回荡，众山皆
应。看雪岭光腾，红吞沧海，锦江春涨，绿到瀛洲。夏日夜分，有圣灯浮
云，传说是神仙朝贺张天师所点仙灯，看来让人感叹不已。
LONG
);
	set("outdoors","qingcheng");
	set("exits", ([
		"eastdown" : __DIR__"shangqing",
	]));
	set("objects", ([
		CLASS_D("qingcheng") + "/hou" : 1,
	]));

	setup();
	replace_program(ROOM);
}

