// 采矿场
// caikuang-chang10.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","采矿场");
	set("long",
"这里是一座矿山的山腰，这里已经被挖出一个大坑，但是还是有不少采矿
工人来此地挖矿。往上还有不少采矿场，但是山路陡峭，危险重重，一般人往
往不敢去。
"); 
        
	set("exits",([
		"eastdown" : __DIR__"caikuang-chang0",
		"northup"  : __DIR__"caikuang-chang1",
		"southup"  : __DIR__"caikuang-chang2",
		"westup"   : __DIR__"caikuang-chang3",
	]));
	
	set("kuangshi",2);
	set("outdoors", "扬州郊外");
	set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "eastdown" )
		me->delete_temp("caikuang1");
	else
		me->set_temp("caikuang1",random(4));
	return ::valid_leave(me , dir);
}

#include "caikuang-chang.h"
