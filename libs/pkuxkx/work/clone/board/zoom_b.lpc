// /clone/board/wiz_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("飞天的访客留言簿", ({ "board" }) );
	set("location", "/d/wizard/wizard_room_zoom");
	set("board_id", "zoom_b");
	set("long", "这是一个飞天的工作间里放置的访客留言簿。\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

