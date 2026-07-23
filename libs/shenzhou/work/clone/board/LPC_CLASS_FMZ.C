// /clone/board/lpc_class_fmz.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("分冥子LPC教室", ({ "board" }) );
	set("location", "/u/scatter/room1");
	set("board_id", "lpc_class_fmz");
	set("long", "分冥子LPC教室\n" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
