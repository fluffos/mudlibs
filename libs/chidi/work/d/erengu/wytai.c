// erengu.c
// cly@yxjh

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","望月台");
        set("long", @LONG
这望月台基底处于海平面以下的盆地中，但其海拔高度甚至要比地势险恶的
昆仑山更高。说望月台是山，其实也不是。它整个的形状整体上看如同一根铁钉
，下端占地面积很小，四五个成年男人手牵着手就能将其环抱，这根石柱一直向
高处延伸，最顶端却是一块上表面积如普通镖局练武场般大小的巨石。而这石柱
四周光滑得就像刻意雕琢，简直可以称得上是鬼斧神工，甚至连一处能够用来攀
岩的凹洞或突起都没有。因此，这望月台顶端究竟是个甚么模样，连长期居住此
地且武功高强的十大恶人都说不清楚。
LONG );
        set("no_fight", 1);
        set("no_magic",1);
        set("no_kill",1);
        set("no_sleep",1);

        set("objects", ([
    __DIR__"npc/tiezhan" : 1,
        ]) );

		set("exits", ([
			"north" : "/d/gaochang/room63",
		]) );

        setup();

}

