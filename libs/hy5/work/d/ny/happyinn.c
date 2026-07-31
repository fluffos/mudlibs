
// Room: /d/snow/happyinn2.c
#include <ansi.h>
inherit ROOM;
int mark_book;
void create()
{
	set("short", "塞外要塞内室");
	set("long",
"这是一间宽敞明亮的卧房，屋中有一张宽大的床，屋中的摆设虽然很豪华，但是透出一股俗\n"
"气。你总是觉得有一些古怪，但又看不出来。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"happyinn2",
]));
	set("no_clean_up", 0);
	mark_book=1;
	setup();
}

