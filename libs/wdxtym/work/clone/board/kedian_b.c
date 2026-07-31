// /clone/board/kedian_b.c

inherit ITEM;

void create()
{
	set_name("客店留言板", ({ "board" }) );
	set("location", "/d/city/kedian");
	set("board_id", "kedian_b");
	set("long", "有有用的话就往这里说，乱灌水杀无赦。\n" );
	setup();
	set("capacity", 1000);
	replace_program(ITEM);
}

int do_discard(string arg)
{
        if (wiz_level(this_player()) < 1)
                return notify_fail("你不能删除这个版面的任何留言。\n");

        return ::do_discard(arg);
}
