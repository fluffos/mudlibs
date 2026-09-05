// Room: /d/beijing/zijin/tihedian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"体和殿"NOR);
	set("long",
HIC"皇太后住储秀宫时,在此用膳,体和殿面阔五间，前后开门，
当中一间为过道，可以进出。东二间相连，西二间亦相通，为其
饭后饮茶的休息室。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"yikungong",
  	"north" : __DIR__"chuxiugong",
]));

	setup();
	replace_program(ROOM);
}
