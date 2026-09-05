// /clone/board/gaibang_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name(HIY"大宋圣旨"NOR, ({ "board" }) );
	set("location", "/d/song/record/positions");
	set("board_id", "dasong_notice_b");
	set("long", "这是一个大明圣旨发布的地方。\n" );
	setup();
	set("capacity", 35);
	
}

int do_post(string arg)
{
	if (!wizardp(this_player()))
		return notify_fail("你不能在这留言。\n");
	return ::do_post(arg);
}
