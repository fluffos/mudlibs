// /clone/board/honghua_b.c

inherit ITEM;

void create()
{
	set_name("红花会留言板", ({ "board" }) );
	set("location", "/d/hangzhou/liuhed");
	set("board_id", "soo_b");
	set("long", "这是一个供红花会众交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

