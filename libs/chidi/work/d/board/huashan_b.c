// /clone/board/huashan_b.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("华山派弟子留言板", ({ "board" }) );
	set("location", "/d/huashan/square");
	set("board_id", "huashan_b");
	set("long", "一块供华山派弟子留言的小石板。\n" );
	setup();
	set("unit","块");
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
