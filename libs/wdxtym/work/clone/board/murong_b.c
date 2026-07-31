// /clone/board/murong_b.c

inherit ITEM;

void create()
{
	set_name("慕容家弟子留言版", ({ "board" }) );
        set("location", "/d/yanziwu/qinyun");
	set("board_id", "murong_b");
	set("long", "这是一个供慕容家弟子交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

