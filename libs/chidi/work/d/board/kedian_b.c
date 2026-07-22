// /clone/board/kedian_b.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("客店留言板", ({ "board" }) );
	set("location", "/d/city/kedian");
	set("board_id", "kedian_b");
    set("no_get",1);
	set("long", "一块普通的留言板，供过往的行人留言用。\n" );
	setup();
	set("unit","块");
        set("capacity", 218);
	replace_program(BULLETIN_BOARD);
}
