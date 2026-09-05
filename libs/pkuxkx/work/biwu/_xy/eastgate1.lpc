// Room: /clone/misc/eastgate1.c
// Date: by jason(尔好啊) Tue Nov 17 15:39:52 2009
// edit by zine Aug 21 2010
#include <ansi.h>
inherit "/biwu/biwuroom2";

void create()
{
	set("short", CYN"震华门"NOR);
	set("long", @LONG
真正踏入襄阳古战场后，你想起一个个传奇的名字，郭靖，杨过，黄药师，
你不由豪情万丈。“震华门”三个大字在阳光下让人不敢逼视。似乎这里有个瓮
城，黑洞洞的你却看不清楚。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"eaststreet",
	    "enter" : __DIR__"innercitye",
  	    "east" : __DIR__"eastgate",
	]));
	set("no_clean_up", 0);
	setup();
}

#include "kuijiaku.h"