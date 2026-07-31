// by Zjb@TY /06/25/2002/

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"lpc—ßœ∞µÿ"NOR,({"board"}));
        set("location","/u/zjb/room/xuexi");
        set("board_id", "zjb_b2");
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

