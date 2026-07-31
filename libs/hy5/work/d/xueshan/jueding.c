 //      jueding.c 凌霄绝顶

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"绝顶"NOR);
        set("long",@LONG 
这里是大雪山顶峰，人迹罕至，连鸟兽都不见踪影。四面寂静，惟闻风声。
凛冽的山风刮脸如刀，透骨冰凉，平常人只待上一小会就得被冻僵。
LONG);
//        set("objects", ([__DIR__("npc/obj/zanghonghua") : 1 ]));
	set("exits", ([
		"down" : __DIR__"shanpo",
	]));
        set("objects",([
                __DIR__"npc/obj/zanghonghua": 1,
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
    this_player()->move(__DIR__"xuegu");
    this_player()->unconcious();
        }
}
