// /clone/board/emei_b.c

inherit ITEM;

void create()
{
	set_name("峨嵋弟子留言板", ({ "board" }) );
        set("location", "/d/emei/hcazhengdian");
	set("board_id", "emei_b");
	set("long", "这是一个供峨嵋门下交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

