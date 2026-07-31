// /clone/board/bugs_b.c

inherit ITEM;

void create()
{
        set_name("臭虫留言板", ({ "board" }) );
        set("location", "/d/city/wumiao");
        set("board_id", "bugs_b");
        set("long", "留言板上到处爬满臭虫，天神们正在为清理臭虫忙的不亦乐乎。\n" );
        setup();
        set("capacity", 1000);
        replace_program(ITEM);
}
