// /clone/board/emei_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
         set_name(HIG"小竹的电话留言机"NOR, ({ "board" }) );
        set("location", "/u/twist/workroom");
        set("board_id", "twist_b");
        set("long", "这是一个SONY的电话留言机,小竹不在的时候你可以留下你的信息,他会尽快和你联系。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

