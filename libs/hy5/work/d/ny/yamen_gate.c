
// Room: /d/snow/yamen_gate.c

#include <room.h>
inherit ROOM;


void create()
{
	set("coor",({-60,4870,10}));
	set("short", "县衙大门");
	set("long",
"这里就是宁远城县衙大门,厚重的门边站着两个精神抖擞的衙役,右手边放着一面硕大的牛皮\n"
"鼓!\n"
);

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/judge_guard" : 2,
]));
	set("outdoors", "ny");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yamen_yard",
    "southeast" : __DIR__"yamen_square",
]));
    set("no_fight",0);
	set("no_clean_up", 0 );
	setup();
}

