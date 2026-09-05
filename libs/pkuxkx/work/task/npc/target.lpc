
// /task/npc/target.c
//Made by jason@pkuxkx
//2001.1.3
#include <ansi.h>
inherit NPC;

int other_qi,other_jing;

int leave();
void auto_perform();
void give_reward(object owner_ob, int task_type);
void copy_hp(object plyr);
int destruct_npc();
string ask_for_move();

void create()
{
	string nickname,name,*tmp,*pinying;
	name=NAME_D->create_name();
	nickname=NAME_D->create_color_nick();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");	
	
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("nickname",nickname);
	set("gender",random(3)>0?"男性":"女性");//male sadan is more..:)
    set("is_tasknpc", 1);
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({(: auto_perform :),}));
	set("inquiry", ([
		"fight" : (:ask_for_move :),
	]) );
    setup();
}


void auto_perform()
{
    object weapon;
//        command("exert powerup")
    command("exert recover");
/*
        weapon = this_object()->query_temp("weapon");
        if (!weapon)
                carry_object("/d/pingxiwangfu/npc/obj/herosword")->wield();
*
*/
    weapon = this_object()->query_temp("weapon");
    if (weapon)
        weapon->set("no_get", 1);
}

void init()
{
    int lvl, i, j;
    string *sname,*pname,*mname,*tmp;
    string *skls = ({"force", "dodge", "strike", "unarmed", "blade", "sword", "parry",});
    string *ks_skill = ({"claw", "finger", "strike", "cuff", "unarmed", "hand", "leg"});
    string sk_type, max_sk;
    int max_sklvl, all_max_sklvl;
    mapping skill_status, prepare_status, map_status, wprepare_status;
    object tempob;
    object ppl = this_player();
	object enemy;
	
    if (ppl->query_temp("task_target") == query("id")
        && query("task_bekill") == ppl->query("id"))
    {
        object me = this_player();
        object output = this_object();
        object weapon, weapon2, ar;
        mapping armor;

        add_action("do_change", "wield");
        add_action("do_change", "put");
        add_action("do_change", "changewield");
        add_action("do_change", "wear");
        add_action("do_change", "unwield");
        add_action("do_change", "remove");
        add_action("do_change", "drop");
        add_action("do_enable", "enable");
        add_action("do_enable", "jifa");
        add_action("do_enable", "bei");
        add_action("do_enable", "wbei");
        add_action("do_enable", "prepare");

        if (output->query_temp("met_time") == 1 || (output->query_temp("task_type")>0 && output->query_temp("task_type") != 3) || output->query("npc_task_target"))
            return;

        if (!output->query_temp("met_time"))
        {
            output->set_temp("met_time", 1);
			output->set("chat_chance", 10);      // 发现NPC之后就调低一点乱跑的概率。
			output->set("task_type", 1+random(3)); // 修改 task 玩法：第一次见面时随机设置任务类型。by lordstar 2017/8/27
            if (output->query("task_type")==3) 
			{
				output->random_move();
			}
			else 
			{
				output->delete("chat_chance");				
			}
        }

        if (output->query_temp("met_time") == 1 && output->query("task_type")==3)
        {
            output->set_temp("met_time", 2);
            output->random_move();
        }

        output->set_temp("met_time", 2);

        if (query_temp("weapon"))
        {
            destruct(output->query_temp("weapon"));
            delete_temp("weapon");
        }
        if (query_temp("secondary_weapon"))
        {
            destruct(output->query_temp("secondary_weapon"));
            delete_temp("secondary_weapon");
        }
        if (armor = output->query_temp("armor"))
        {
            tmp = keys(armor);
            for (i = sizeof(armor) - 1; i >= 0; i--)
            {
                destruct(armor[tmp[i]]);
            }
            delete_temp("armor");
        }
        if (tempob = me->query_temp("weapon"))
        {
            weapon = new(base_name(tempob));
            if (weapon->query("seed")) // random weapon
                weapon->gen_weapon(tempob->query("seed"));
            else if (tempob->query("cjg_weapon"))
                weapon->set_cjg_weapon(tempob->query("cjg_weapon"));
            weapon->set("weapon_prop/damage",
                        tempob->query("weapon_prop/damage") / 2);
            if (weapon->is_gems())
            {
                weapon->set("owner_id", query("id"));
                weapon->set("gem_ob_autoloaded", 1);
            }
            weapon->set("owner", query("id"));
            weapon->set("value", 0);
            weapon->set("no_get", 1);
            weapon->set("no_give", 1);
            weapon->set("no_drop", 1);
            weapon->set("no_store", 1);
            weapon->move(output);
            weapon->wield();
        }
        if (tempob = me->query_temp("secondary_weapon"))
        {
            weapon = new(base_name(tempob));
            if (weapon->query("seed")) // random weapon
                weapon->gen_weapon(tempob->query("seed"));
            else if (tempob->query("cjg_weapon"))
                weapon->set_cjg_weapon(tempob->query("cjg_weapon"));
            weapon->set("weapon_prop/damage",
                        tempob->query("weapon_prop/damage")/2);
            if (weapon->is_gems())
            {
                weapon->set("owner_id", query("id"));
                weapon->set("gem_ob_autoloaded", 1);
            }
            weapon->set("owner",query("id"));
            weapon->set("value",0);
            weapon->set("no_get",1);
            weapon->set("no_give",1);
            weapon->set("no_drop",1);
            weapon->set("no_store",1);
            weapon->move(output);
            weapon->wield();
            if (!me->query_temp("weapon"))   //防止左手拿针右手空bug
            {
                /* output->delete_temp("weapon");
                output->set_temp("secondary_weapon", weapon); */
                output->changewield();
            }
        }
        if (armor = me->query_temp("armor"))
        {
            tmp = keys(armor);
            for (i = 0; i < sizeof(armor); i++)
            {
                tempob = armor[tmp[i]];
                ar = new(base_name(armor[tmp[i]])) ;
                if (tempob->query("cjg_armor"))
                {
                    ar->set_cjg_armor(tempob->query("cjg_armor"));
                }
                else if (tempob->is_gems()) //random armor
                {
                    ar->gen_armor(tempob->query("type"));
                    ar->set("armor_prop/armor", tempob->query("armor_prop/armor"));
                }
                if (ar->is_gems())
                {
                    ar->set("owner_id", query("id"));
                    ar->set("gem_ob_autoloaded", 1);
                }
                ar->set("owner",query("id"));
                ar->set("value",0);
                ar->set("no_get",1);
                ar->set("no_drop",1);
                ar->set("no_give",1);
                ar->set("no_store",1);
                ar->set("owner",query("id"));
                ar->move(output);
                ar->wear();
            }
//            command("wear all");
        }
        if (me->query("zyhb"))
            output->set("zyhb", 1);
/*        if (me->query("env/no_hubo") && random(2))
            output->delete("zyhb"); */

        lvl = me->query_temp("task_level");

        if (mapp(skill_status = me->query("weapon")))
            output->set("weapon", skill_status);
        else
            output->delete("weapon");

        if (mapp(skill_status = me->query_skills()))
        {
//            skill_status = me->query_skills();
            sname  = keys(skill_status);

            /* 复制技能 */
            for (i = 0; i < sizeof(skill_status); i++)
            {
                if (intp(skill_status[sname[i]]))
                {
                    output->set_skill(sname[i], skill_status[sname[i]] + (lvl - 4));
                    output->map_skill(sname[i]);
                    output->prepare_skill(sname[i]);
                }
            }

			all_max_sklvl = 0;
			
            /* 激发右手武器技能 */
            if ( objectp(weapon = output->query_temp("weapon")) )
            {
                sk_type = weapon->query("skill_type");
                max_sklvl = 0;
                for (i = 0; i < sizeof(skill_status); i++)
                {
                    if ( SKILL_D(sname[i])->valid_enable(sk_type) == 1 && output->query_skill(sname[i], 1) > max_sklvl )
                    {
                        max_sk = sname[i];
                        max_sklvl = output->query_skill(sname[i], 1);
                    }
                }
                if ( max_sklvl > 0 )
                {
                    output->map_skill(sk_type, max_sk);
					all_max_sklvl = max_sklvl;
                }
            }

            /* 激发左手武器技能 */
            if ( objectp(weapon2 = output->query_temp("secondary_weapon")) )
            {
                sk_type = weapon2->query("skill_type");
                max_sklvl = 0;
                for (i = 0; i < sizeof(skill_status); i++)
                {
                    if ( SKILL_D(sname[i])->valid_enable(sk_type) == 1 && output->query_skill(sname[i], 1) > max_sklvl )
                    {
                        max_sk = sname[i];
                        max_sklvl = output->query_skill(sname[i], 1);
                    }
                }
                if ( max_sklvl > 0 )
                {
                    output->map_skill(sk_type, max_sk);
					if ( all_max_sklvl < max_sklvl ) all_max_sklvl = max_sklvl;
                }
            }

            /* 激发轻功技能 */
            max_sklvl = 0;
            for (i = 0; i < sizeof(skill_status); i++)
            {
                if ( SKILL_D(sname[i])->valid_enable("dodge") == 1 && output->query_skill(sname[i], 1) > max_sklvl )
                {
                    max_sk = sname[i];
                    max_sklvl = output->query_skill(sname[i], 1);
                }
            }
            if ( max_sklvl > 0 )
            {
                output->map_skill("dodge", max_sk);
				if ( all_max_sklvl < max_sklvl ) all_max_sklvl = max_sklvl;
            }

            /* 激发内功技能 */
            max_sklvl = 0;
            for (i = 0; i < sizeof(skill_status); i++)
            {
                if ( SKILL_D(sname[i])->valid_enable("force") == 1 && output->query_skill(sname[i], 1) > max_sklvl )
                {
                    max_sk = sname[i];
                    max_sklvl = output->query_skill(sname[i], 1);
                }
            }
            if ( max_sklvl > 0 )
            {
                output->map_skill("force", max_sk);
				if ( all_max_sklvl < max_sklvl ) all_max_sklvl = max_sklvl;
            }

            /* 激发招架技能 */
            output->map_skill("parry", me->query_skill_mapped("parry"));

            /* 激发空手技能 */
            max_sklvl = 0;
            for (i = 0; i < sizeof(ks_skill); i++)
            {
                for (j = 0; j < sizeof(skill_status); j++)
                {
                    if ( SKILL_D(sname[j])->valid_enable(ks_skill[i]) == 1 && output->query_skill(ks_skill[i], sname[j]) > max_sklvl )
                    {
                        sk_type = ks_skill[i];
                        max_sk = sname[j];
                        max_sklvl = output->query_skill(sk_type, max_sk);
                    }
                }
            }
            if (max_sklvl > 0)
            {
                output->map_skill(sk_type, max_sk);
                output->prepare_skill(sk_type, max_sk);
				if ( all_max_sklvl < max_sklvl ) all_max_sklvl = max_sklvl;
            }

            //task npc 基本功夫最低等级
            for (i = 0; i < sizeof(skls); i++)
            {
                if (output->query_skill(skls[i], 1) < 30)  
                    output->set_skill(skls[i], 30);
            }
        }

        if (output->query("combat_exp") < 3000)
            output->set("combat_exp", 3000);

        output->reset_action();

		if (output->query("task_type")==3) // 保留原有斩杀模式
		{
			command("say 不是冤家不聚头，纳命来吧！！");
			if (random(4) > 1)
				output->kill_ob(me);
		}
		else if (output->query("task_type")==1 && !output->query("npc_task_target"))  // 加入第二个模式：逮捕双贼
		{
			enemy = new(__DIR__"enemy",1);
			enemy->set("owner_id", me->query("id"));
			enemy->set("npc_task_target", output->query("id"));
			output->set("npc_task_target", enemy->query("id"));
			enemy->move(environment(output));
			output->copy_hp(me);
			enemy->init_skills(all_max_sklvl);
			enemy->copy_hp(me);
			command("say " + enemy->query("name") + "你个王八羔子，想独吞宝物？没那么容易！受死吧！！");
			tell_object(me, HIW"看样子两个恶贼起了内讧，正好趁他们打得筋疲力尽的时候，一网打尽逮捕(arrest/daibu)他们！\n\n"NOR);
			tell_object(me, HIW"一位埋伏在周边的捕快偷偷告诉你：「别忘了 " + HIR + "set broadcast_combat 1"+ HIW +" 才能更好观察贼人们的战斗。」\n\n"NOR);
			enemy->set_leader(output);
			output->set_leader(enemy);
			enemy->kill_ob(output);
			output->kill_ob(enemy);
			me->set_temp("task/arrest_rate", 1+random(5));
		}
		else if (output->query("task_type")==2 && !output->query("npc_task_target"))  // 第三个模式：歼灭真凶
		{
			enemy = new(__DIR__"villain",1);
			enemy->set("owner_id", me->query("id"));
			enemy->set("npc_task_target", output->query("id"));
			output->set("npc_task_target", enemy->query("id"));
			enemy->move(environment(output));
			enemy->init_skills(all_max_sklvl);
			enemy->copy_hp(me);
			output->copy_hp(me);
			command("say " + enemy->query("name") + "你偷走宝物也就罢了，竟然栽赃给我，害我平白蒙冤！还想往哪逃？受死吧！！");
			tell_object(me, HIG"看样子事情不对，真凶另有其人！行侠仗义也不能随意冤枉无辜！\n\n"NOR);
			tell_object(me, HIG"直觉告诉你应该帮助"+output->query("name")+ HIR+" 击杀"+ enemy->query("name") 
					+ HIG + " 此贼轻功不凡，为防其脱逃，你要 " + HIR + "速战速决 "+ HIG + "！\n"NOR);
			tell_object(me, HIG + output->query("name")+HIG"偷偷告诉你：「教你一招 "HIR"夺魂弯钩"HIG"(gou) 有奇效，当然，用不用在你……」\n\n"NOR);
			enemy->set_leader(output);
			output->set_leader(enemy);
			enemy->kill_ob(output);
			output->kill_ob(enemy);
			if (environment(enemy)->query("no_fight"))
				enemy->set("leave_later", 1);
		}
	}
}

