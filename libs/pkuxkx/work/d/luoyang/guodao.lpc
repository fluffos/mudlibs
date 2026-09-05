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
这里是望星楼宴客厅的门厅，东面是望星楼四层，西面是宴客厅。
LONG);

    set("no_reset",1);
    set("no_clean_up", 1);
	set("no_task",1);
    
	set("exits", ([
                "east" : __DIR__"wangxinglou4",
                "west" : __DIR__"yanketing",
		        
	]));
    set("yanke_no","yanke2");
    set("boss","杜老版");
    set("place","望星楼");
    set("pathway","west");
    set("save_me","statistics/yanke_2_entry");
	setup();
	
}

void init()
{
    add_action("do_yanke","yanke");
    add_action("do_lingjiang","lingjiang");
}

