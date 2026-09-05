//modified by vast 5/30/2003

inherit NPC;

int do_yao(string);
int train_it(object, object, int);
varargs void revive();

void init()
{
        add_action("do_gen", "come");
        add_action("do_yao", "attack");
        add_action("do_ting", "stay");
        add_action("do_fang", "free");
	add_action("do_stop","stop");
        add_action("do_ride", "ride");
        add_action("do_ride", "qi");
        add_action("do_down", "xia");
        add_action("do_down", "unride");
        add_action("do_feed", "wei");
        add_action("do_feed", "feed");
        add_action("do_drink", "yin");
}

void create()
{
	set_name("野兽", ({"ye shou", "shou"}));
	set("race", "野兽");
	set("age", 100);
	set_weight(150000);
	set("long", "一只面目不清的野兽。\n");
	//set("attitude", "peaceful");
	set("combat_exp", 1000);
	set("wildness", 5);
	set("loyalty", 5);
	set("auto_follow",1);
	setup();
}

int is_trainee()
{
	return 1;
}

int train_it(object ob, object me, int pts)
{
	string msg_trained;

	if(!living(me)) return 1;

	if(!me->query_lord())
		pts = 10 * pts / (me->query("loyalty") + 10);

	if(query_temp("trainer") != ob->name()) {
		set_temp("trainer", ob->name());
		set_temp("training_pts",pts);
	}
	else
		add_temp("training_pts",pts);
	if(query_temp("training_pts") > 100) {
		delete_temp("trainer");
		delete_temp("training_pts");
		if(me->is_fighting())
			me->remove_all_enemy();
		me->set_lord(ob);
		if(!(msg_trained = me->query("msg_trained")))
			msg_trained = "$N驯服了$n";

		message_vision(msg_trained + "。\n", ob, me);

		if(me->query("auto_follow")) {
			me->set_leader(ob);
			message_vision("$n朝$N走了过来。\n", ob, me);
		}
	}
	return 1;
}

