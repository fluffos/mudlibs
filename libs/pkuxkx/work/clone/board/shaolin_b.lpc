// /clone/board/shaolin_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(GRN "少林" NOR + RED "风波录" NOR, ({ "board" }) );
	set("location", "/d/shaolin/guangchang1");
	set("board_id", "shaolin_b");
	set("long", "这是一个供少林弟子交流的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
