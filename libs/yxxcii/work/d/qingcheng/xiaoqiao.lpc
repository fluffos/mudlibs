//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "小桥");
	set("long", @LONG
小桥横跨小溪上。溪水清澈，游鱼卵石斑驳可数。桥北面就是青城建
福宫了。青城是道家发轫之处，号道教的“第五洞天”，相传东汉张陵在
此结庐传授五斗米道，至今宫阙连绵，传道嗣法不绝。
LONG
);
	set("outdoors","qingcheng");
	set("exits", ([
		"south" : __DIR__"qcroad3",
		"north" : __DIR__"jianfugong",
	]));
	setup();
	replace_program(ROOM);
}

