//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "古龙桥");
	set("long", @LONG
你走在古龙桥上。望见岩壁上一个大裂槽。宽二十余丈深，深达六、
七丈，传说是张天师降魔时以笔划山而过的仙家痕迹。
LONG
);
	set("outdoors","qingcheng");
	set("exits", ([
		"northup"   : __DIR__"zushidian",
		"southdown" : __DIR__"tianshidong",
	]));
	setup();
	replace_program(ROOM);
}

