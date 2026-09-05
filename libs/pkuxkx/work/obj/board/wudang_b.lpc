#pragma save_binary
// wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("武当弟子留言板", ({ "board" }) );
	set("location", "/d/wudang/sanqingdian");
	set("board_id", "wudang_b");
	set("long",	"这是供武当弟子留言记事的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
