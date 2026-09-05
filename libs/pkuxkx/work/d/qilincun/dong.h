// dong.h
// Created by iszt@pkuxkx, 2007-02-11

#include <ansi.h>

void setshort()
{
	this_object()->set("short", CYN"石洞"NOR);
}

void setlong()
{
	this_object()->set("long", CYN @LONG
这是一个黑漆漆的石洞，周围都是坚硬的石壁。
LONG NOR);
}

void setobject()
{
	this_object()->set("objects", ([
		__DIR__"npc/lev"+random(9) : 1,
		__DIR__"npc/lev"+random(9) : 1,
	]));
}