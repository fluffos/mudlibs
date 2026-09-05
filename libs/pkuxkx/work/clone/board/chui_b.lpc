// /clone/board/wiz_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("CHUI巫师留言簿", ({ "board" }) );
	set("location", "/d/wizard/wizard_room_chui");
	set("board_id", "chui_b");
	set("long", "这是一个专供CHUI巫师使用的留言板。\n" );
	setup();
set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

