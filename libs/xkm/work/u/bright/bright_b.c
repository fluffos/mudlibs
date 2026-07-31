//write by bright
//盼盼记事本

inherit BULLETIN_BOARD;

void create()
{
        set_name("盼盼记事本", ({ "board" }) );
        set("location", "/u/bright/workroom");
        set("board_id", "bright_b");
        set("long", "这是一块明亮与其他巫师沟通的留言版。\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}
