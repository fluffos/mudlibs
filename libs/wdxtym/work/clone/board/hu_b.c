// /clone/board/hu.c

inherit ITEM;

void create()
{
	set_name("胡家弟子留言版", ({ "board" }) );
        set("location", "/d/guanwai/xiaoyuan");
	set("board_id", "hu_b");
	set("long", "这是一个供胡家弟子交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}
