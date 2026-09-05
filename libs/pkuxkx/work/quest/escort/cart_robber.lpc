////quest/escort/cart_robber.c
// robber for dart
//使得复制时不参考literate等级
//劫匪模块化处理
//掉落采用推车掉落函数by yhzzyahoo@15.7.23，这下可以精准打击了！

#include <ansi.h>
inherit NPC;
void exer();

//robber_skill为劫匪属性配置
//skills为劫匪技能，分为两种，一种为基本技能:特殊技能，另外一种为知识技能:技能级别
//unarmed为激发的拳脚技能
//exert为内功特技，perform为特殊攻击，配置中通配符$PF$为perform，$TARGET$为对方id，$CLONE$后面跟着的物品要clone出来
//perform中存在mapping的时候，cmd为执行命令，pct为特殊权重（默认权重100）。
//weapon为劫匪武器，武器2为武器1被打没的时候备用武器
//special为额外的劫匪用户属性。
mapping *robber_skill=
({(["name":MAG"劫匪"NOR,
	  "menpai":(["华山派":19]),
	  "skills":(["#1sword":"huashan-jianfa",
	             "sword":"kuangfeng-kuaijian",
	             "force":"huashan-neigong",
	             "dodge":"huashan-shenfa",
	             "parry":"huashan-jianfa",
	             "strike":"hunyuan-zhang"]),
	  "unarmed":({"strike"}),
	  "exert": ({"powerup"}),
	  "perform": ({(["cmd":"$PF$ kuangfeng-kuaijian.kuangfeng $TARGET$", "pct":25]),
	               (["cmd":"$PF$ kuangfeng-kuaijian.lianhuan $TARGET$", "pct":50]),
	  	           "$PF$ huashan-jianfa.jianzhang $TARGET$"}),
	  "weapon":({"/clone/weapon/changjian","/d/pingxiwangfu/npc/obj/herosword"}),
	  "special":(["feilong":1, "huashan_newskills/jianzong":1]) ]),
	(["name":HIM"劫匪"NOR,
	  "menpai":(["华山派":19]),
	  "skills":(["#1sword":"huashan-jianfa",
	             "#2sword":"yangwu-jian",
	             "sword":"yunushijiu-jian",
	             "force":"zixia-shengong",
	             "dodge":"huashan-shenfa",
	             "parry":"huashan-jianfa",
	             "strike":"hunyuan-zhang"]),
	  "unarmed":({"strike"}),
	  "exert": ({"powerup"}),
	  "perform": ({(["cmd":"$PF$ yunushijiu-jian.sanqingfeng $TARGET$", "pct":30]),
	  	           "$PF$ huashan-jianfa.jianzhang $TARGET$",
	  	           "$PF$ yangwu-jian.yangwu $TARGET$"}),
	  "weapon":({"/clone/weapon/changjian","/d/pingxiwangfu/npc/obj/herosword"}),
	  "special":(["feilong":1, "huashan_newskills/qizong":1]) ]),
	(["name":HIY"劫匪"NOR,
	  "menpai":(["丐帮":19]),
	  "skills":(["staff":"dagou-bang",
	             "force":"huntian-qigong",
	             "dodge":"xiaoyaoyou",
	             "parry":"dagou-bang",
	             "strike":"xianglong-zhang"]),
	  "unarmed":({"strike"}),
	  "perform": ({"$PF$ staff.chan $TARGET$",
	               "unwield zhu;$PF$ strike.xiao;wield zhu",
	  	           (["cmd":"unwield zhu;$PF$ strike.leiting $TARGET$;wield zhu","pct":10])}),
	  "weapon":({"/kungfu/class/gaibang/yuzhu_zhang","/kungfu/class/gaibang/yuzhu_zhang"}),
	  "special":(["leiting":1]) ]),
	(["name":HIW"劫匪"NOR,
	  "menpai": (["武当派":3]),
	  "skills":(["sword":"taiji-jian",
	             "force":"taiji-shengong",
	             "dodge":"tiyunzong",
	             "parry":"taiji-jian",
	             "cuff":"taiji-quan"]),
	  "unarmed":({"cuff"}),
	  "exert": ({"taiji"}),
	  "perform": ({(["cmd":"$PF$ sword.chan $TARGET$", "pct":50]),
	  	           "$PF$ sword.sui",
	  	           "unwield jian;$PF$ cuff.zhen $TARGET$;wield jian"}),
	  "weapon":({"/clone/weapon/changjian","/d/pingxiwangfu/npc/obj/herosword"})]),
	(["name":HIB"劫匪"NOR,
	  "menpai": (["星宿派":2]),
	  "skills":(["staff":"tianshan-zhang",
	             "force":"huagong-dafa",
	             "dodge":"zhaixinggong",
	             "parry":"tianshan-zhang",
	             "strike":"xingxiu-duzhang"]),
	  "unarmed":({"strike"}),
	  "perform": ({"$PF$ staff.handu $TARGET$",
	  	           "unwield zhang;$PF$ strike.sandu $TARGET$;wield zhang"}),
	  "weapon":({"/d/xingxiu/obj/bingpozhang","/d/xingxiu/obj/bingpozhang"})]),
	(["name":HIR"劫匪"NOR,
	  "menpai":(["全真派":3]),
	  "skills":(["sword":"quanzhen-jian",
	             "force":"xiantian-gong",
	             "dodge":"jinyan-gong",
	             "parry":"quanzhen-jian",
	             "cuff":"kongming-quan",
	             "finger":"yiyang-zhi",
	             "qixing-array":300]),
	  "unarmed":({"cuff"}),
	  "perform": ({"$PF$ sword.jianqi $TARGET$",
	  	           "$PF$ sword.sanqing $TARGET$",
	  	           "$PF$ sword.qixing $TARGET$",
	  	           "$PF$ sword.ding $TARGET$",
	  	           "unwield jian;$PF$ cuff.hubo $TARGET$;wield jian",
	  	           "unwield jian;prepare none;prepare yiyang-zhi;$PF$ finger.fuxue $TARGET$;prepare none;prepare kongming-quan;wield jian"}),
	  "weapon":({"/clone/weapon/changjian","/d/pingxiwangfu/npc/obj/herosword"}),
	  "special":(["zuoyou-hubo":1,"yiyang_zhi/quanzhen":1]) ]),
	(["name":HIC"劫匪"NOR,
	  "menpai":(["桃花岛":3]),
	  "skills":(["sword":"yuxiao-jian",
	             "force":"bihai-shengong",
	             "dodge":"luoying-shenfa",
	             "parry":"yuxiao-jian",
	             "finger":"tanzhi-shengong",
	             "throwing":"tanzhi-shengong",
	             "hand":"fuxue-shou",
	             "qimen-bagua":400,
	             "music::music-theory":400,
	             "music::shaw":400,
	             "music::shaw::meihua-sannong":400,
	             "music::shaw::yuqiao-wenwan":400,
	             "music::shaw::bihai-chaosheng":400,
	             "literate":400]),
	  "unarmed":({"finger","hand"}),
	  "perform": ({(["cmd":"$PF$ sword.chan $TARGET$", "pct":40]),
	  	           (["cmd":"$PF$ sword.zouxiao $TARGET$", "pct":20]),
	  	           "$PF$ sword.xiaohua $TARGET$",
	  	           "unwield jian;$PF$ hand.fuxue $TARGET$;wield jian",
	  	           "$CLONE$ /d/taohuadao/obj/shizi;$PF$ finger.tan $TARGET$"}),
	  "weapon":({"/d/taohuadao/npc/obj/yuxiao","/d/pingxiwangfu/npc/obj/herosword"}),
	  "special":(["zuoyou-hubo":1]) ]),
	(["name":HIG"劫匪"NOR,
	  "menpai":(["少林派":37]),
	  "skills":(["whip":"riyue-bian",
	             "force":"yijin-jing",
	             "dodge":"shaolin-shenfa",
	             "parry":"riyue-bian",
	             "cuff":"luohan-quan",
	             "hunyuan-yiqi":501,
	             "buddhism":500]),
	  "unarmed":({"cuff"}),
	  "exert": ({"jingang"}),
	  "perform": ({(["cmd":"$PF$ whip.chan $TARGET$", "pct":30]),
	  	           "$PF$ whip.fumoquan $TARGET$",
	  	           (["cmd":"unwield bian;$PF$ cuff.luohan $TARGET$;wield bian","pct":20])}),
	  "weapon":({"/clone/weapon/changbian","/clone/weapon/changbian"}) ,
	  "special":(["class":"bonze"]) ]) });
	  	
