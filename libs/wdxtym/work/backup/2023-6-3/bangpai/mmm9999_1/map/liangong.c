
//#include <bangpai.h>
inherit ROOM;

void create()
{
	set("short", "练功区");
	set("long", "这里是兄弟们锻炼武功的地方，宽广而偌大。");
	set("exits", ([
		"north" : __DIR__"guangchang",
	]));
set("practice_room", 1);
	set("no_fight","1");
		set("bangpai_room","1");
		set("bangpai/liangong",1);
	setup();
}

