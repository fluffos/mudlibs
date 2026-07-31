// by ranger_游侠
// banghui.c
//#include <bangpai.h>
inherit ROOM;

void create()
{
	set("short", "炼丹房");
	set("long", "这里是帮内炼丹的地方，周围炼丹炉林立，火焰升腾。");
	set("exits", ([
		"east" : __DIR__"guangchang",
	]));
	set("bangpai_room","1");
	set("no_fight","1");
	set("bangpai/liandan",1);
	setup();
}

