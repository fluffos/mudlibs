// /clone/board/soo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("风儿留言板", ({ "board" }) );
	set("location", "/u/winder/workroom");
	set("board_id", "soo_b");
	set("long", "这是一个留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

