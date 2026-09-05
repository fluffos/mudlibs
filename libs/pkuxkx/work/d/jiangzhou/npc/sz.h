#include <ansi.h>
#include <math.h>
void move();


void init()
{
	object weapon,weapon2;
	add_action("do_none", "steal");
	add_action("do_none", "attack");
	add_action("do_none", "beg");
	add_action("do_perform", "perform");
	if(this_player() ==query("killer"))
	kill_ob(this_player());
	remove_call_out("leave");
	set("random_npc",1);
    set("isshuizei",1);
    if (weapon=query_temp("weapon"))
	weapon->set("no_get",1);
    if (weapon2=query_temp("secondary_weapon"))
	weapon2->set("no_get",1);
    call_out("kill_target",2);
    call_out("leave",15);
	if (query("zhoushi"))
	call_out("anti_perform",5+random(4));
}
//水贼咒师配置
int remove_anti_perform()
{
	message_vision(HIG+"$N看着放晴的天空，目光变得很惊异。\n"+NOR,this_object());
	delete("anti_perform");
	remove_call_out("anti_perform");
	call_out("anti_perform",8+random(6));
	return 1;
}
int anti_perform()
{
	message_vision(BLINK+RED+"$N念出了一些古怪的祭文，瞬时天色昏暗起来。\n"+NOR,this_object());
	set("anti_perform",1);
	remove_call_out("remove_anti_perform");
	call_out("remove_anti_perform",2+random(2));
	return 1;
}
int do_perform()
{
	if (!query("zhoushi"))
	{
		return 0;
	}
	if (!query("anti_perform"))
	{
		return 0;
	}
	if (!userp(this_player()))
	{
		return 0;
	}
	tell_object(this_player(),query("name")+"正在乱你心意，此时强行出招，恐怕不是明智之举。\n");
	return 1;
}
int kill_target()
{
	object target=query("killer"),*team;
	if(objectp(target) &&!is_fighting(target) &&environment(target)==environment(this_object()))
	kill_ob(target);
	if (query("killers_team"))
	{
		team=query("killers_team");
		for (int i=0;i<sizeof(team);i++)
		if (team[i]&&living(this_object())&&userp(team[i])&&environment(team[i])==environment(this_object())&&!is_fighting(team[i]))
		kill_ob(team[i]);	
	}
	remove_call_out("kill_target");
	call_out("kill_target",5+random(5));
	return 1;
}

void leave()
{
    object ob = this_object();
    object me = ob->query("killer");
    if ((!me||environment(me) != environment(ob))&&!query("killers_team"))
    {
		destruct(ob);
	    return ;
    }
    else
    {
        call_out("leave",90);
    }
}