void create()
{
	set_name(HIM"劫匪"NOR, ({ "cart robber", "robber" }));
	set("title", "拦路抢劫");
	set("gender", "男性");
	set("age", random(30) + 14);
	set("bonus", 1);
	set("vendetta/authority", 1);
	set("no_use/qiankun-danuoyi", 1);
	//        set("no_use/iron-cloth",1);       
	set("busy", 1);

	set("long", "这是一位华山派弃徒。\n");

	set("chat_chance_combat", 14);
	set("chat_msg_combat", ({
		(: exer() : ),
	}));

	setup();
	carry_object("/clone/armor/tiejia")->wear();
	call_out("start_attact", 5, this_object());
	call_out("dest", 900);
}

void init()
{
	set("no_steal", 1);
	set("random_npc", 1);
//	set_temp("pfm_skip",1);
	//        set("chat_chance_combat", 14);
	add_action("no_heal", "yun");
	add_action("no_heal", "exert");
	add_action("no_say", "say");
}

//特殊招式默认每次必发powerup和recover，必检查武器
//然后从robber_skill对应门派劫匪的exeret和perform属性中获得可以发动的特殊招式列表
//其中通配符$TARGET$为对方id，$PF$为perform命令，$CLONE$为clone该通配符空格后面的物品
//如果命令中存在';'则次序执行系列命令。
void exer()
{
	object *enemy, target, weapon, t_obj;
	int menpai, lp, pct, *wgt, t_wgt, prd;
	string *exers, t_exer, *cmds, debug_info;
	mixed pfm;

	menpai = this_object()->query("menpai");
	if (random(100) < 30)
	{
		this_object()->exert_function("powerup");
		this_object()->exert_function("recover");
	}

	if (this_object()->query("busy"))
		return;

	enemy = query_enemy() - ({ 0 });
	target = enemy[random(sizeof(enemy))];
	weapon = this_object()->query_temp("weapon");
	if (!weapon)
		carry_object(robber_skill[menpai]["weapon"][1])->wield();
	weapon = this_object()->query_temp("weapon");
	weapon->set("no_get", 1);
	weapon->set("no_drop_to_room", 1);
	exers = ({});
	wgt = ({});
	t_wgt = 0;
	debug_info = "exert_list:\n";
	if (robber_skill[menpai]["exert"])
	{
		for (lp = 0; lp < sizeof(robber_skill[menpai]["exert"]); lp++)
		{
			exers = exers + ({ "exert " + replace_string(robber_skill[menpai]["exert"][lp], "$TARGET$", target->query("id")) });
			wgt = wgt + ({ 100 });
			t_wgt = t_wgt + 100;
			debug_info += "exert " + replace_string(robber_skill[menpai]["exert"][lp], "$TARGET$", target->query("id")) + ":100\n";
		}
	}

	debug_info += "\nperform_list:\n";

	if (robber_skill[menpai]["perform"])
	{
		for (lp = 0; lp < sizeof(robber_skill[menpai]["perform"]); lp++)
		{
			pfm = robber_skill[menpai]["perform"][lp];
			if (mapp(pfm))
			{
				exers = exers + ({ replace_string(replace_string(pfm["cmd"], "$TARGET$", target->query("id")), "$PF$", "perform") });
				wgt = wgt + ({ pfm["pct"] });
				t_wgt = t_wgt + pfm["pct"];
				debug_info += replace_string(replace_string(pfm["cmd"], "$TARGET$", target->query("id")), "$PF$", "perform") + ":" + pfm["pct"] + "\n";
			}
			else
			{
				exers = exers + ({ replace_string(replace_string(robber_skill[menpai]["perform"][lp], "$TARGET$", target->query("id")), "$PF$", "perform") });
				wgt = wgt + ({ 100 });
				t_wgt = t_wgt + 100;
				debug_info += replace_string(replace_string(robber_skill[menpai]["perform"][lp], "$TARGET$", target->query("id")), "$PF$", "perform") + ":100\n";
			}
		}
	}

	prd = random(t_wgt);
	for (lp = 0; lp < sizeof(wgt); lp++)
	{
		if (prd < wgt[lp])
		{
			t_exer = exers[lp];
			break;
		}
		else
			prd = prd - wgt[lp];
	}
	//    t_exer=exers[random(sizeof(exers))];
	if (wizardp(target))
		tell_object(target, HIR + debug_info + "\nnow:" + t_exer + "\n"NOR);
	if (strsrch(t_exer, ";") < 0)
		command(t_exer);
	else
	{
		cmds = explode(t_exer, ";");
		for (lp = 0; lp < sizeof(cmds); lp++)
		{
			if (strsrch(cmds[lp], "$CLONE$") >= 0)
			{
				t_obj = new(explode(cmds[lp], " ")[1]);
				t_obj->move(this_object());
			}
			else
				command(cmds[lp]);
		}
	}
}