int do_gen(string arg)
{
	object me, ob, vc;
        ob = this_player();
	if (!arg )
                return notify_fail("你想让谁跟着你走？\n");
	if ( ob->query_skill("training",1) < 10 )
		return notify_fail("你的驭兽术还不纯熟，无法让野兽跟随你！\n");
        if(!objectp(me = present(arg, environment(ob))))
                return notify_fail("这里没有这个生物。\n");
        if( !me->is_character() || me->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        if( me->is_fighting() )
                return notify_fail(ob->name() + "正在打架，没空理你！\n");
        if( me->is_busy() )
                return notify_fail(ob->name() + "正在忙乎，没空理你！\n");
	if (!living(me))
		return notify_fail("这只野兽晕倒了，你怎能让它跟你呢？\n");
        if(ob == me)
                return notify_fail("这个好办。\n");
	message_vision("$N向$n招了招手。\n", ob, me);
	if(me->query_lord() == ob)
	{
		me->set_leader(ob);
		message_vision("$n朝$N走了过来。\n", ob, me);
	}
	else {
		message_vision("$n对$N睬也不睬。\n", ob, me);
	}
	return 1;
}

int do_stop(string arg)
{
        object me, ob, vc;
        ob = this_player();
        if (!arg )
                return notify_fail("你想让谁停下来？\n");
        if(!objectp(me = present(arg, environment(ob))))
                return notify_fail("这里没有这个生物。\n");
        if( !me->is_character() || me->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        if(ob==me)
                return notify_fail("用halt命令。\n");
        message_vision("$N拍一拍$n的头。\n", ob, me);
        if(me->query_lord() == ob) {
		if (me->is_fighting()) {
                me->remove_all_enemy();
                message_vision("$N缩在$n的脚边停止了攻击。\n",me,ob);
		return 1;
		}
		else {
			message_vision("$n疑惑地看着$N。\n", ob, me);
			return 1;
		}
	}
	else {
		 message_vision("$n对$N睬也不睬。\n", ob, me);
        }
        return 1;
}

int do_yao(string victim)
{
        object me, ob, vc;
        int atk;
        ob = this_player();
	me = this_object();

        if(me->query_lord() != ob)
        {
                message_vision("$n对$N睬也不睬。\n", ob, me);
		return 1;
        }

        if(me->query("race") == "马类")
        {
                tell_object(ob, "这么温顺的动物怎么会帮你打架呢？\n");
                return 1;
        }

        if(! victim)
        {
                tell_object(ob, "攻击谁？\n");
                return 1;
        }
        if(!(vc = present(victim,environment(me)))) {
                message_vision("$N拍拍$n的头。\n", ob, me);
                write(me->name()+"找不到这个人。\n");
                return 1;
        }
        if (vc == ob) {
                message_vision("$N拍拍$n的头，又指了指自己。\n", ob, me);
                if(me->query_lord()==ob) {
                        message_vision("$n疑惑地看着$N。\n", ob, me);
                        return 1;
                }
                remove_call_out("biting");
                call_out("biting",1,me,vc);
		return 1;
        }
	if (vc == me) {
		message_vision("$N拍拍$n的头，指了指它的尾巴。\n", ob, me);
		message_vision("$n咬着自己的尾巴转了一个圈。\n", ob, me);
		return 1;
	}
        message_vision("$N拍拍$n的头，又指了指" + vc->query("name") +
                "。\n", ob, me);
        remove_call_out("biting");
        call_out("biting",1,me,vc);
        message_vision("$n向$N扑了过去。\n", vc, me);
        return 1;
}
int do_ting()
{
	object me, ob;
	me = this_object();
	ob = this_player();
	if( 	me->query_lord() == ob
		&& me->query_temp("rider") == ob
		&& ob->query_temp("riding") == me )
	{
		tell_object(ob,"你必须先从它身上下来。\n");
		return 1;
	}
	else if( me->query_lord() == ob)
	{
		me->set_leader(0);
		message_vision("$N对$n挥了挥手，$n垂首走开了。\n", ob, me);
		return 1;
	}
	else if(me->query_lord() != ob)
	{
		tell_object(ob,"你不是它的主人。\n");
		return 1;
	}
	return 0;
}

int do_fang()
{
	object me, ob;
	me = this_object();
	ob = this_player();
	if( 	me->query_lord() == ob
		&& me->query_temp("rider") == ob
		&& ob->query_temp("riding") == me )
	{
		tell_object(ob,"你必须先从它身上下来，才能放它。\n");
		return 1;
	}
	else if(me->query_lord() == ob && !me->query_temp("rider"))
	{
		me->set_lord(0);
		me->set_leader(0);
		message_vision("$N在$n耳边轻声说了几句，$n垂首走开了。\n", ob, me);
		me->set_temp("prelord",ob->query("id"));
		return 1;
	}
	else if(me->query_lord() != ob)
	{
		tell_object(ob,"你不是它的主人。\n");
		return 1;
	}
	return 0;
}
void biting(object me, object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	me->kill_ob(ob);
}
int do_ride()
{
	object me, ob;
	me = this_object();
	ob = this_player();
	if( me->query_lord() == ob )
	{
		if( !ob->query_temp("riding") )
		{
			if( !me->query_temp("rider") )
			{
				ob->set_temp("riding", me);
				me->set_temp("rider",  ob);
				me->set_leader(ob);
				message_vision("\n$N一纵身，威风凛凛地骑在了" + me->name() +"身上。\n", ob);
				return 1;
			}
			else    return notify_fail( me->query_temp("rider")->name() + "已经骑在它身上上了！\n");
		}
		else	return notify_fail("你已经骑在" + ob->query_temp("riding")->name() + "上了！\n");
	}
	else return notify_fail("你不是它的主人！\n");
}
int do_down()
{
	object me, ob;
	me = this_object();
	ob = this_player();
	if( ob->query_temp("riding") == me && me->query_temp("rider") == ob )
	{
		ob->delete_temp("riding");
		me->delete_temp("rider" );
		message_vision("\n$N一纵身，从" + me->name() +"身上跃了下来。\n", ob);
		return 1;
	}
	else return notify_fail("你还没骑它呢！\n");
}
int do_feed(string arg)
{
	object me, ob, food;
	me = this_object();
	ob = this_player();
	if(!arg) return notify_fail("你要喂它什么东西？\n");
	food = present(arg, environment(ob));
	if(!food) return notify_fail("你必须把食物放在房间里面！\n");
	if(!food->query("food_remaining")) return notify_fail("这不是食物啊！\n");
	if(me->query_lord() != ob)
	{
		tell_object(ob,"你不是它的主人。\n");
		return 1;
	}
	if( me->query("food") >= me->max_food_capacity() )
		return notify_fail(me->name() + "已经吃太饱了，再也塞不下任何东西了。\n");
	command("eat " + food->query("id"));
	return 1;
}
int do_drink(string arg)
{
	object me, ob, drink;
	me = this_object();
	ob = this_player();
	if(!arg) return notify_fail("你要喂它什么东西？\n");
	drink = present(arg, environment(ob));
	if(!drink) return notify_fail("你必须把饮水放在房间里面！\n");
	if(!drink->query("liquid/remaining")) return notify_fail("这东西不能喝啊！\n");
	if(me->query_lord() != ob)
	{
		tell_object(ob,"你不是它的主人。\n");
		return 1;
	}
	if( me->query("water") >= me->max_water_capacity() )
		return notify_fail(me->name() + "已经喝太多了，再也灌不下一滴水了。\n");
	command("drink " + drink->query("id"));
	return 1;
}