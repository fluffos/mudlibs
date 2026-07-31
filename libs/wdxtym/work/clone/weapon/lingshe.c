// lingshe.c 灵蛇杖
// by jeeny

#include <weapon.h>
#include <ansi.h>

inherit F_OBSAVE;
inherit STAFF;

string do_wield();
string do_unwield();

void create()
{
	set_name(HIW "灵蛇杖" NOR, ({ "lingshe zhang", "staff", "lingshe" }));
	set_weight(1500);
	if (clonep())
		destruct(this_object());
	else {
		set("long", @LONG
这是一柄令人毛骨悚然的宝杖，昔年西毒欧阳峰曾凭借此杖和洪七公大战
三百回合。杖头雕着个咧嘴而笑的人头，面目狰狞，口中两排利齿，上喂
剧毒，舞动时宛如个见人即噬的厉鬼。更厉害的是缠杖盘旋的两条毒蛇，
吞吐伸缩，令人难防。
LONG );
		set("unit", "把");
		set("value", 800000);
		set("no_sell", 1);
		set("du", 3) ;
		set("material", "steel");
		set("wield_msg", (: do_wield :));
		set("unwield_msg", (: do_unwield :));
		set("stable", 80);
	}
	init_staff(200);
	setup();
	restore();
}

string do_wield()
{
	object me;

	me = this_player();
	remove_call_out("check_npc");
	call_out("check_npc", 0, me, environment(me));
	if (me->query("shen") < -10000)
		return HIW "$N一声长啸，取出$n" HIW "，一时间，阴风袭袭。"NOR"\n";
	else
	if (me->query("shen") <= 0)
		return HIC "$N一伸手，已然把$n" HIW "握在手中。"NOR"\n";
	else
	if (me->query("shen") > 10000)
		return HIB "$N哆哆嗦嗦的摸出一把$n" HIB "。"NOR"\n";
	else
		return HIB "$N一声冷笑，“唰”的一声亮出了$n" HIB "。"NOR"\n";
}

string do_unwield()
{
	object me;

	me = this_player();
	remove_call_out("check_npc");
	if (me->query("shen") <= 0)
		return HIC "$N一挥手，收起了灵蛇杖。"NOR"\n";
	else
	if (me->query("shen") > 10000)
		return HIG "$N把$n" HIG "收了起来，心还“砰砰砰”跳个不停。"NOR"\n";
	else
		return HIG "$N一晒，把$n" HIG "插回腰间。"NOR"\n";
}

