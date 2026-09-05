// 长江天险
// edit: by zine Sep 2 2010

inherit __DIR__"skfroom1";
#include <ansi.h>
#include "qiuyuan.h"

void create()
{
	set("short", "长江天险");
	set("long", @LONG
这里是长江边的一块开阔地。前后四通八达十分适合骑兵布阵绞杀。
LONG
	);
	set("exits", ([ 
       "north" : __DIR__"changjiang-2",
	]));
    set("objects", ([
		__DIR__"npc/mes2" : 1,
	]));
	set("no_task",1);
	setup();
	::create();
}


void init()
{
	add_action("do_back","back");
    add_action("do_qiuyuan","qiuyuan");
	::init();
	return;
}

