// /clone/board/wiz_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("ALL巫师留言簿", ({ "board" }) );
	set("location", "/d/wizard/wizard_room_all");
	set("board_id", "all_b");
	set("long", "这是一个专供ALL巫师使用的留言板。\n" );
	setup();
set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

