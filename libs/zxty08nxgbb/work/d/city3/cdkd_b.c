// /clone/board/cdkd_b.c, xixi

inherit BULLETIN_BOARD;

void create()
{
	set_name("成都假日酒店留言板", ({ "board" }) );
	set("location", "/d/city3/kedian");
	set("board_id", "beiyou_b");
	set("long", "这是一个成都假日酒店的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
