// /clone/board/bugboard.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("BUG 留言版", ({ "board" }) );
	set("location", "/d/city/guangchang");
	set("board_id", "bugboard");
	set("long", "请把 BUG POST 出来, 详细表格请 read 1" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
