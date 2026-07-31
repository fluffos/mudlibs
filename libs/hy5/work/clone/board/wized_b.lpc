// /clone/board/wized_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("修改记录留言簿", ({ "board" }) );
	set("location", "/d/wizard/edit_room");
	set("board_id", "wized_b");
	set("long", "专供巫师记录修改的留言板。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}