// /clone/board/gaibang_r.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("丐帮弟子留言板", ({ "report" }) );
	set("location", "/d/city/gbxiaowu");
	set("board_id", "gaibang_r");
	set("long", "这是一个供丐帮弟子交流信息的留言板。\n" );
	setup();
	set("unit","块");
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
