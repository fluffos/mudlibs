#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIW"转站记录"NOR, ({ "board" }) );
set("location", "/u/londe/workroom");
set("board_id", "zz_b");
set("long", "转站记录留言板。\n" );
setup();
set("capacity", 100);
replace_program(BULLETIN_BOARD);
}
