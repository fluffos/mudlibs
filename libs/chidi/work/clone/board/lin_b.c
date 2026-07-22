// /clone/board/lin_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("林府留言板", ({ "board" }) );
        set("location", "/d/city/zhengting");
        set("board_id", "lin_b");
        set("long", "这是一个供大理段府门下交流的留言板。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

