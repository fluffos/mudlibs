// Room: /d/beijing/zijin/kunningmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"坤宁门"NOR);
	set("long",
HIC"这里向南是坤宁宫,向北是御花园。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"north" : __DIR__"yuhuayuan",
  	"south" : __DIR__"kunninggong",
  	"west" : __DIR__"tongdao3",
  	"east" : __DIR__"tongdao6",
]));
        set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
