// /clone/board/gaibang_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name(HIY"大明圣旨"NOR, ({ "board" }) );
	set("location", "/d/yingtianfu/neicheng/shengzhi");
	set("board_id", "daming_notice_b");
	set("long", "这是一个大明圣旨发布的地方。\n" );
	setup();
	set("capacity", 35);
	
}

int do_post(string arg)
{
	if (this_player()->query("id")!="zine")
		return notify_fail("你不能在这留言。\n");
	return ::do_post(arg);
}

int do_read(string arg)
{
	if (!this_player()->query("mingpin")&&!this_player()->query("ming/tj/pin"))
		return notify_fail("你不是大明官员也不是内廷官员，不能阅读大明金榜。\n");
	return ::do_read(arg);
}