// 采矿场
// caikuang-chang13.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","采矿场");
	set("long",
"这里是一座矿山的一个山峰，这里已经被挖出一个大坑，但是还是有不少
采矿工人来此地挖矿。
"); 
        
	set("exits",([
		"out" : __DIR__"caikuang-chang3",
	]));
	
	set("kuangshi",30);
	set("outdoors", "扬州郊外");
	set("incity",1);
	setup();
}

#include "caikuang-chang.h"