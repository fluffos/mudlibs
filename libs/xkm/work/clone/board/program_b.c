//program's board

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
 set_name(HIY"雁过留声"NOR, ({ "board" }) );
 set("location", "/u/program/workroom");
 set("board_id", "program_b");
 set("long",HIG"留下你的心情。\n"NOR );
 setup();
 set("capacity", 100);
 replace_program(BULLETIN_BOARD);
}
