// Room: /d/beijing/zijin/tongdao5.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"通道"NOR);
	set("long",
HIC"这是一条大青石铺成的宽敞通道,可供宫中车马通过,两侧是数
丈高的围墙,令人感到庄严肃穆。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
 	"west" : __DIR__"jinghemen",
  	"north" : __DIR__"tongdao6",
 	"south" : __DIR__"tongdao4",
 	"east" : __DIR__"chengqiangong",
]));
        set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
