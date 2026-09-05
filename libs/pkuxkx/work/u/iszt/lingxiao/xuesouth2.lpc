// File		: xuesouth2.c
// Created By	: iszt@pkuxkx, 2006-09-06

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "尚武书局"NOR);
	set("long", @LONG
这里是凌霄城弟子经营的书局，所以字号也是“尚武”。书局里卖的也
不是圣贤的四书五经，而是一些武功入门书籍。新入凌霄城的弟子可以选上
几本，再向师傅请教就可以事半功倍了。至于外人，稍稍了解一下雪山剑法
也无妨。
LONG);
	
	set("indoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"xuejie2",
	]));
	set("objects", ([
		__DIR__"npc/jiawanyu" : 1,
	]));

	setup();
}