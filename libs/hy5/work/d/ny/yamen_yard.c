
// Room: /d/snow/yamen_yard.c
#include <room.h>
inherit ROOM;

void create()
{
	set("coor",({-70,4870,10}));
	set("short", "衙门大院");
	set("long",
"这里是衙门前的衙门大院，人来人往，熙熙攘攘非常热闹，经常有人叫卖着。不时有一两个衙役\n"
"穿梭其中。\n"
);
	set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yamen_gate",
  "west" : __DIR__"yamen",
]));
	set("no_clean_up", 1);


	setup();
	replace_program(ROOM);
}
