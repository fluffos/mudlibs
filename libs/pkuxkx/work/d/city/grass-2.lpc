// 草地
// edit: by zine Aug 21 2010

inherit __DIR__"skfroom1";
#include <ansi.h>
#include "/d/city/duoergun.h"
void create()
{
	set("short", HIG"草地"NOR);
	set("long", @LONG
一片碧绿的草地，一只小白兔在悠闲地吃着草。南面是一片池塘。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"pool-2",
		"southeast" : __DIR__"zhulin-2",
		"southwest" : __DIR__"pingtai-2",
		"northup" : __DIR__"milinend-2",	
	]));
	set("objects", ([(__DIR__"npc/rabbit") : 1,
	]));
	set("no_task",1);
    set("juemen",1);
	setup();
	::create();
}
