//liuzu.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "六祖殿");
	set("long", @LONG
这里是供奉少林六祖的地方。正面是观音，文殊，菩贤，地藏，大势至
等菩萨的玉雕像。两山安放着初祖达摩，二祖惠可，三祖僧璨，四祖道信，
五祖弘忍，六祖慧能的塑像。 
LONG
	);

	set("exits", ([
//		"north" : __DIR__"hguangz2",
                "east" : __DIR__"pingtai",
       ]));
         set("objects",([
		CLASS_D("shaolin") + "/dao-cheng" : 1,
                __DIR__"obj/muchui" : 1,
	]));

		setup();
}



