// by ranger_游侠
// banghui.c
//#include <bangpai.h>

inherit ROOM;

void create()
{
	set("short", "闭关室");
	set("long", "这里是帮内众兄弟闭关的地方，安静异常。");
	set("exits", ([
		"south" : __DIR__"guangchang",
	]));
		set("bangpai_room","1");
    set("close_room", 1);
	set("no_fight","1");
	set("bangpai/biguan",1);
	setup();
}

