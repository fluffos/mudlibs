inherit ROOM;

void create()
{
	set("short","死刑房");
	set("long","你完了……\n");
	set("no_update", 1);
	set("exits/out", VOID_OB);
	setup();
}

void init()
{
	object ob = this_player();

	if (wizardp(ob))
		return;
	ob->clear_condition();
	ob->set_ghost(0);
	ob->set("startroom", __FILE__[0..<3]);
	ob->save();
	add_action("block_cmd","", 1);
}

int block_cmd(string arg)
{
	switch(query_verb()) {
		case "look":
			if (arg) return 1;
		case "go":
		case "out":
		case "quit":
		case "suicide":
			return 0;
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	int exp = me->query("combat_exp");

	if (exp < 100000)
		return notify_fail("你还是老老实实地待着吧。\n");
	if (exp > 1000000)
		exp /= 10;
	else
		exp = 100000;
	if (!me->query_temp("confirm")) {
		me->set_temp("confirm", 1);
		me->start_busy(2);
		return notify_fail("离开这里将受到扣除"+chinese_number(exp)+"点经验的处罚，如果你同意，就再输入一次 out\n");
	}
	me->delete_temp("confirm");
	me->add("combat_exp", -exp);
	tell_object(me, "你被扣除了"+chinese_number(exp)+"点经验。\n");
	me->setup();
	return ::valid_leave(me, dir);
}
