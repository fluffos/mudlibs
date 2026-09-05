#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{

        set_name(BBLU+HIW "大轮寺" NOR +BBLU+ HIY "留言版" NOR, ({ "board" }) );
        set("location", "/d/dalunsi/guangchang");

        set("board_id", "dls_b");
        set("long", "这里是大轮寺的留言板，有什么心得体会就写这里吧。\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
