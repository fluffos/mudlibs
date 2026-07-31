// /clone/board/baituo_b.c

inherit ITEM;

void create()
{
	set_name("灵鹫宫弟子留言板", ({ "board" }) );
        set("location", "/d/lingjiu/damen");
	set("board_id", "lingjiu_b");
	set("long", "这是一个供灵鹫宫弟子交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}