string ask_for_move()
{
	object me = this_player();
	object ob = this_object();
	object tar;
	if (ob->query("task_bekill") != me->query("id"))
		return "关你什么事？滚！";
	if (wizardp(me) || environment(ob)->query("no_fight"))
	{
		if (ob->query("task_type")==1 || ob->query("task_type")==2)
		{
			command("say 知道了，知道了，打个架都不爽快，烦死了……");
			tar = present( ob->query("npc_task_target"), environment(ob));
			if (objectp(tar))
			{
				command("say "+tar->query("name")+"我们走！换个地方老子再好好收拾你！");
				ob->remove_all_killer();
				ob->random_move();
				if (environment(ob) != environment(tar))
					tar->move(environment(ob));
				ob->kill_ob(tar);
				tar->kill_ob(ob);
				return tar->query("name")+"别走，看招！";
			}
			else
			{
				command("fly");
				return "我的对手都不在这里，还挪什么挪？";
			}
		}
		ob->random_move();
		return "换地方就换地方，老子会怕你吗？";
	}
	else
		return "要打便打，问来问去的烦不烦啊？";
}

int do_change(string arg)
{
    object ppl = this_player();
    if (ppl->query_temp("task_target") == query("id")
        && query("task_bekill") == ppl->query("id"))
    {
        write("临阵换装，来不及了吧？\n");
        return 1;
    }
    return 0;
}