// robber.h

void start_attact(object me)
{
	me->delete("busy", 1);
	return;
}

int no_heal(string arg)
{
	object ppl, me;
	ppl = this_player();
	me = this_object();
	if (!arg)
		return 0;
	if (!me->query("uni_target"))
		return 0;
	if (!ppl) return 0;
	if ((ppl == me->query("uni_target")) && ((arg == "heal") || (arg == "lifeheal")))
	{
		write("战斗中不能疗伤！\n");
		return 1;
	}
	return 0;
}

int no_say(string arg)
{
	object ppl, me;
	int i;
	ppl = this_player();
	me = this_object();
	if (!objectp(ppl)) return 0;
	if (ppl == me->query("uni_target") && arg != "")
	{
		write("你说道：" + arg + "\n");
		write("劫匪怒道：嘴里不干不净地嘟囔什么！看招！\n");
		me->delete("busy", 1);
		me->start_busy(0);
		for (i = 0; i < random(5) + 1; i++)
			COMBAT_D->do_attack(me, ppl, me->query_temp("weapon"));
		return 1;
	}
	return 0;
}

void destroying(object me)
{
	destruct(me);
	return;
}

int dest() //By Zine ，15分钟自毁，有些劫匪在街上一直存在 13 Nov 2010
{
	if (this_object())
	{
		message_vision(CYN"\n$N看看无镖可截，转身离开了。\n"NOR, this_object());
		destruct(this_object());
	}
	return 1;
}

