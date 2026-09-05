// Room: /city/zuixianlou2.c
// YZC 1995/12/04 
// modified by Zine 31/3/2011 加入巫师宴会功能
inherit ROOM;
#include <ansi.h>
#include "/d/city/yanke.h"
void create()
{
	set("name", "宴客厅门厅");
	set("short", "宴客厅门厅");
	set("long", @LONG
这里是烟雨楼宴客厅的门厅，里间是宴客大厅。
LONG);

    set("no_reset",1);
    set("no_clean_up", 1);
	set("no_task",1);
    
	set("exits", ([
                "out" : __DIR__"yanyu2",
                "enter" : __DIR__"yanketing",
		        
	]));
    set("yanke_no","yanke3");
    set("boss","张老版");
    set("place","烟雨楼");
    set("pathway","enter");
    set("save_me","statistics/yanke_3_entry");
	setup();
	
}

void init()
{
    add_action("do_yanke","yanke");
    add_action("do_lingjiang","lingjiang");
}

