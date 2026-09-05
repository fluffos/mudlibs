// Room: /city/zuixianlou2.c
// YZC 1995/12/04 
// modified by Zine 31/3/2011 加入巫师宴会功能
inherit ROOM;
#include <ansi.h>
#include <net/dns.h>
#include "/d/city/yanke.h"

void create()
{
	set("name", "宴客厅门厅");
	set("short", "宴客厅门厅");
	set("long", @LONG
这里是醉仙楼的宴客厅的门厅，东面是醉仙楼二楼，西面是宴客厅。
LONG);

    set("no_reset",1);
    set("no_clean_up", 1);
	set("no_task",1);
	set("exits", ([
                "east" : __DIR__"zuixianlou2",
                "west" : __DIR__"yanketing",
		        
	]));

    set("yanke_no","yanke");
    set("boss","冼老版");
    set("place","醉仙楼");
    set("pathway","west");
    set("save_me","statistics/yanke_1_entry");
	setup();
	
}

void init()
{
    add_action("do_yanke","yanke");
    add_action("do_lingjiang","lingjiang");
}

