// /clone/board/wiz_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("飞天的访客留言簿", ({ "board" }) );
        set("location", "/u/haiv/wizard_room_zoom");

        set("location", "/u/haiv/wizard_room_haiv");
        set("board_id", "haiv_b");
        set("long", "这是一个haiv的工作间里放置的访客留言簿。\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

