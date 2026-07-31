// /clone/board/towiz_b.c

inherit ITEM;

void create()
{
	set_name("玩家意见留言板", ({ "board" }) );
	set("location", "/d/wizard/guest_room");
	set("board_id", "towiz_b");
	set("long", "这是一个供玩家和巫师交流的留言板。\n" );
	setup();
	set("capacity", 1000);
}

int do_post(string arg)
{
        object me;

        me = this_player();
        if (wiz_level(me) < 1 &&
            me->query("combat_exp", 1) < 10000 &&
            me->query("age") < 18)
                return notify_fail("你现在还没有资格在这里留言。\n");

        return ::do_post(arg);
}

int do_discard(string arg)
{
        if (wiz_level(this_player()) < 1)
                return notify_fail("你不能删除这个版面的任何留言。\n");

        return ::do_discard(arg);
}