void check_npc(object me, object env)
{
	object *ob;
	int i;

	if (! objectp(me) || ! living(me))
		return;

	if (environment(me) != env)
		return;

	ob = all_inventory(env);
	for (i = 0; i < sizeof(ob); i++)
	{
		if (! ob[i]->is_character() || ob[i] == me ||		    
		    ! living(ob[i]) || ob[i]->query("not_living") ||
		    ob[i]->query("id") == "ouyang feng")
			continue;

		if (me->is_good())
		{
			if (userp(ob[i]))
				continue;

			if (ob[i]->query("shen") < -10000)
			{
				message_vision("$N大怒喝道：好你个" + RANK_D->query_rude(me) +
					       "，居然敢盗用灵蛇杖？\n", ob[i]);
				if (! env->query("on_fight"))
					ob[i]->kill_ob(me);
			} else
			if (ob[i]->is_good())
			{
				message_vision(random(2) ? "$N哈哈大笑，对$n道：干得漂亮，侠之"
							   "大者，也就是兄台这般人物。\n" :
							   "$N拼命鼓掌，对$n道：兄弟又为武林立"
							   "一大功啊",
					       ob[i], me);
			}
			continue;
		}

		if (me->is_not_bad())
			continue;

		if (ob[i]->query("shen") < -10000 && ! userp(ob[i]))
		{
			message_vision(random(2) ? "$N赞道：好杖，好杖！\n" :
						   "$N叹道：也不知欧阳兄近来可好？\n",
				       ob[i]);
		} else
		if (ob[i]->query("shen") > 10 && ! userp(ob[i]))
		{
			int ob_exp, my_exp;
			ob_exp = ob[i]->query("combat_exp");
			my_exp = me->query("combat_exp");
			if (ob_exp > my_exp * 2 || ob_exp > 1500000)
			{
				message_vision(random(2) ? "$N对$n冷冷道：滚开！少在我面前卖弄。\n" :
							   "$N一声冷笑，对$n道：你以为你是谁？欧"
							   "阳峰？哈哈哈哈！\n",
					       ob[i], me);
			} else
			if (ob_exp > 20000)
			{
				message_vision(random(2) ? "$N脸色有些不对劲。\n" :
							   "$N露出害怕的神色。\n",
					       ob[i]);
				if (env->query("no_fight"))
					continue;
				message_vision(random(2) ? "$N怒喝一声，“大家都不要活了！”\n" :
							   "$N一言不发，忽的扑向$n，身形极快。\n",
					       ob[i], me);
				ob[i]->kill_ob(me);
			} else
			{
				message_vision(random(2) ? "$N扑通一声，瘫倒在地，双手急摇"
							   "道：“不是我！真的不是我！”\n" :
							   "$N一个哆嗦，结结巴巴的什么也说"
							   "不上来。\n",
					       ob[i], me);
				if (! env->query("no_fight"))
					ob[i]->unconcious();
			}
		}
	}
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int n;
	int my_exp, ob_exp;

	if (me->is_good() || victim->is_bad())
		return - damage_bonus / 2;

	if (me->is_not_bad() || victim->is_not_good())
		return 0;

	if (me->query_skill_mapped("staff") != "lingshe-zhangfa" ||
	    me->query_skill("lingshe-zhangfa", 1) < 100)
		// only increase damage
		return damage_bonus / 2;

	switch (random(6))
	{
	case 0:
		if (! victim->is_busy())
			victim->start_busy(me->query_skill("staff") / 20 + 2);
		return HIB "$N跨前一步，手中的" NOR+HIW "灵蛇杖" NOR+HIB "从意想不到的"
		       "角度向$n攻去，杖法有如狂风暴雨般猛烈。$n大吃一\n"
		       "惊，不知如何抵挡，只有连连后退。"NOR"\n";

	case 1:
		n = me->query_skill("staff");
		victim->receive_damage("qi", n, me);
		victim->receive_wound("qi", n, me);
		victim->receive_damage("jing", n, me);
		victim->receive_wound("jing", n / 2, me);
		return random(2) ? HIB "$N一声长吟，手中的灵蛇杖化作一道白光，“唰”的扫过$n。"NOR"\n":
				   HIB "$N突然大声喝道：“什么名门正派，还不受死？”手中灵蛇杖"
				   HIB "忽的一抖，$n登时觉得眼前有如万千条毒蛇窜动。"NOR"\n";
	}

	// double effect
	return damage_bonus;
}

void start_borrowing()
{
	remove_call_out("return_to_feng");
	call_out("return_to_feng", 7200 + random(600));
}

void return_to_feng()
{
	object me;

	me = environment();
	if (! objectp(me))
		return;

	while (objectp(environment(me)) && ! playerp(me))
		me = environment(me);
 
	if (playerp(me))
	{
		if (me->is_fighting())
		{
			call_out("return_to_feng", 1);
			return;
		}

		message_vision("忽然一个欧阳世家的弟子走了过来，看到$N，忙招呼道：“祖师爷让"
			       "我来找你拿回灵蛇杖，你现在不用了么？”\n"
			       "$N道：“好了，好了，你就拿回去吧。”\n"
			       "$N将杖交给欧阳世家弟子带走。\n", me);
	} else
	{
		message("vision", "忽然一个欧阳世家弟子走了过来，捡起灵蛇杖，叹了口气，摇摇"
				  "头走了。\n", me);
	}

	destruct(this_object());
}

// 进行保存数据的接口函数
mixed save_dbase_data()
{
	mapping data;

	data = ([ "du" : query("du") ]);


	return data;
}

// 接受存盘数据的接口函数
int receive_dbase_data(mixed data)
{
	if (! mapp(data))
		return 0;

	if (! undefinedp(data["du"]))
	{
		set ("du", data["du"]);
	}

	return 1;
}

