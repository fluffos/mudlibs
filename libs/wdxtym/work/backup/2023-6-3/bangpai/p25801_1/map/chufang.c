// by ranger_游侠
// banghui.c
//#include <bangpai.h>
inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", "这里是厨房，兄弟们聚餐的地方。");
	set("exits", ([
		"west" : __DIR__"guangchang",
		"south" : __DIR__"caiyuan",
	]));
	
	
	set("action_list", ([
		"做菜" : "cook",
		"停止" : "halt_cooking",
		]));
		
	set("bangpai_room","1");
	set("no_fight","1");
	set("bangpai/chufang",1);
	setup();
}


void init()
{
	add_action("do_cook", "cook");
	add_action("do_halt_cooking", "halt_cooking");
}

int do_cook(string arg)
{
	"/d/bangpai/cook/cook"->do_cook(arg, this_player(), this_object());
	return 1;
}

int do_halt_cooking(string arg)
{
	"/d/bangpai/cook/cook"->do_halt_cooking(arg, this_player());
	return 1;
}
