// Room: binglinfeng.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "冰林峰");
	set("long", @LONG
这里是大雪山最高的山峰，终年覆盖在冰雪之中，气候寒冷。在凛冽的山风
积年累月的吹拂下，形成了高约几丈到十几丈不等的座座冰柱，远远望去，犹如
冰雪林海。每当晴天，阳光照耀下就会幻发出种种奇特的光晕，景色美不胜收。
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanpo",
	]));
	setup();
}
void init()
{
        mixed *local;
    
        local = localtime(time() * 60);
        if (local[2] < 11 || local[2] > 13) {
	message_vision(HIW
"狂风夹着雪花劈头盖脸打了过来，吹得$N睁不开眼。突然从山崖边落下一大块积雪，$N躲闪不及正砸在头上！\n"NOR,this_player());
	message_vision(HIR"$N脚下不稳，顺着山崖跌落下去。\n"NOR,this_player());
	this_player()->unconcious();
	this_player()->move(__DIR__"xuegu");
        }
}