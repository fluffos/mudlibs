// Room: /d/beijing/zijin/tongdao7.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"通道"NOR);
	set("long",
HIC"这是通向出宫的神武门的通道，一侧是数丈高的围墙，另一侧则
是植满花草树木，鸟语花香令人心旷神怡。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"shenwumen",
  	"south" : __DIR__"hougongmen",
]));
        set("outdoors","beijing");

	setup();
	replace_program(ROOM);
}