int do_enable(string arg)
{
    object ppl = this_player();
    if (ppl->query_temp("task_target") == query("id")
        && query("task_bekill") == ppl->query("id"))
    {
        write("临阵换招，来不及了吧？\n");
        return 1;
    }
    return 0;
}

//由于第三个参数不再是object，需要做出相应的判断by boost 2007-09-12
varargs int receive_wound(string type, int damage, mixed who)
{
    string owner = query("task_bekill");
    int ret = 0;
    object killer;

    ret = ::receive_damage(type, damage, who);
	
	if (this_object()->query("task_type")!=3) 
		return ret;
	
    killer = get_damage_origin_object();

    if (killer && objectp(killer) && userp(killer) && killer->query("id") != owner)
    {
        if (damage > 0)
        {
            switch (type)
            {
            case "qi":
                other_qi += damage; break;
            case "jing":
                other_jing += damage; break;
            }
        }
    }
    return ret;
}
//由于第三个参数不再是object，需要做出相应的判断by boost 2007-09-12
varargs int receive_damage(string type, int damage, mixed who)
{
    string owner = query("task_bekill");
    int ret = 0;
    object killer;

//需要先判断是否为objectp，再判断是否为userp，因为objectp接受mixed参数，而userp接受object参数
//如果将一个非object强行转为object后任何query动作都会导致没有心跳的错误！  by boost 2007-09-12
    ret = ::receive_damage(type, damage, who);
	
	if (this_object()->query("task_type")!=3) 
		return ret;
	
    killer = get_damage_origin_object();

    if (killer && objectp(killer) && userp(killer) && killer->query("id") != owner)
    {
        if (damage > 0)
        {
            switch (type)
            {
            case "qi":
                other_qi += damage; break;
            case "jing":
                other_jing += damage; break;
            }
        }
    }
    return ret;
}

