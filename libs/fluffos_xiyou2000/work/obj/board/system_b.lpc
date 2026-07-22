// cracked by vikee 2/09/2002   vikee@263.net
// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("系统公告板", ({ "board" }) );
	set("location", "/d/wiz/system");
	set("board_id", "system_b");
	set("long",
		"这是一个专门公告系统资讯的板子，只有巫师能 post。\n" );
	setup();
	set("capacity", 150);
	replace_program(BULLETIN_BOARD);
}
