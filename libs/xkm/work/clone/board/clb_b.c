//Cracked by Kafei
// /clone/board/clb_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("长乐帮留言板", ({ "board" }) );
        set("location", "/d/forest/clzoulang2");
        set("board_id", "clb_b");
        set("long", "这是一个供长乐帮帮众交流和报告BUG的留言板。\n" );
        setup();
        set("capacity", 60);
        replace_program(BULLETIN_BOARD);
}