void do_copy(object me)
{
	object ob= this_object();
	mapping skills, hp_status, skill_status;
	string *sname;
	string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	int i, temp,factor,exp,count,tempskill,lianxu,f,extra=0;
	set("gender", random(2)?"男性":"女性");
    temp = 0;
	tempskill = 0;
	if (me->query_temp("pyh/count")>14)
	{
		extra=10;
		ob->set("yzy",1);
	}
	if (me->query_temp("pyh/count")>28)
	{
		extra=15;
		ob->set("antibusy",1);
	}
	if (me->query("pyh/easytask"))
	{
		extra-=15;
	}
	if (me->query("pyh/simpletask"))
	{
		extra-=25;
	}
	if (me->query_temp("pyh/count")<11)
	{
		ob->set("no_pfm",1);
	}
	exp = me->query("combat_exp");
	tempskill = to_int(pow(exp/100,0.333)*10);
	tempskill = to_int(tempskill * ( 95 + extra)/100);//技能也是0.95至1.20倍浮动 Zine
	if (tempskill<300)
	tempskill=300;
	if (query("yanei"))
	tempskill/=4;
	skills = ob->query_skills();
	for (i=0;i<sizeof(skills);i++)
	skills[keys(skills)[i]] = tempskill;
	hp_status = me->query_entire_dbase();
	set("str", hp_status["str"]+random(2));
	set("int", hp_status["int"]+random(2));
	set("con", hp_status["con"]+random(2));
	set("dex", hp_status["dex"]+random(2));
	set("combat_exp",exp/100 * (95 + extra));// exp浮动，0.95至1.20倍玩家经验 Zine
	set("qi", hp_status["max_qi"]);
	set("eff_qi",hp_status["max_qi"]);
	set("max_qi",hp_status["max_qi"]);
	set("max_neili", hp_status["max_neili"]);
	set("neili", hp_status["max_neili"]);
	set("max_jingli", hp_status["max_jingli"]);
	set("jingli", hp_status["jingli"]);
	if (query("jing") < 5000)
	{
		set("eff_jing",5000);
		set("max_jing",5000);
		set("jing",5000);
	}
	if (query("qi")>20000)//为武当长气血的一点点福利 Zine
	{
		set("eff_qi",20000);
		set("max_qi",20000);
		set("qi",20000);
	}
	if (query("lishi"))
	{
		set("chat_chance_combat", 0);
		set("eff_jing",query("max_jing")*3);
		set("max_jing",query("max_jing")*3);
		set("jing",query("max_jing")*3);
		set("eff_qi",query("max_qi")*5);
		set("max_qi",query("max_qi")*5);
		set("qi",query("max_qi")*5);
	}
	if (query("zhoushi"))
	{
		set("chat_chance_combat", 0);
		set("eff_jing",query("max_jing")*2/3);
		set("max_jing",query("max_jing")*2/3);
		set("jing",query("max_jing")*2/3);
		set("eff_qi",query("max_qi")*2/5);
		set("max_qi",query("max_qi")*2/5);
		set("qi",query("max_qi")*2/5);
	}
	if (query("yanei"))
	{
		set("chat_chance_combat", 0);
		set("eff_jing",query("max_jing")/4);
		set("max_jing",query("max_jing")/4);
		set("jing",query("max_jing")/4);
		set("eff_qi",query("max_qi")/4);
		set("max_qi",query("max_qi")/4);
		set("qi",query("max_qi")/4);
		set("combat_exp",query("combat_exp")/4);
	}
	if (!query("lishi")&&!query("zhoushi")&&!query("yanei")&&!query("hua")&&!query("shuizei_leader")&&query("gender")=="女性")
	{
		set("title",color[random(sizeof(color))]+"鄱阳女水贼"+NOR);
		set("long","这是一位鄱阳湖女水贼。\n");
	}
}
//死亡管理
void no_damage_source_leave(object ob)
{
	message_vision(HIR+ob->name()+"长笑一声：嘿嘿，你有帮手，爷不奉陪了。\n"NOR,ob);
	destruct(ob);
	return;
}
int yanei_death()
{
	int i;
	object *all=all_inventory(environment(this_object())),*remain_robbers=({});
	for (i=0;i<sizeof(all);i++)
	{
		if (all[i]->query("isshuizei")&&!userp(all[i])&&all[i]!=this_object())
			remain_robbers+=({all[i]});
	}
	if (sizeof(remain_robbers)>0)
	{
		for (i=0;i<sizeof(remain_robbers);i++)
		{
			if (!remain_robbers[i]->query_temp("yanei_death_buff"))
			{
				remain_robbers[i]->set_temp("yanei_death_buff",1);
				remain_robbers[i]->add_temp("attack",10);
				remain_robbers[i]->add_temp("damage",10);
				tell_room(environment(this_object()),HIW+remain_robbers[i]->name()+"看到"+this_object()->name()+HIW+"被杀，害怕被"+MAG+"水贼大头目"+HIW+"责怪，只得奋起精神，继续投入战团。\n"+NOR);
			}
		}
	}
}
int reward(object killer)
{
	int exp,pot,bl,sf,wx,gg,max=0;
	float percent;
	killer->add_temp("pyh/count",1);
	if (query("shuizei_leader"))
	killer->add_temp("pyh/count",2);
	if (query("hua")||query("lishi")||query("zhoushi"))
	{
		bl=killer->query("str");
		sf=killer->query("dex");
		wx=killer->query("int");
		gg=killer->query("con");
		max=max(({bl,sf,wx,gg}));
		max=max+random(10);
		max=max*max;
		exp=REWARD_D->add_exp(killer,max,"piaoliu");
		pot=REWARD_D->add_pot(killer,max);
		killer->add("exp/pyh",exp);
		killer->add("pot/pyh",pot);
		tell_object(killer,HIG+"打败"+query("title")+HIG+"，你额外获得"+chinese_number(exp)+"点经验、"+chinese_number(pot)+"点潜能。\n"+NOR);
		killer->add_temp("pyh/count",1);
		if (query("hua"))
		GEM_D->drop(this_object(),killer);
	}
	if (query("yanei"))
	{
		GEM_D->drop(this_object(),killer);
		yanei_death();
	}
	message_vision(HIG"$N"+HIG+"终于打退了$n的攻击。\n"NOR,killer,this_object());
	environment(this_object())->add("pyh/total_mobs",1);
	killer->add_temp("pyh/mobs_kill",1);
	percent=to_float(killer->query_temp("pyh/mobs_kill"))/to_float(environment(this_object())->query("pyh/total_mobs"))*100.0;
	tell_object(killer,"这次寻宝任务中，你总共击退了"+chinese_number(killer->query_temp("pyh/mobs_kill"))+"名水贼，任务贡献度为"+percent+"%。\n");
	return 1;
}
void die()
{
    object killer,pl;
    object *team;
    string msg;
	float extra_count;
    if(!killer=get_damage_origin_object())//无伤害来源
    {
        return no_damage_source_leave(this_object());
    }
	if (killer!=query("killer"))
	{
		if (killer->query("isshuizei"))
		{
			if (killer->query("killer")&&userp(killer->query("killer"))&&environment(killer->query("killer"))==environment(this_object()))
			pl=killer->query("killer");
			else if (query("killers_team")[0]&&userp(query("killers_team")[0])&&environment(query("killers_team")[0])==environment(this_object()))
			pl=query("killers_team")[0];
			if (userp(pl))
			reward(pl);
			else
			return no_damage_source_leave(this_object());
		}
		else if (!query("killers_team"))
		{
			return no_damage_source_leave(this_object());
		}
		else if (member_array(killer,query("killers_team"))==-1)
		{
			return no_damage_source_leave(this_object());
		}
		else
		{
			extra_count=to_float(query("combat_exp"))/to_float(killer->query("combat_exp"));
			if (extra_count>1.0)
			extra_count=1.0;
			killer->add_temp("pyh/extra_count",extra_count);
			reward(killer);
		}
	}
	else
	{
		reward(killer);
	}
	
	if (wizardp(killer))
	{
		tell_object(killer,"鄱阳湖npc测试信息：\n");
		tell_object(killer,"count:"+killer->query_temp("pyh/count")+"extra_count:"+killer->query_temp("pyh/extra_count")+"\n");
		if (team=killer->query("team"))
		{
			for (int i=0;i<sizeof(team);i++)
			{
				msg+=team[i]->query("id")+"----"+"count:"+team[i]->query_temp("pyh/count")+"extra_count:"+team[i]->query_temp("pyh/extra_count")+"\n";
			}
			tell_object(killer,"team信息:\n"+msg);
		}
	}
    destruct(this_object());
	return ;
}

