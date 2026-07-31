// /clone/board/huashan_b.c

inherit ITEM;

void create()
{
	set_name("华山弟子留言板", ({ "board" }) );
        set("location", "/d/huashan/laojun");
	set("board_id", "huashan_b");
	set("long", "这是一个供华山门下交流的留言板。\n" );
	setup();
	set("capacity", 100);
	//replace_program(ITEM);
}

