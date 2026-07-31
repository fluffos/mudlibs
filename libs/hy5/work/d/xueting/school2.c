// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "淳风武馆教练场");
        set("long", @LONG
你现在正站在一个宽敞的教练场中，地上铺著黄色的细砂，许
多人正在这里努力地操练著，北边是一间高大的兵器厅，往东则是
武馆师父们休息的大厅。
LONG
        );
       set("no_beg",1);
       set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"weapon_storage",
	"west"  : __DIR__"school1",
	"east"  : __DIR__"schoolhall",
]));
        set("objects", ([ /* sizeof() == 2 */
//  "/d/snow/npc/trainee" : 8,
//  "/d/snow/npc/fist_trainer" : 1,
	__DIR__"npc/wgdizi":6,
	]));
        set("outdoors", "xueting");

        create_door("west", "红漆大门", "east", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}
