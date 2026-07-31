// /clone/board/bocai_b.c
// jeeny 2001.5
inherit ITEM;

void create()
{
        set_name("博彩留言簿", ({ "board" }));
        set("location", "/d/city/bocai");
        set("board_id", "bocai_b");
        set("long", "这是一个专供博彩使用的留言板。\n" );
        setup();
        set("capacity", 1000);
        replace_program(ITEM);
}

int do_discard(object me, string arg)
{
        me = this_player();

        if (wiz_level(me) < 1)
                return notify_fail("你不是巫师，无法删除留言。\n");
        else
                return ::do_discard(me, arg);
}
