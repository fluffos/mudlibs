// /clone/board/yipin_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("平安大吉留言板", ({ "board" }) );
	set("location", "/d/pingan/guangchang");
	set("board_id", "pingan_b");
	set("long", "这是一个供新手交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