int checking(object me, object ob)
{
	object obgem;
	int mf_rate, lv_rate, diff, deactivity_rate;//限制全自动机器

	if (!ob || !me)
		return 1;

	if (ob->query("antirobot/deactivity") < 2)
		deactivity_rate = 100;
	else
		deactivity_rate = 400 / (ob->query("antirobot/deactivity")*ob->query("antirobot/deactivity")*ob->query("antirobot/deactivity"));

	mf_rate = 35 * deactivity_rate;

	if (ob->query_temp("yb_addi")) //做完附加任务，加下来到下次附加之前掉宝率增加20%，Zine 26 Nov 2010
	{
		mf_rate = mf_rate * 11 / 10;
	}

	lv_rate = to_int(sqrt(to_float(ob->query("level"))));
	if (lv_rate > 10)
	{
		lv_rate = 10;
	}

	diff = ob->query_temp("yunbiao/high_value");
	if (!diff)
		diff = 10;

	mf_rate = mf_rate / 2;
	mf_rate = mf_rate + mf_rate*lv_rate / 10;
	mf_rate = (mf_rate*diff) / 10;      //增加任务难度相关的掉宝率增加  by seagate@pkuxkx

	if ((int)me->query("qi") * 100 / (int)me->query("max_qi") <= 15)
	{
		if (wizardp(ob))
			message_vision(sprintf("%d,%d\n", ob->query_temp("yunbiao/lianxu"), mf_rate), me, ob);
		if (!living(me))
			return 1;
		else
		{
			if (!me->query("rob_unique"))
				ob->add_temp("yunbiao/bonus", me->query("bonus"));

			if (random(ob->query_temp("yunbiao/lianxu")) > random(5) &&
				random(10000) < mf_rate)
				GEM_D->drop_hubiao(me, ob); //控制掉

			message_vision(CYN"\n$N叫道：点子扎手，扯呼！\n\n$N个起纵遁入暗里不见了。\n\n"NOR, me);
			//tell_object(me,CYN"\n$N叫道：点子扎手，扯呼！\n\n$N个起纵遁入暗里不见了。\n\n"NOR);
			destruct(this_object());
			return 1;
		}
	}

	if (me->is_fighting())
	{
		call_out("checking", 2, me, ob);
		return 1;
	}

	if (!me->is_fighting() && living(ob) && objectp(present(ob->query("id"), environment())))
	{
		me->fight_ob(ob);
		call_out("checking", 2, me, ob);
		return 1;
	}

	if ((!present(ob->query("id"), environment()) || !living(ob)) && present("biao che", environment()))
	{
	//	command("laugh");
		command("sword");
		command("love1 " + ob->query("id"));
		command("tiaoxi " + ob->query("id"));
		command("jie biao che");
		message_vision("$N推着镖车呼啸而去。\n", me);
//		tell_object(me,"$N推着镖车呼啸而去。\n");
		call_out("destroying", 1, me);
		return 1;
	}

	if (!present(ob->query("id"), environment()))
	{
		message_vision("$N悻悻的说：“算你跑的快！”\n", me);
	//	command("sigh");
		command("sword");
		command("jie biao che");
		message_vision("$N身行几起几纵消失在暗处\n", me);
		//tell_object(me,"$N身行几起几纵消失在暗处\n");

		call_out("destroying", 1, me);
		return 1;
	}

	if (present(ob->query("id"), environment()) && !living(ob) && present("biao che", environment()))
	{
	//	command("laugh");
		command("jie biao che");
		command("love1 " + ob->query("id"));
		command("tiaoxi " + ob->query("id"));
		message_vision("$N推着镖车呼啸而去。\n", me);

	//	tell_object(me,"$N推着镖车呼啸而去。\n");

		call_out("destroying", 1, me);
		return 1;
	}

	if (me->query("rob_unique") && (!present(ob->query("id"), environment()) || !living(ob)))
	{
		command("haha");
		command("get all from " + ob->query("id"));
		message_vision("$N身行几起几纵消失在暗处\n", me);
//		tell_object(me,"$N身行几起几纵消失在暗处\n");

		call_out("destroying", 1, me);
		return 1;
	}

	if (present(ob->query("id"), environment()) && !living(ob) && !present("biao che", environment()))
	{
		command("sigh");
		message_vision("$N身行几起几纵消失在暗处\n", me);
//		tell_object(me,"$N身行几起几纵消失在暗处\n");

		call_out("destroying", 1, me);
		return 1;
	}
}

