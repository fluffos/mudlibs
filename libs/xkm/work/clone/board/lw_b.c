// /clone/board/lw_b.c

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
 set_name(HIW"发礼物记录"NOR, ({ "board" }) );
   set("location", "/d/wizard/flw_room");
set("board_id", "lw_b");
	set("long", "这是各位巫师用来记录所发礼物用的。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
