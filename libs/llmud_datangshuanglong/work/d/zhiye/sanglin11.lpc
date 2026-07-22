// 农田
// sanglin11.c
// augx@sj 10/17/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","桑林");
	set("long",
"这是片很大的桑树林，桑树长的都很茂盛，你可以在这里养蚕(yangcan)。
而养蚕需要注意喂食(weishi)，清扫(qingsao)，和抽丝(chousi)。
"); 
        
	set("exits",([
		"out" : __DIR__"sanglin1",
	]));
	
	set("outdoors", "长安郊外");
	set("incity",1);
	set("exam",0);
	setup();
}

#include "sanglin.h"
