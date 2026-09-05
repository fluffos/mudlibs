
#include <ansi.h>

inherit FAMILY_NPC;
object* allob;
int fscount;
int job_level,templvl;
int reward,reward_re,reward_qn,reward_exp,reward_skill;
int reward2,reward_re2,reward_qn2,reward_exp2,reward_skill2;
varargs void wield_weapon(string weapon);
void die();

int kill_target();

void create()
{
	set_name("番邦武士", ({ "fanbang wushi", "wushi" }) );
	set("gender", "男性" );
	set("age", 22+random(10));
	set("long", "这是一个穿着怪异的番邦武士，看上去杀气腾腾，一副致人死地的模样。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	
    set("food",500);
    set("water",500);
	set("chat_chance", 25);
	set("uni_target", 1);
	set("wanansi", 1);

	setup();
    carry_object("/clone/armor/bianfuxuejia")->wear();
	
	call_out("kill_target",10);
}

void delete_init_num(object me)
{
	me->delete("init_num");
	return;
}

void init()
{
	add_action("do_perform", "perform");
	add_action("do_halt", "halt");
}

int do_copy(object me)
{
	int level;
	int succ_times = 0;
	int addition = 1;
	int life = 0;

	if(!objectp(me))
		return 0;

	succ_times = me->query("wananta/succ_times");

	job_level = query("job_level");
	
	set("level",to_int(pow(me->query("combat_exp")/400, 0.333)));
	level = pow(me->query("combat_exp")/100, 0.333) * 9;
	level += level/14*job_level;
     
	if(level < 200)
		level = 200;
	if(succ_times/100 > 1 && job_level == 7)
	{
        addition = succ_times/150;
	    if(addition > 3)
	    {
	        addition = 3;		    
	    }	    
	    set("combat_exp", (me->query("combat_exp")/10) * (random(job_level)+ 7 +addition) );	    
	    family_skill(this_object(), "random", level*(addition), 1);
	}
	else
	{
		set("combat_exp", me->query("combat_exp")/10*(random(job_level)+7));
		family_skill(this_object(), "random", level, 1);
	}
	
	if (job_level<5)
	{
		templvl=10;
	}
	if (job_level==5)
	{
		templvl=random(40);
		if (templvl<10)
		{
			templvl=10;
		}
		if (templvl>30)
		{
			templvl=30;
		}
	}
	if (job_level>5)
	{
		templvl=random(40);
		if (templvl<25)
		{
			templvl=30;
		}
		if (templvl>35)
		{
			templvl=45;
		}
	}
  set("chat_chance_combat", 150);
	//life = (succ_times-20);
	//if(life <= 0) life = 1;
	//if(life > 25) life /= 25;
	//else life = 1;

	//if(job_level < 7) life = 1;
	
	life = level * templvl;

	set("max_qi", life);
	set("eff_qi", life);
	set("qi", life);
	set("max_jing", life);
	set("eff_jing", life);
	set("jing", life);
	set("max_jingli", life);
	set("jingli", life);
	set("max_neili", life*2/3);
	set("neili", life*2/3);

	set("uni_target", me);
	wield_weapon();
}

void unconcious()
{
	if(query("job_level") >= 6)
	{
		//拒绝一招晕
		if(random(2) == 1 && query("qi") > (query("max_qi")/100)*50 && query("eff_qi") > (query("max_qi")/100)*50 && query("jing") > (query("max_jing")/100)*50 && query("eff_jing") > (query("max_jing")/100)*50)
		{
			return;
		}
	}
	::unconcious();
}

int filter_skills(string skill,object me)
{
    if(me->query_skill(skill,1)<=10) return 0;
    if(skill == "tianmo-jieti") return 0;
    if(skill == "business") return 0;
                		
	return 1;
}
void die()
{
	object me = query("uni_target");
	object ob = this_object();
	object equip;
	object room;
	int job_lvl,count;
	string respect; 
	mapping skills;
	string* filter_skills; 
	string* sname;
	string skill;
	int succ_times = 0;

	if(!objectp(me)) return ::die();
	    
	respect = RANK_D->query_respect(me);
	skills = me->query_skills();
	filter_skills = filter_array(keys(skills),"filter_skills",this_object(),me);
	
	job_lvl=query("job_level");
	
	room = environment(me);
	//GEM_D->drop(ob,me);
	allob = all_inventory(environment(me));
	for(int i =0;i<sizeof(allob);i++)
		{    
			if(allob[i]->query("id")=="fanbang wushi" && allob[i]->query("uni_target") == me)
			{
				fscount++;
				allob[i]->kill_ob(me);
			}
		}
	if (fscount>1)
	{
		::die();
		fscount=0;   //武士计数器清0
		return;
	}

	


	if (job_lvl==1)
	{
		reward = 300+random(1000);  
	
		if (me->query("special_skill/lucky") && me->query("age")>=18)
		{
			reward = reward + reward/10; //有lucky的玩家奖励多10%
		}
		
    reward = reward * SPEWEEK_D->query_wat_bonus()/100;        
		reward_re=reward;   //声望奖励
		me->set_temp("wanansi/reward_re",reward_re);
		reward_qn = reward * 2;  //潜能奖励
		me->set_temp("wanansi/reward_qn",reward_qn);
		reward_exp = reward * 3 + random(reward2)/10;  //经验奖励
		me->set_temp("wanansi/reward_exp",reward_exp);

		reward2 = 500+random(1000) + reward;  
	
		if (me->query("special_skill/lucky") && me->query("age")>=18)
		{
			reward2 = reward2+ reward2/10; //有lucky的玩家奖励多10%
		}
     
		reward_re2 = reward2;   //声望奖励
		me->set_temp("wanansi/reward_re2",reward_re2);
		reward_qn2 = reward2 *2 ;  //潜能奖励
		me->set_temp("wanansi/reward_qn2",reward_qn2);
		reward_exp2 = reward2 * 3 + random(reward2)/10;  //经验奖励
		me->set_temp("wanansi/reward_exp2",reward_exp2);

	}

	if (job_lvl>1 && job_lvl<7)
	{

		me->set_temp("wanansi/reward_re",me->query_temp("wanansi/reward_re2"));
		me->set_temp("wanansi/reward_qn",me->query_temp("wanansi/reward_qn2"));
		me->set_temp("wanansi/reward_exp",me->query_temp("wanansi/reward_exp2"));


		reward = 300+random(1000); 
		if (job_lvl>=3 && job_lvl<=4)
		{
			reward = 1000+random(1000);
		}

		if (job_lvl==5)
		{
			reward =25000+random(3000);
		}
	
		if (job_lvl==6)
		{
			reward =50000+random(5000);
		}

		if (me->query("special_skill/lucky") && me->query("age")>=18)
		{
			reward2 = reward2+ reward2/10; //有lucky的玩家奖励多10%
		}
		
    reward = reward * SPEWEEK_D->query_wat_bonus()/100;
             
		reward_re2 =me->query_temp("wanansi/reward_re2")+reward;   //声望奖励
		me->set_temp("wanansi/reward_re2",reward_re2);
		reward_qn2 = me->query_temp("wanansi/reward_qn2")+reward*2 ;  //潜能奖励
		me->set_temp("wanansi/reward_qn2",reward_qn2);
		reward_exp2 = reward *3 + me->query_temp("wanansi/reward_exp2");  //经验奖励
		me->set_temp("wanansi/reward_exp2",reward_exp2);
	}

	
	if (job_lvl==2)
	{
		if (!me->query_temp("wanansi/reward_skill"))
		{			
			if(sizeof(filter_skills) == 0) skill = "force";
			else
			{
				count = random(sizeof(filter_skills));			
				skill = filter_skills[count];
			}
			if(SKILL_D(skill)->valid_enable("force") && !random(3))
			skill = "force";
			me->set_temp("wanansi/reward_skill",skill);
		}
		reward_skill=1+random(1);
		me->set_temp("wanansi/reward_count2",reward_skill);
	}

	if (job_lvl>3 && job_lvl<7)
	{
		me->set_temp("wanansi/reward_count",me->query_temp("wanansi/reward_count2"));
		reward_skill2=me->query_temp("wanansi/reward_count2")+1+random(1);
		me->set_temp("wanansi/reward_count2",reward_skill2);
	}
	
	if(job_lvl == 7)
	{
		succ_times = me->query("wananta/succ_times");
		succ_times /= 100;
		//if(succ_times <= 0) succ_times = 1;
        //if(succ_times > 3) 
		succ_times = 1;		    

		me->set_temp("wanansi/reward_re",succ_times*me->query_temp("wanansi/reward_re2"));
		me->set_temp("wanansi/reward_qn",succ_times*me->query_temp("wanansi/reward_qn2"));
		me->set_temp("wanansi/reward_exp",succ_times*me->query_temp("wanansi/reward_exp2"));
		me->set_temp("wanansi/reward_count",succ_times*me->query_temp("wanansi/reward_count2"));

		if(me->query_temp("wanansi/reward_count") > 3) 
			me->set_temp("wanansi/reward_count",3);

    me->add("wananta/succ_times",1);
        
    tell_object(me,HIB"暗处的番邦武士对你抱拳道:恭喜这位英雄！你已经通过了万安塔的全部考验！\n"NOR);	    
    tell_object(me,HIY"你已经成功的闯过万安塔七层"+chinese_number(me->query("wananta/succ_times"))+"次\n"NOR);
	}
	else
	{
	    tell_object(me,HIB"暗处的番邦武士对你一抱拳，道“阁下果然武功不凡！”\n"NOR);
		
		tell_object(me,HIW"如果你现在离开，可获厚礼：\n");
		tell_object(me,"\t"+chinese_number(REWARD_D->check_rep(me->query_temp("wanansi/reward_re")))+"点江湖声望。\n");
		tell_object(me,"\t"+chinese_number(REWARD_D->check_pot(me->query_temp("wanansi/reward_qn")))+"点潜能；\n");
		tell_object(me,"\t"+chinese_number(REWARD_D->check_exp(me->query_temp("wanansi/reward_exp")))+"点经验.\n");

		tell_object(me,"\n"NOR);

		tell_object(me,HIW"如果你继续上楼闯关，可获厚礼：\n");
		tell_object(me,"\t"+chinese_number(REWARD_D->check_rep(reward_re2))+"点江湖声望。\n");
		tell_object(me,"\t"+chinese_number(REWARD_D->check_pot(reward_qn2))+"点潜能；\n");
		tell_object(me,"\t"+chinese_number(REWARD_D->check_exp(reward_exp2))+"点经验.\n");

		if (job_lvl>5)
		{
			tell_object(me,"\t"+"同时有几率获得"+chinese_number(REWARD_D->check_skill(me->query_temp("wanansi/reward_count2")))+"级武功");
			
		}
		tell_object(me,"\n"NOR);

		
		
	}
	allob = all_inventory(environment(me));
	for(int i =0;i<sizeof(allob);i++)
		{    
			if(!allob[i]->is_character() && !allob[i]->query_temp("seeme"))
			{
				destruct(allob[i]);

			}
		}
	
	::die();	
}


varargs void wield_weapon(string weapon)
{
	if(!weapon && query("use_weapon1"))
		wield_weapon(query("use_weapon1"));
	if(!weapon && query("use_weapon2"))
		wield_weapon(query("use_weapon2"));
	if(!weapon)
		return;
	switch(weapon)
	{
	case "sword":
		carry_object("/clone/weapon/changjian")->wield();
		break;
	case "blade":
		carry_object("/clone/weapon/gangdao")->wield();
		break;
	case "staff":
		carry_object("/clone/weapon/gangzhang")->wield();
		break;
	case "whip":
		carry_object("/clone/weapon/changbian")->wield();
		break;
	case "zhen":
		set("gender", "无性");
		carry_object("/d/city/obj/flower_shoe")->wear();
		carry_object("/d/city/obj/pink_cloth")->wear();
		carry_object("/d/city/obj/goldring")->wear();
		carry_object("/d/city/obj/necklace")->wear();
		carry_object("/d/quanzhou/obj/xiuhua")->wield();
		carry_object("/d/riyuejiao/obj/xiuhuajia");
		break;
	case "dagger":
                carry_object("/clone/weapon/bishou")->wield();
		break;
        case "xiao":
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
	case "hammer":
		carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
		break;
	default:
	}
	return;
}

int do_halt()
{
	object me = this_player();
	if(!me->is_fighting())
	{
		return 0;
	}	
	
	tell_object(HIR"生死之战，岂容你逃避？！\n"NOR);
	me->start_busy(1+random(4));
	return 1;
}

int visible(object ob)
{
	if(ob->query("uni_target") && query("uni_target") == ob->query("uni_target")) return 1;
    if(query("uni_target") != ob) return 0;
    return 1;
}

int kill_target()
{
	object target = query("uni_target");
	if(objectp(target))
	{
   		command("kill "+target->mask_id());
	}
	remove_call_out("kill_target");
	call_out("kill_target",5+random(5));
	return 1;
}

varargs int receive_damage(string type, int damage, mixed who)
{
    int ret=0;
    object killer;

    ret=::receive_damage(type, damage, who);
    killer=get_damage_origin_object();

	if(query("job_level") >= 6)
	{
		if(random(12) == 0)
		{
			if(objectp(killer))
			{
				tell_object(killer, query("name")+"被伤痛一激,爆发出不可思议的力量，竟然摆脱了你的纠缠，但同时也伤的更重了。\n");				
			}
			ret+=::receive_damage(type,damage,who);
			start_busy(0);
		}
	}
	return ret;
}
