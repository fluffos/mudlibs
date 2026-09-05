// Room: /d/beijing/zijin/tongdao2.c
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
  	"west" : __DIR__"yikungong",
 	"north" : __DIR__"tongdao3",
 	"south" : __DIR__"tongdao1",
  	"east" : __DIR__"longfumen",
]));
        set("outdoors","beijing");


	setup();
	replace_program(ROOM);
}