// This is called in heart_beat() to perform attack action.
int attack()
{
    object opponent;

    clean_up_enemy();

    opponent = select_opponent();
    if (objectp(opponent))
    {
        string owner = query("task_bekill");
        set_temp("last_opponent", opponent);
        COMBAT_D->fight(this_object(), opponent);
        return 1;
    }
    else
        return 0;
}

void unconcious()
{
    die();
}

void die()
{
    string owner;
    object owner_ob;
	object tar;
    object me = this_object();

	if (me->query("task_type")==3) // 原有斩杀模式
	{
		owner = query("task_bekill");
		if (stringp(owner) && objectp(owner_ob = find_player(owner)))
		{
			if (owner_ob->query_temp("task_target") != query("id")
            || get_damage_origin_object() != owner_ob)
			//modified by icer
			//别人杀的不算
			{
            //log_file("task","leave fuc \n");
				message("vision", HIM + me->name() + HIM "见势不妙，偷偷地开溜了……\n" NOR, environment());
				leave();
				return;
			}
			if (environment(owner_ob) == environment() && living(owner_ob))
			{
				message("vision", HIC + me->name() + HIC "喷出一口鲜血，缓缓倒了下去。\n" NOR, environment());
			}
			give_reward(owner_ob, 0);
			owner_ob->delete_temp("task_target");
		}
//		destruct(this_object());
	}
	else if (me->query("task_type")==1 && !me->query("task_done"))
	{
		message("vision", HIC"\n" + me->name() + HIC"不甘心地怒吼了一声：可恶！我的宝物还没抢回……话犹未尽，两腿一蹬，死了。\n"NOR, environment());
		if (me->query("npc_task_target") && objectp(tar = present( me->query("npc_task_target"), environment(me)) ) 
			&& tar->query("is_tasknpc") )
		{
			message("vision", HIY + tar->name() + "捂着怀里的宝物大笑了三声，跳进路旁的草丛中不见了。\n"NOR, environment());
			tar->destruct_npc();
		}
	}
	else if (me->query("task_type")==2 && !me->query("task_done"))
	{
		message("vision", HIC"\n" + me->name() + HIC"不甘心地怒吼了一声：可恨！我竟不能洗雪此冤……话犹未尽，两腿一蹬，死了。\n"NOR, environment());
		if (me->query("npc_task_target") && objectp(tar = present( me->query("npc_task_target"), environment(me)) ) 
			&& tar->query("is_tasknpc") )
		{
			message("vision", HIY + tar->name() + "大笑了三声，跳进路旁的草丛中不见了。\n"NOR, environment());
			tar->delete("siwang_wangou");
			tar->destruct_npc();
		}
	}	
	remove_call_out("leave");
	::die();
}

