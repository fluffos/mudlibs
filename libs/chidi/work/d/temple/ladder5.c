#pragma save_binary
// Room: /d/temple/ladder5.c
#include <roadbusy.h>

inherit ROOM;

void create()
{
	set("coor",({1300,4900,15}));
	set("short", "石英岩石阶");
	set("long",
"你正站在这阶梯的起点,纯白色宽敞的石英岩阶梯蜿蜒而上,在青\n"
"翠的山色中形成一条纯白色的巨龙。抬头仰望石阶尽头的那座庙\n"
"宇,虽然无情的岁月已经在它身上留下痕迹,但仍不失其庄严神圣\n"
"的气息。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"ladder4",
  "eastdown" : __DIR__"sroad",
]));
	set("no_clean_up", 0);
	set("outdoors", "snow");

	setup();
//        replace_program(ROOM);
}
