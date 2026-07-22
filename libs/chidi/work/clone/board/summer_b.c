 //   /clone/board/summer_b.c

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC"玉娇龙留言板"NOR, ({ "board" }) );
set("location", "/u/summer/workroom");
          set("board_id", "summer_b");
          set("long", HIC"这是玉娇龙和其它巫师交换意见的留言板。\n" NOR);
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}

