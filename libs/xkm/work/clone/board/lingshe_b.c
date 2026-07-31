//Cracked by Kafei
// /clone/board/lingshe_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("灵蛇岛留言板", ({ "board" }) );
	set("location", "/d/lingshedao/room");
	set("board_id", "gaibang_b");
	set("long", "这是一个供灵蛇岛弟子交流的留言板。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

