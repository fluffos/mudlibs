// /clone/board/gaibang_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name(HIM"异闻录"NOR, ({ "board" }) );
	set("location", "/d/riyuejiao/chengde");
	set("board_id", "ry_b");
	set("long", "这是一个供日月神教弟子交流、分享经验、成就的留言板。\n" );
	setup();
	set("capacity", 35);
	
}

int do_post(string arg)
{
	if (this_player()->query("family/family_name")!="日月神教")
		return notify_fail("你不是神教弟子，不能在这留言。\n");
    if (this_player()->query("exp/rynewbiejob")<10000)
		return notify_fail("你对神教贡献不够，不能撰写神教异闻录。\n");
	return ::do_post(arg);

}

int do_read(string arg)
{
	mapping * notes;
    int num;
    notes = query("notes");
	
	if (this_player()->query("family/family_name")!="日月神教")
		return notify_fail("你不是神教弟子，不能阅读神教异闻录。\n");
	if (this_player()->query("exp/rynewbiejob")<10000)
		return notify_fail("你对神教贡献不够，不能阅读神教异闻录。\n");
	return ::do_read(arg);
}