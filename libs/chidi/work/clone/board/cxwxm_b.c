// marry 99.8
inherit BULLETIN_BOARD;

void create()
{
        set_name("痴心妄想门弟子留言板", ({ "board" }) );
        set("location", "/d/cxwxm/dating");
        set("board_id", "board");
        set("long", "这是一个供痴心妄想门弟子交流的留言板。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
