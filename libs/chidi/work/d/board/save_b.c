// /clone/board/towiz_b.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("巫师公告板", ({ "board" }) );
	set("location", "/d/city/wumiao");
	set("board_id", "wizto_b");
	set("long", "这是一个巫师发布公告的留言板。\n" );
	setup();
	set("capacity", 60);
}
int do_post(string arg)
{
	if (!wizardp(this_player()))
		return notify_fail("只有巫师才可以在这里留言。\n");
	return ::do_post(arg);
}
