//Cracked by Kafei
// /clone/board/pigroom_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("拱猪交流站", ({ "board" }) );
	set("location", "/d/city/duchang2");
	set("board_id", "pigroom_b");
	set("long", "这里给拱猪狂提供一个交流和吹牛的场所。\n");
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

