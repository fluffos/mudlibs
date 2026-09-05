// /clone/board/wudang_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(YEL "灵鹫宫" NOR + CYN "留言版" NOR, ({ "board" }) );
        set("location", "/d/lingjiu/zhengting");
        set("board_id", "lingjiu_b");
        set("long", "这是一个供灵鹫宫门下交流的留言板。\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
