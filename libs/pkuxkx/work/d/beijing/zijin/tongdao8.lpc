// Room: /d/beijing/zijin/tongdao8.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"通道"NOR);
	set("long",
HIC"这是通向出宫的神武门的通道，一侧是数丈高的围
墙，另一侧则是植满花草树木，鸟语花香令人心旷神怡。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"yinghuadian",
  	"east" : __DIR__"shenwumen",
]));
        set("outdoors","beijing");

	setup();
	replace_program(ROOM);
}