void unconcious() 
{
    object ob=this_object();
    object killer=ob->get_damage_origin_object();
    int damage,index=5,index2=4;
	if (query("shuizei_leader"))
	{
		index2=3;
		index=8;
	}
	if (query("lishi"))
	index=12;
	damage=(int)ob->query("max_qi")/index;
    if(ob->query("yzy"))
	{
		//拒绝一招晕
		if(query("lishi")||(random(index2) == 1 && ob->query("qi") > (ob->query("max_qi")/100)*50 && ob->query("eff_qi") > (ob->query("max_qi")/100)*50 && ob->query("jing") > (ob->query("max_jing")/100)*50 && ob->query("eff_jing") > (ob->query("max_jing")/100)*50))
		{
            ob->receive_damage("qi", damage, killer);
        	ob->receive_wound("qi", damage/2, killer);
			return;
		}
        else
        {
            call_out("die",1);
        }
	}
	else
    {
        call_out("die",1);
    }
}

int do_none()
{
    return 1;
}

varargs int receive_damage(string type, int damage, mixed who)
{
    object killer;
	int index=12, ret=0;

    ret=::receive_damage(type,damage,who);
    killer=get_damage_origin_object();

	if(query("shuizei_leader")) index=10;
	if(query("antibusy") && random(index)==0 && objectp(killer) && userp(killer))
	{
		tell_object(killer, query("name")+"被伤痛一激,爆发出不可思议的力量，竟然摆脱了你的纠缠，但同时也伤的更重了。\n");				
		ret+=::receive_damage(type,damage,who);
		start_busy(1);
	}
	return ret;
}
