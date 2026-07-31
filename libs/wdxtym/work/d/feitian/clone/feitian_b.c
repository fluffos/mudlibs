// /clone/board/bonze_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("飞天御剑流弟子留言板", ({ "board" }) );
	set("location", "/d/feitian/daochang");
	set("board_id", "feitian_b");
	set("long", "这是一个供飞天御剑流弟子交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
