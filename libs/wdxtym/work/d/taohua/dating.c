// dating.c

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", "桃花山庄正厅");
    set("long", 
"这里是桃花山庄的正厅。整个大厅十分宽阔。厅中挂满了各种\n"
"名家的书法真迹。但最显眼的则是正中挂的一幅对联：\n\n"
   
BLU "	    桃花影落飞神剑\n"
    "	    碧海潮生按玉箫\n\n"
NOR

"字体遒劲挺拔，气势宏伟。\n"
);
	set("exits", ([
	    "north" : __DIR__"qianyuan",
	    "south" : __DIR__"houyuan",
	    "east"  : __DIR__"daojufang",
	    "west"  : __DIR__"wofang" ,
	]));
	set("objects", ([
	    "/kungfu/class/taohua/huang" : 1,
	]) );    
	set("valid_startroom", 1);
	set("no_beg", "1");
	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (! objectp(guarder = present("huang yaoshi", this_object())))
	{
		return 1;
	}

	if (dir == "south" || dir == "east")
		return guarder->permit_pass(me, dir);

	return 1;
}
