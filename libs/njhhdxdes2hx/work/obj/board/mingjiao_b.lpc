// /clone/board/wudang_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(YEL "明教" NOR + CYN "留言版" NOR, ({ "board" }) );
        set("location", "/d/mingjiao/dadian");
        set("board_id", "mingjiao_b");
        set("long", "这是一个供明教门下交流的留言班。\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
