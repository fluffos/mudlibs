#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
       set_name(HIY"峨嵋派弟子留言板"NOR, ({ "board" }) );
        set("location", "/d/emei/jinding");
        set("board_id", "emei_b");
        set("long", "这是一个供峨嵋派弟子交流的留言板。\n");
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
