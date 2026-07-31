// /clone/board/shuyuan_b.c

inherit ITEM;

void create()
{
        set_name("先贤的传说", ({ "board" }) );
        set("location", "/d/city/shuyuan2");
        set("board_id", "shuyuan_b");
        set("long", "先贤的江湖风雨，传说故事。\n" );
        setup();
        set("capacity", 100);
        replace_program(ITEM);
}
