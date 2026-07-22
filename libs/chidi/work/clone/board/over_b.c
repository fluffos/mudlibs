//over's board.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("¹Â¶À°å¿é", ({ "board" }) );
        set("location", "/u/over/workroom");
        set("board_id", "over_b");
        set("long", "¼ÅÄ¯¿Õ¼ä£¬¹Â¶ÀÁôÑÔ\n" );
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
