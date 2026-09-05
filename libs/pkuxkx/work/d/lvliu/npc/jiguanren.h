void renew(object me);

void init()
{
	if (!userp(this_player())) return;
	if (this_object()->query("changed"))
		message_vision("$N头顶上有个像是头箍似的小圆环忽然转动了几圈，发出了滴滴声响，$N变得益发精神抖擞起来。\n"NOR, this_object());
	renew(this_player());
}

void interrupt_me(object me)
{
	object ob=this_object();
	if (!ob->query("interrupt_busy")) return;
	if (ob->is_busy() && !random(3))
	{
		message_vision(HIM"\n$N"HIM"的臂弯处传来咔咔数响，接着双臂转了两圈，又变得活动自如了。\n\n"NOR, ob);
		ob->start_busy(0);
	}
}

void auto_perform()
{
    command("jifa unarmed xiake-quanjiao");
    command("exert recover");
    command("exert qi");
}

void killall()
{
	object me = this_object();
	object *allob = all_inventory(environment(me));
	for(int i=0;i<sizeof(allob);i++)
	{
		if(!objectp(allob[i])) continue;
		if(!userp(allob[i]) || wizardp(allob[i])) continue;
		if(me->is_fighting(allob[i])) continue;
		message_vision(HIM"$N"HIM"忽然动了起来，摇摇晃晃地对$n发起了攻击！\n"NOR, me, allob[i]);
		me->kill_ob(allob[i]);
	}
}

void renew(object me)
{
	mapping hp_status, skill_status, map_status, prepare_status;
	int exp, level;
	object ob = this_object();
	ob->start_busy(0);
	exp = me->query("combat_exp");
	if (exp<100) exp=100;
	level = to_int(ceil( pow( exp*10, 1.0/3) ));
	if (exp > ob->query("combat_exp"))
		ob->set("combat_exp", exp);
	if (ob->query("max_qi") < me->query("max_qi"))
		ob->set("max_qi", me->query("max_qi"));
	if (ob->query("max_jing") < me->query("max_jing"))
		ob->set("max_jing", me->query("max_jing"));
	if (ob->query("max_neili") < me->query("max_neili"))
		ob->set("max_neili", me->query("max_neili"));
	if (ob->query("max_jingli") < me->query("max_jingli"))
		ob->set("max_jingli", me->query("max_jingli"));
	ob->set("neili",  2*ob->query("max_neili"));
	ob->set("jingli",  2*ob->query("max_jingli"));
	if (!ob->query("changed"))
	{
		ob->set("eff_qi", ob->query("max_qi"));
		ob->set("eff_jing", ob->query("max_jing"));
		ob->set("changed", 1);
	}
	else
	{
		ob->add("eff_qi", (ob->query("max_qi") - ob->query("eff_qi"))/2);
		ob->add("eff_jing", (ob->query("max_jing") - ob->query("eff_jing"))/2);
	}
	ob->set("qi", ob->query("eff_qi"));
	ob->set("jing", ob->query("eff_jing"));
	if (ob->query("level") < me->query("level"))
		ob->set("level", me->query("level"));
	if (level > ob->query("max_sk"))
	{
        set_skill("force", level*3);
        set_skill("dodge", level);
        set_skill("unarmed", level);
        set_skill("jixie-bi", level);
        set_skill("parry", level);
        set_skill("literate", level);
        set_skill("poison", level);
		set("jiali", level/2);
		ob->set("max_sk", level);
	}
}

void unconcious()
{
    die();
}

void die()
{
	object ob = this_object();
	object env = environment(ob);
	object box;
	message_vision(YEL"\n$N"YEL"伴着一声巨响轰然倒地，散成了无数零件碎片。\n\n"NOR, ob);
	if (env->query("robot_components")<5)
		env->add("robot_components", 1+random(2));
	if (ob->query("last_jiguanren"))
	{
		message_vision(YEL"\n待得尘土散尽，废墟中露出了一个巨大的宝盒。\n"NOR, ob);
		box = new("/d/lvliu/obj/wxbox");
		box->move(env);
	};
	destruct(ob);
}
