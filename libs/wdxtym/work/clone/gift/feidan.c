// feidan.c 核子飞弹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "核子飞弹" NOR, ({ "nucleus bomb" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是高科技产品，是" RED "血滴子" NOR "的新版本。\n");
		set("value", 50000);
		set("no_sell", 1);
		set("unit", "枚");
	}
}

void init()
{
	add_action("do_launch", "launch");
	add_action("do_aim", "aim");
}

int do_launch(string arg)
{
	object me;
	object ob;
	string user;

	me = this_player();

	if (me->is_busy())
		return notify_fail("什么事情都等你忙完了再说。\n");

	if (me->is_fighting())
		return notify_fail("打完架再考虑这些事情吧！\n");

	if (! arg || ! id(arg))
		return notify_fail("你要发射什么？\n");

	if (! stringp(user = query_temp("aim")))
		return notify_fail("你先瞄准(aim)好再发射！\n");

	if (! objectp(ob = find_player(user)) ||
	    ! me->visible(ob))
		return notify_fail("你要炸的玩家现在好像不在线上。\n");

	message_vision(HIM "$N掏出一个" + name() + HIM "，喃喃自"
		       "语道：“5... 4... 3... 2... 1...”说罢一按开关！\n"
		       "就听“轰”的一声，" + name() + HIM "腾空而去！"NOR"\n", me);

	if (ob->query("env/no_idle"))
	{
		message_vision(HIG "突然天空传来一阵嗡嗡的声音...\n" +
			       "一颗" + name() + HIG "呼啸而下，$N" + HIG
			       "赶紧往边上一跳，好险，只差一毫米那么宽，"
			       "幸免于难。"NOR"\n", ob);
		tell_object(me, "你的" + name() + "没有命中对方，再接再厉。\n");
		destruct(this_object());
		return 1;
	}

	message_vision(HIC "突然天空传来一阵嗡嗡的声音...\n" +
		       "“轰”的一声，$N" HIC "被炸得浑身都是小烟，"
		       "一句话都说不出来..."NOR"\n", ob);

	if (wizardp(ob))
		message_vision(HIM "$N" HIM "连忙点燃一张符纸，口中"
		       "直念叨：“太上老君救命啊...”"NOR"\n", ob);
	else
	{
		message_vision(HIG "$N" HIG "一脸无辜的表情，真冤枉啊！"NOR"\n", ob);
		if (! ob->ban_say(1))
			CHANNEL_D->do_channel(this_object(), "rumor",
					      "听说" + ob->name(1) +
					      "惨遭核子飞弹袭击，现在精神失常。");
		ob->ban_say_until(10 * 60, "你现在被炸得头晕眼花，说不出话");
		log_file("static/feidan", sprintf("%s：%s对%s使用了核子飞弹成功。\n",ctime(time()),me->query("id"),ob->query("id")));
	}

	destruct(this_object());
	return 1;
}

int do_aim(string arg)
{
	object me;
	object ob;
	string my_id;

	if (arg && sscanf(arg, "%s with %s", arg, my_id) == 2 && ! id(my_id))
		return notify_fail("这里没有(" + my_id + ")这样东西。\n");

	if ((arg == "none" || arg == "cancel") && query_temp("aim"))
	{
		delete_temp("aim");
		write("立即取消飞弹瞄准！\n");
		return 1;
	}

	me = this_player();

	if (! arg || ! objectp(ob = find_player(arg)) ||
	    ! me->visible(ob))
		return notify_fail("你要瞄准哪个玩家？\n");

	if (me->is_busy())
		return notify_fail("什么事情都等你忙完了再说。\n");

	if (me->is_fighting())
		return notify_fail("打完架再考虑这些事情吧！\n");

	if (me->ban_say())
		return notify_fail("你现在说不出话来...导弹也没法发射。\n");

	tell_object(me, HIY "你掏出一个" + name() + HIY "，东瞄瞄，西瞄瞄。"NOR"\n", me);
	if (!random(10))
		message("vision", HIR "【观察卫星】紧急报告，" + ob->name(1) +
			  HIR "已经被人用" + name() +
			  HIR "瞄准了。"NOR"\n", ob);
	log_file("static/feidan", sprintf("%s：%s对%s使用了核子飞弹瞄准。\n",ctime(time()),me->query("id"),ob->query("id")));
	set_temp("aim", ob->query("id"));
	me->start_busy(5);

	return 1;
}

string long()
{
	object ob;
	string msg;

	msg = query("long");
	if (query_temp("aim") &&
	    objectp(ob = find_player(query_temp("aim"))))
	{
		msg += "现在这枚飞弹正瞄准着" + ob->name(1) +
		       "，待命发射(launch)。\n";
	} else
		msg += "现在这枚飞弹正处于准备状态，"
		       "可以随时瞄准(aim)。\n";
	return msg;
}
