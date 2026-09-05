// /clone/board/shaolin_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(GRN "神龙岛" NOR + RED "留言板" NOR, ({ "board" }) );
        set("location", "/d/shenlongdao/fengding");
    set("board_id", "shenlong_b");
        set("long", "这是一个供神龙教弟子交流的留言板。Advent友情提示：请经常用news命令查看最新消息。\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

