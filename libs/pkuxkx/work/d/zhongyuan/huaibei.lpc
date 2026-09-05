
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "淮北");
set("occupied",1);
	set("long", 
"淮北地处三省之交界，淮海之腹心，立来是兵家必争之地。
 此地驻有重兵，盘查南来北往的行人，并负责翦灭附近山上的
 草寇。\n"
	);

	set("exits", ([
		"west" : __DIR__"guandao2",
		"southeast" : __DIR__"guandao3",
        "northeast" : __DIR__"guandao4",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "zhongyuan");
	setup();
}



