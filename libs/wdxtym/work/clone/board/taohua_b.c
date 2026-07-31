// /clone/board/taohua_b.c

inherit ITEM;

void create()
{
	set_name("桃花岛弟子留言板", ({ "board" }) );
	set("location", "/d/taohua/dating");
	set("board_id", "taohua_b");
	set("long", "这是一个专供桃花岛弟子使用的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

