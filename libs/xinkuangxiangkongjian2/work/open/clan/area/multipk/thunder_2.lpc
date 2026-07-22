// thunder_2.c by ACKY

inherit ROOM;
#include <ansi.h>
#include "thunder.msg"

void create()
{
	set( "short", HIY"卍迅雷峰卍"NOR );
	set( "long", (: print_msg :) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );    
        set( "exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"thunder_1",
		"south" : __DIR__"thunder_5",
		"east"  : __DIR__"thunder_3",
	]));
        setup();
}

