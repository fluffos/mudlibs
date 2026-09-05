// /clone/board/iszt_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name("旭心的留言簿", ({ "zhx board", "board" }) );
        set("location", "/d/wizard/wizard_room_zhx");
        set("board_id", "zhx_b");
        set("long", HIY"这是一本留言簿，有什么事找旭心就写在这里吧。\n"NOR );
        setup();
	set("capacity",30);
	replace_program(BULLETIN_BOARD);
}
