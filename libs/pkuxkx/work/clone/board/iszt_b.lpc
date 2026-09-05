// /clone/board/iszt_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("十兆巫师留言簿", ({ "iszt board", "board" }) );
        set("location", "/d/wizard/wizard_room_iszt");
        set("board_id", "iszt_b");
        set("long", HIY"这是一本用芭蕉叶做成的留言簿，有什么事找iszt就写在这里吧。\n"NOR );
        setup();
	set("capacity",30);
	replace_program(BULLETIN_BOARD);
}