void give_reward(object owner_ob, int task_type)
{
	int max_qi, max_jing, ratio, exp_r, pot_r, cost_time, rt;
    max_qi = query("max_qi");
    max_jing = query("max_jing");
      ratio = 100 * (max_qi - other_qi) / max_qi;
        if (ratio < 0)
            ratio = 0;
        ratio = ratio * (max_jing - other_jing) / max_jing;

        if (ratio < 0)
            ratio = 0;

        exp_r = query("kill_reward/exp") * ratio / 100;
        pot_r = query("kill_reward/pot") * ratio / 125;
        //modified by iszt, 奖励在icer改动基础上调高若干，advent说10%，害我算了半天得9/1000和13/2000又不要了，kick
        if (owner_ob->query("special_skill/lucky") && owner_ob->query("age") >= 18)
        {
            exp_r = exp_r + exp_r / 10; //有lucky的玩家奖励多10%,by whuan
            pot_r = pot_r + pot_r / 10;
        }

        exp_r = exp_r * SPEWEEK_D->query_task_bonus() / 100;
        pot_r = pot_r * SPEWEEK_D->query_task_bonus() / 100;
		
		switch ((int)query("task_type"))
		{
			case 1: rt = 28; break;
			case 2: rt = 21; break;
			default: rt = 18;
		}
		exp_r = exp_r * rt / 10;
		pot_r = pot_r * rt / 10;
		
        ANTIROBOT_D->same_as_fullme(owner_ob);

        exp_r = REWARD_D->add_exp(owner_ob, exp_r);
        pot_r = REWARD_D->add_pot(owner_ob, pot_r);

        REWARD_D->add_rep(owner_ob, to_int(owner_ob->query_temp("task_level")) * 10 + 10);
        REWARD_D->add_money(owner_ob, 10000 + random(10000));
        TASK_D->task_step2_done(owner_ob);
        owner_ob->add("exp/task", exp_r);
        owner_ob->add("pot/task", pot_r);

        if (owner_ob->query_temp("task_level") >= 9)
            owner_ob->set_temp("task_level", 6);
        else
            owner_ob->add_temp("task_level", 1);

        tell_object(owner_ob, "你被奖励了" + chinese_number(exp_r) + "点经验和" + chinese_number(pot_r) + "点潜能!\n");
        tell_object(owner_ob, "你获得了金钱奖励！\n");
        CHANNEL_D->do_channel(this_object(), "sys_misc", sprintf("%sTask获得经验：%d、潜能：%d。", owner_ob->name(), exp_r, pot_r));

		"/adm/daemons/gemd"->drop(this_object(), owner_ob); //drop物品
		
        //加入任务统计系统 by icer
        cost_time = time() - owner_ob->query_temp("task_stat/task/task_starttime");
        COMBAT_D->add("task_stat/task/complete_times", 1);
        COMBAT_D->add("task_stat/task/cost_time", cost_time);
        COMBAT_D->add("task_stat/task/exp", exp_r);
        COMBAT_D->add("task_stat/task/pot", pot_r);
        COMBAT_D->add("task_stat/task/expratio", to_float(exp_r) / owner_ob->query("combat_exp"));

}

