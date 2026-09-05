#include <room.h>
#include "nodie.h"
inherit ROOM;
void create()
{
	set("short", "看台楼下");
	set("long",	"这是比武场旁边的一座阁楼，楼上被用作比武看台，登楼就可以观赏周边四个比
武场中的比武较技。几位锦衣武士侍立在门口，若是技痒想入场一展身手，可让管事
安排。\n"NOR);
	set("exits", ([
		"up" : __DIR__"biwukantai",
		"east" : __DIR__"biwuxiuxi",
		"south" : __DIR__"xixiaomen",
	]));
    set("objects", ([
	    __DIR__"npc/guanshi" : 1,
        ]));
	create_door("east","木门","west",DOOR_CLOSED);
	setup();
}

