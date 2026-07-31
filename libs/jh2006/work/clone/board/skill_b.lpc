inherit BULLETIN_BOARD;

void create()
{
        set_name("技能研究讨论版", ({ "board" }) );
        set("location", "/d/city/kedian/pianting");
        set("board_id", "skill_b");
        set("long", "有有用的话就往这里说，乱灌水杀无赦。\n" );
        setup();
	set("capacity", 300);
}

int do_post(string arg)
{
	object ob = this_player();

	if (!ob->query("can_post") && ob->query("combat_exp") < 1000000)
		return notify_fail("你还不够资格在这里留言。\n");
	return ::do_post(arg);
}