void unconcious()
{
	die();
}

void die()
{
	int mf_rate, deactivity_rate, lv_rate, diff;//限制全自动机器
	object ob;
	string day;

	//message_vision(sprintf("%O\n", this_object()->query("uni_target") ), this_object());

	if (objectp(this_object()->query("uni_target")))
	{
		ob = this_object()->query("uni_target");

		if (objectp(ob))
		{
			if (ob->query("antirobot/deactivity") < 2)
				deactivity_rate = 100;
			else
				deactivity_rate = 400 / (ob->query("antirobot/deactivity")*ob->query("antirobot/deactivity")*ob->query("antirobot/deactivity"));

			mf_rate = 35 * deactivity_rate;
			if (ob->query_temp("yb_addi")) //做完附加任务，加下来到下次附加之前掉宝率增加20%，Zine 26 Nov 2010
			{
				mf_rate = mf_rate * 11 / 10; //降低加成到10%，Zine 6-14-2011
			}

			lv_rate = to_int(sqrt(to_float(ob->query("level"))));
			if (lv_rate > 10)
				lv_rate = 10;

			diff = ob->query_temp("yunbiao/high_value");
			if (!diff)
				diff = 10;

			mf_rate = mf_rate / 2;
			mf_rate = mf_rate + mf_rate*lv_rate / 10;
			mf_rate = (mf_rate*diff) / 10;      //增加任务难度相关的掉宝率增加  by seagate@pkuxkx

			//增加休闲玩家的处理，休闲玩家每天只能得到400次高概率掉宝
			if (userp(ob) && ob->query("xiuxian_player"))
			{
				day = gctime(0, 1);
				if (ob->query("xiuxian/date") != day)
				{
					ob->delete("xiuxian");
					ob->set("xiuxian/date", day);
				}

				if (ob->query("xiuxian/hubiao_gem") < 500)
				{
					mf_rate = mf_rate * 2;
					ob->add("xiuxian/hubiao_gem", 1);
				}
				else if (ob->query("xiuxian/hubiao_gem") < 1000)
				{
					mf_rate = mf_rate * 3 / 2;
					ob->add("xiuxian/hubiao_gem", 1);
				}
				else if (ob->query("xiuxian/hubiao_gem") < 2000)
				{
					ob->add("xiuxian/hubiao_gem", 1);
				}
				else
				{
					tell_object(ob, "你今天已经太累了，可以休息休息了。\n");
					mf_rate = mf_rate / 4;
				}
			}

			if (wizardp(ob))
				message_vision(sprintf("%d,%d\n", ob->query_temp("yunbiao/lianxu"), mf_rate), this_object(), ob);

			if (objectp(ob) && !this_object()->query("rob_unique"))
			{
				ob->add_temp("yunbiao/bonus", this_object()->query("bonus"));
				ob->add_temp("yunbiao/killed_num", 1);
				if (random(ob->query_temp("yunbiao/lianxu")) > random(5) &&
					random(10000) < mf_rate)
					GEM_D->drop_hubiao(this_object(), ob); //控制掉落率             
			}
		}
	}

	message_vision(CYN"\n$N叫道：点子扎手，扯呼！\n\n$N个起纵遁入暗里不见了。\n\n"NOR, this_object());
	destruct(this_object());
}