void copy_hp(object plyr)
{
	int qi,jing;
	object ob=this_object();
	if (!plyr) return;
    ob->set("str", plyr->query("str"));
    ob->set("int", plyr->query("int"));
    ob->set("con", plyr->query("con"));
    ob->set("dex", plyr->query("dex"));
    ob->set("combat_exp", 11*plyr->query("combat_exp")/10);
	qi = 11*plyr->query("max_qi")/10;
	jing = 11*plyr->query("max_jing")/10;
	ob->set("max_qi", qi);
    ob->set("max_jing", jing);
	ob->set("eff_qi", qi);
    ob->set("eff_jing", jing);
	ob->set("qi", qi);
    ob->set("jing", jing);
    ob->set("jingli", 2*plyr->query("max_jingli"));
    ob->set("max_jingli", plyr->query("max_jingli"));
    ob->set("neili", 2*plyr->query("max_neili"));
    ob->set("max_neili", plyr->query("max_neili"));
	ob->set("shen", plyr->query("shen"));
}

int goto_leave()
{
    remove_call_out("leave");
	if (query("wait_time"))
	{
		call_out("leave", query("wait_time"));
	}
	else 
	{
		call_out("leave", 1);
	}
    return 1;
}

int leave()
{
//    command("haha");
//    command("say 东西是我拿的，人也是我杀的，谁能把我怎么样？哈哈哈……\n");
    destruct(this_object());
    return 1;
}

int destruct_npc()
{
	remove_call_out("leave");
	this_object()->move(VOID_OB);
	call_out("leave", 1);
}