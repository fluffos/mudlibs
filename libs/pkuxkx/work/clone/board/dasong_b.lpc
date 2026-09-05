inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name(WHT"银台"NOR, ({ "board" }) );
	set("location", "/d/song/shangshu2");
	set("board_id", "dasong_b");
	set("long", "这是一个供大宋官员交流、分享经验以及成就的留言板。\n" );
	setup();
	set("capacity", 35);
	
}

int do_post(string arg)
{
	if (!this_player()->query("song/pro"))
		return notify_fail("你不是大宋官员，不能在这留言。\n");
	return ::do_post(arg);
}

int do_read(string arg)
{
	if (!this_player()->query("song/pro"))
		return notify_fail("你不是大宋官员，不能阅读这里的信息。\n");
	return ::do_read(arg);
}