void do_change(object ob)
{
	object me, robber;
	mapping skills, hp_status, skill_status, family, rob_status, rob_skill;
	string *sname, *robsk;
	int i, temp, factor, exp, count, tempskill, lianxu, diff, menpai, robs, eslvl, mhp, enhance, temp_level;
	enhance = 0;//增强型劫匪
	
	me = this_object();
	temp = 0;
	tempskill = 0;
	lianxu = ob->query_temp("yunbiao/lianxunum");
	exp = ob->query("combat_exp");
	diff = ob->query_temp("yunbiao/high_value");
	if (!diff)
		diff = 10;
	eslvl = F_ESCORT->query_escort_level(diff);
	//增强型劫匪概率 1%
	if ((eslvl == 1 && random(200) < 1) || (eslvl == 2 && random(100) < 2))
	{
		enhance = 1;
		eslvl += 1;
		diff += 5;
		me->set_temp("apply/kf_def_wound", 25);
		me->set_temp("apply/kf_anti_hr", 2);
		me->set_temp("apply/kf_hit_rate", 2);
		exp = exp / 10 * 15;	//经验提高50%
	}
	
	//设置劫匪发招几率，随着难度提高劫匪发招几率
	me->set("chat_chance_combat", 10 + eslvl * 4);

	menpai = random(sizeof(robber_skill));
	me->set("menpai", menpai);
	me->set("name", robber_skill[menpai]["name"]);
	family = robber_skill[menpai]["menpai"];
	create_family(keys(family)[0], family[keys(family)[0]], "弟子");
	me->set("long", "这是一位" + keys(family)[0] + "弃徒。\n");
	carry_object(robber_skill[menpai]["weapon"][0])->wield();
	if (rob_status = robber_skill[menpai]["special"])
	{
		for (i = 0; i < sizeof(rob_status); i++)
			me->set(keys(rob_status)[i], rob_status[keys(rob_status)[i]]);
	}

	if (!enhance && exp > 400000000)
		exp = 400000000;
	if (enhance && exp > 600000000)
		exp = 600000000;//bt劫匪600m封顶
	
	tempskill = to_int(pow(exp / 100, 0.333) * 10);
	tempskill = to_int(tempskill * (50 + random(35) + (diff - 10) * 5) / 100);
	if (tempskill <= 100)
		tempskill = 100;
	rob_skill = robber_skill[menpai]["skills"];
	robsk = keys(rob_skill);
	for (i = 0; i < sizeof(robsk); i++)
	{
		if (intp(rob_skill[robsk[i]]))
		{
			if (diff >= 10)
				me->set_skill(robsk[i], rob_skill[robsk[i]] + (diff - 10) * 100);
			else
				me->set_skill(robsk[i], rob_skill[robsk[i]] + (diff - 10) * 20);
		}
		else
		{
			me->set_skill(rob_skill[robsk[i]], tempskill);
			if (robsk[i][0] != '#')
			{
				me->set_skill(robsk[i], tempskill);
				map_skill(robsk[i], rob_skill[robsk[i]]);
				if (member_array(robsk[i], robber_skill[menpai]["unarmed"]) >= 0)
					prepare_skill(robsk[i], rob_skill[robsk[i]]);
			}
		}
	}

	/* copy hp */
	hp_status = ob->query_entire_dbase();
	me->set("str", hp_status["str"] + random(2) + (diff - 10));
	me->set("int", hp_status["int"] + random(2) + (diff - 10));
	me->set("con", hp_status["con"] + random(2) + (diff - 10));
	me->set("dex", hp_status["dex"] + random(2) + (diff - 10));
	// me->set("combat_exp",to_int(hp_status["combat_exp"]*(random(5)+8)/10))
	me->set("combat_exp", to_int(exp / 100 * (80 + lianxu * 3 + random(3) + (diff - 10) * 3)));
	if (random(60) <= 3)
		me->set("combat_exp", to_int(exp*(random(8) + 8 + (diff - 10) / 2) / 10));
	if (me->query("combat_exp") < 500000)
		me->set("combat_exp", 500000);

	mhp = hp_status["max_qi"];
	if (eslvl == 0 && mhp < 1000)
		mhp = 1000;
	else if (eslvl == 0 && mhp >= 10000)
		mhp = 10000;

	if (eslvl == 1 && mhp < 2000)
		mhp = 2000;
	else if (eslvl == 1 && mhp >= 20000)
		mhp = 20000;

	if (eslvl == 2 && mhp < 10000)
		mhp = 10000;
	else if (eslvl == 2 && mhp >= 30000)
		mhp = 30000;
	
	if (eslvl == 3 && mhp < 20000)
		mhp = 20000;
	else if (eslvl == 2 && mhp >= 40000)
		mhp = 40000;

	me->set("qi", mhp*diff / 10);
	me->set("eff_qi", mhp*diff / 10);
	me->set("max_qi", mhp*diff / 10);
	me->set("max_neili", hp_status["max_neili"] * diff / 10);
	me->set("neili", hp_status["max_neili"] * diff / 10);
	me->set("max_jingli", hp_status["max_jingli"] * diff / 10);
	me->set("jingli", hp_status["jingli"] * diff / 10);
	me->set("jing", hp_status["max_jing"] * diff / 10);
	me->set("eff_jing", hp_status["max_jing"] * diff / 10);
	me->set("max_jing", hp_status["max_jing"] * diff / 10);
	me->set("jiali", diff * 10 + random(50));
	me->set("level",me->query("level")+random(5));
	me->set_temp("apply/armor", diff * 16 + random(80));
	//icer added to avoid short jing damage bug
	if (me->query("jing") < 2000)
	{
		me->set("eff_jing", 2000);
		me->set("max_jing", 2000);
		me->set("jing", 2000);
	}

	count = 1;
	if (!me->query("sp"))
	{
		temp = hp_status["qi"] / 4000;
		factor = 10 + temp * 10;
		if (factor == 10)
			factor = 15;

		robs = ob->query_temp("yunbiao/killed_num") / factor + temp;

		if (eslvl == 0 && robs > 1)
			robs = 1;
		else if (eslvl == 1 && robs > 2)
			robs = 2;
		else if (eslvl == 1 && robs < 1)
			robs = 1;
		else if (eslvl >= 2 && robs < 2)
			robs = 2;
		if (wizardp(ob))
			tell_object(ob, sprintf("劫匪数量参数：%d, 镖局参数：%d\n", robs, eslvl));

		for (i = 0; i < robs; i++)
		{
			if (count > 3)
				break;
			message_vision(HIR"劫匪大喊：点子爪子硬！赶紧来帮忙！\n"NOR, ob);
			me->add("bonus", 1);
			robber = new("/quest/escort/cart_robber");
			count++;
			robber->set("uni_target", ob);
			robber->set("title", "拦路抢劫" + ob->query("name") + "的");
			robber->set_name(robber->query("name"), ({ ob->query("id") + "'s robber", ob->query("id") + " robber", "robber" }));
			robber->set("sp", 1);
			robber->do_change(ob);
			robber->move(environment(ob));
			robber->fight_ob(ob);
			robber->checking(robber, ob);
			robber->command("rob");
		}
	}
}