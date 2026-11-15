// zhang.c



inherit NPC;

int is_punisher() { return 1; }

void create()
{
	set_name("章召重", ({ "zhang zhaozhong", "zhang", "zhaozhong" }) );
	set("title", "御林军骁骑营佐领");
	set("nickname", HIR "火手判官" NOR);
	set("gender", "男性");
	set("age", 43);
	set("long", @LONG
章召重人称“火手判官”，身材魁梧，留一丛短胡子。江湖盛言“宁
挨一枪，莫遇一张”就是指他了。他热衷功名利禄，投身朝廷，此人
办事卖力，这些年来更是青云直上。
LONG );
	set("combat_exp", 1800000);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("max_neili", 5500);
	set("neili", 5500);
	set("max_jing", 2500);
	set("jing", 2500);
	set("max_qi", 5000);
	set("qi", 5000);

	set("str", 35);
	set("int", 32);
	set("con", 33);
	set("dex", 31);

	set_skill("unarmed", 240);
	set_skill("sword", 240);
	set_skill("parry", 240);
	set_skill("dodge", 240);
	set_skill("force", 250);
	set_skill("taiji-shengong", 250);
	set_skill("taiji-jian", 240);
	set_skill("taiji-quan", 240);
	set_skill("tiyunzong", 240);
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji-shengong");
	map_skill("sword", "taiji-jian");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");

	create_family("武当派", 13, "弟子");
	setup();

	set_max_encumbrance(100000000);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 200);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	carry_object("/clone/weapon/green_sword")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}

void init()
{
	add_action("do_halt", "halt");
}

int do_halt()
{
 

	if (this_player() == query_temp("catch_ob"))
	{
		write(name() + "喝道：“你还想在我面前逃走吗？"
		      "乖乖的束手就擒吧！”\n");
		return 1;
	}

	return 0;
}

void fight_ob(object ob)
{
	int damage;

	if (is_fighting(ob))
		return;

	if (ob != query_temp("catch_ob"))
	{
		message_vision(HIY "$N" HIY "对$n" HIY "大喝"
			       "道：大胆！居然敢攻击官差？找死么？\n"
			       "说罢，只见$N" HIY "飞起一脚，将$n"
			       HIY "踢倒在地！！！"NOR"\n",
			       this_object(), ob);
		damage = 500 + random(100);
		ob->receive_damage("qi", damage, this_object());
		ob->receive_wound("qi", damage / 2, this_object());
		ob->remove_enemy(this_object());
		remove_enemy(ob);
		if (! ob->is_busy())
			ob->start_busy(2);
		return;
	}

	::fight_ob(ob);
	if (! is_killing(ob->query("id")))
		kill_ob(ob);
}

int accept_fight(object ob)
{
	message_vision("$N冷冷的对$n道：“我有公干，你少来惹事！”。\n",
		       this_object(), ob);
	return 0;
}

int accept_kill(object ob)
{
	return 1;
}

int accept_hit(object ob)
{
	return 1;
}

void catch_ob(object ob)
{
	remove_enemy(ob);
	message_vision("$N伸手把$n提拎了起来，喝道：“走吧！”\n",this_object(), ob);
	message_vision("$N拎着$n转身离去。\n", this_object(), ob);

	CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) + HIM "因为妄杀无辜，现已被火手判官章召重缉拿归案，押入大牢。");
	ob->get_into_prison(this_object(), "/d/changan/prison", ob->query_condition("killer")/30);
	ob->delete("combat/need_catch");
	ob->clear_condition("killer");
	destruct(this_object());
	return;
}

void start_catch(object ob)
{
	move(environment(ob));
	message_vision("$N走了过来，看到$n，冷笑了一声。\n", this_object(), ob);
	command("chat " + ob->name(1) + "你为非作歹，官府已经下了海捕文书，你就乖乖的跟我回去吧！");

	catch_ob(ob);
}

int attack()
{
	object ob;

	if (objectp(ob = query_temp("catch_ob")) &&
	    ! living(ob) &&
	    environment(ob) == environment())
	{
		catch_ob(ob);
		return 1;
	} else
		return ::attack();
}

void unconcious()
{
	die();
}

void die()
{
	command("chat 天哪！我" + name() + "忠心耿耿，可是...不是我没用，而是敌人太强大了。");
	message_vision(HIM "$N" HIM "狂吐几口鲜血，扔下一个烟雾弹，"
		       HIM "借着混乱逃走了。\n", this_object());
	destruct(this_object());
}

void scan()
{
	object ob;

	if (! environment())
	{
		destruct(this_object());
		return;
	}

	if (! objectp(ob = query_temp("catch_ob")) ||
	    environment(ob) != environment() ||
	    environment(ob)->query("no_fight"))
	{
		message_vision("$N收住招式，悻悻道：“哼”，随即转身离去。\n",
			       this_object());
		destruct(this_object());
		return;
	}

	if (! living(ob))
	{
		catch_ob(ob);
		return;
	}

	if (! is_fighting(ob))
		fight_ob(ob);

	::scan();
}