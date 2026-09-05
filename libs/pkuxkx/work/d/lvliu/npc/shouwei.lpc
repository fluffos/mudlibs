
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
	set_name("守卫武士", ({ "shouwei wushi", "shouwei", "wushi" }) );
	set("gender", "男性" );
	set("age", 22+random(10));
	set("long", "这是一个全副武装的守卫武士，看上去杀气腾腾，一副致人死地的模样。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	
    set("food",500);
    set("water",500);
	set("chat_chance", 25);
	set("uni_target", 1);
	set("lvliu_jiuzhou_shouwei", 1);

	setup();
    carry_object("/clone/armor/jinzhuang")->wear();
    carry_object("/clone/armor/tiejia")->wear();
	
	call_out("kill_target",10);
}

void init()
{
	add_action("do_halt", "halt");
}

int do_copy(object me, int rate)
{
	int level;
	int succ_times = 0;
	int addition = 1;
	int life = 0;

	if(!objectp(me))
		return 0;

	succ_times = me->query("lvliu_jiuzhou/succ_times");
	job_level = query("job_level");
	
	set("level",to_int(pow(me->query("combat_exp")/400, 0.333)));
	level = pow(me->query("combat_exp")/100, 0.333) * 9;
	level += level/14*job_level;
     
	if (level < 200) level = 200;
	if (rate<1) rate=1;
	
	if(succ_times/100 > 1 && job_level == 7)
	{
        addition = succ_times/150;
	    if(addition > 3)
	    {
	        addition = 3;		    
	    }	    
	    set("combat_exp", me->query("combat_exp")/10 * rate * (random(job_level)+ 7 +addition) );	    
	    family_skill(this_object(), "random", level*(addition), 1);
	}
	else
	{
		set("combat_exp", me->query("combat_exp")/10 * rate * (random(job_level)+7));
		family_skill(this_object(), "random", level, 1);
	}
	
	if (job_level<6)
	{
		templvl=10;
	}
	if (job_level==6)
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
	if (job_level>6)
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

	life = rate * rate * level * templvl;
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

	wield_weapon();
}

void unconcious()
{
	if(query("job_level") >= 8)
	{
		//拒绝一招晕
		if(random(2) == 1 && query("qi") > (query("max_qi")/100)*50 && query("eff_qi") > (query("max_qi")/100)*50 && query("jing") > (query("max_jing")/100)*50 && query("eff_jing") > (query("max_jing")/100)*50)
		{
			return;
		}
	}
	die();
}

void die()
{
	object me = query("uni_target/1");
	object mate = query("uni_target/2");
	object ob = this_object();
	object room;
	int job_lvl,count;
	string mark, msg;

	room = environment(ob);
	if (objectp(me) && environment(me) != room) {
		delete("uni_target/1");
		me = 0;
	}
	if (objectp(mate) && environment(mate) != room) {
		delete("uni_target/2");
		mate = 0;
	}
	
	if(!objectp(me) && !objectp(mate))
		return ::die();
	
	allob = all_inventory(room);
	for(int i =0;i<sizeof(allob);i++)
		{    
			if(allob[i]->query("lvliu_jiuzhou_shouwei") && !userp(allob[i]))
			{
				fscount++;
				if (objectp(me)) allob[i]->kill_ob(me);
				if (objectp(mate)) allob[i]->kill_ob(mate);
			}
		}
	if (fscount>1)
	{
		::die();
		fscount=0;
		return;
	}

	job_lvl = query("job_level");
	mark = sprintf("lvliu_jiuzhou/%d", job_lvl);
	
	if (job_lvl<=1)
	{
		reward = 300+random(1000);
		reward = reward * SPEWEEK_D->query_lvliu_bonus()/100;
		reward_re = reward;   //声望奖励
		reward_qn = reward * 2;  //潜能奖励
		reward_exp = reward * 3 + random(reward2)/10;  //经验奖励
		reward2 = 500+random(1000) + reward;  
		reward_re2 = reward2;   //声望奖励
		reward_qn2 = reward2 *2 ;  //潜能奖励
		reward_exp2 = reward2 * 3 + random(reward2)/10;  //经验奖励
		if (objectp(me) && me->query_temp(mark))
		{
			me->set_temp("lvliu_jiuzhou/reward_re",reward_re);
			me->set_temp("lvliu_jiuzhou/reward_qn",reward_qn);
			me->set_temp("lvliu_jiuzhou/reward_exp",reward_exp);
			me->set_temp("lvliu_jiuzhou/reward_re2",reward_re2);
			me->set_temp("lvliu_jiuzhou/reward_qn2",reward_qn2);
			me->set_temp("lvliu_jiuzhou/reward_exp2",reward_exp2);
		}
		if (objectp(mate) && mate->query_temp(mark))
		{
			mate->set_temp("lvliu_jiuzhou/reward_re",reward_re);
			mate->set_temp("lvliu_jiuzhou/reward_qn",reward_qn);
			mate->set_temp("lvliu_jiuzhou/reward_exp",reward_exp);
			mate->set_temp("lvliu_jiuzhou/reward_re2",reward_re2);
			mate->set_temp("lvliu_jiuzhou/reward_qn2",reward_qn2);
			mate->set_temp("lvliu_jiuzhou/reward_exp2",reward_exp2);
		}
	}
	else if (job_lvl>=2 && job_lvl<=8)
	{
		if (objectp(me) && me->query_temp(mark))
		{
			me->set_temp("lvliu_jiuzhou/reward_re", me->query_temp("lvliu_jiuzhou/reward_re2"));
			me->set_temp("lvliu_jiuzhou/reward_qn", me->query_temp("lvliu_jiuzhou/reward_qn2"));
			me->set_temp("lvliu_jiuzhou/reward_exp", me->query_temp("lvliu_jiuzhou/reward_exp2"));
		}
		if (objectp(mate) && mate->query_temp(mark))
		{
			mate->set_temp("lvliu_jiuzhou/reward_re", mate->query_temp("lvliu_jiuzhou/reward_re2"));
			mate->set_temp("lvliu_jiuzhou/reward_qn", mate->query_temp("lvliu_jiuzhou/reward_qn2"));
			mate->set_temp("lvliu_jiuzhou/reward_exp", mate->query_temp("lvliu_jiuzhou/reward_exp2"));
		}

		if (job_lvl<=3)
		{
			reward = 300+random(800); 
		}
		else if (job_lvl==4)
		{
			reward = 1000+random(1000);
		}
		else if (job_lvl==5)
		{
			reward = 8000+random(1000);
		}
		else if (job_lvl==6)
		{
			reward = 10000+random(2000);
		}
		else if (job_lvl==7)
		{
			reward = 20000+random(3000);
		}	
		else if (job_lvl==8)
		{
			reward = 40000+random(5000);
		}
		reward = reward * SPEWEEK_D->query_lvliu_bonus()/100;             
		
		if (objectp(me) && me->query_temp(mark))
		{
			reward_re2 = me->query_temp("lvliu_jiuzhou/reward_re2")+reward;   //声望奖励
			reward_qn2 = me->query_temp("lvliu_jiuzhou/reward_qn2")+reward*2 ;  //潜能奖励
			reward_exp2 = reward *3 + me->query_temp("lvliu_jiuzhou/reward_exp2");  //经验奖励
			me->set_temp("lvliu_jiuzhou/reward_re2",reward_re2);
			me->set_temp("lvliu_jiuzhou/reward_qn2",reward_qn2);
			me->set_temp("lvliu_jiuzhou/reward_exp2",reward_exp2);
		}
		if (objectp(mate) && mate->query_temp(mark))
		{
			reward_re2 = mate->query_temp("lvliu_jiuzhou/reward_re2")+reward;   //声望奖励
			reward_qn2 = mate->query_temp("lvliu_jiuzhou/reward_qn2")+reward*2 ;  //潜能奖励
			reward_exp2 = reward *3 + mate->query_temp("lvliu_jiuzhou/reward_exp2");  //经验奖励
			mate->set_temp("lvliu_jiuzhou/reward_re2",reward_re2);
			mate->set_temp("lvliu_jiuzhou/reward_qn2",reward_qn2);
			mate->set_temp("lvliu_jiuzhou/reward_exp2",reward_exp2);
		}	
	}
	
	if(job_lvl == 9)
	{
		if (objectp(me) && me->query_temp(mark))
		{
			me->set_temp("lvliu_jiuzhou/reward_re",me->query_temp("lvliu_jiuzhou/reward_re2"));
			me->set_temp("lvliu_jiuzhou/reward_qn",me->query_temp("lvliu_jiuzhou/reward_qn2"));
			me->set_temp("lvliu_jiuzhou/reward_exp",me->query_temp("lvliu_jiuzhou/reward_exp2"));
			me->add("lvliu_jiuzhou/succ_times",1);
			tell_object(me,HIW"\n看着剩下的守卫武士全都抱头鼠窜，四散逃离，你不禁长舒了一口气。\n"NOR);	    
			tell_object(me,HIY"历经血战，你第"+chinese_number(me->query("lvliu_jiuzhou/succ_times"))+"次成功地闯过了九重画廊！\n"NOR);
		}
		if (objectp(mate) && mate->query_temp(mark))
		{
			mate->set_temp("lvliu_jiuzhou/reward_re",mate->query_temp("lvliu_jiuzhou/reward_re2"));
			mate->set_temp("lvliu_jiuzhou/reward_qn",mate->query_temp("lvliu_jiuzhou/reward_qn2"));
			mate->set_temp("lvliu_jiuzhou/reward_exp",mate->query_temp("lvliu_jiuzhou/reward_exp2"));
			mate->add("lvliu_jiuzhou/succ_times",1);
			tell_object(mate,HIW"\n看着剩下的守卫武士全都抱头鼠窜，四散逃离，你不禁长舒了一口气。\n"NOR);	    
			tell_object(mate,HIY"看起来，你已第"+chinese_number(mate->query("lvliu_jiuzhou/succ_times"))+"次成功地闯过了九重画廊！\n"NOR);
		}
	}
	else
	{
		msg = HIG"\n最后一名守卫武士惨呼一声，叫道：「你……你给我等着……」忙不迭地跳进地道逃走了。\n"
			+ HIY"看样子对方去招呼帮手了！\n"
			+ HIC"你看了一眼武士消失的地方，有块地砖(brick)能够翻动，或许从那里可以中途离开！\n"
			+ HIW"如果你现在就离开，可以获得：\n" ;
		if (objectp(me) && me->query_temp(mark))
		{
			tell_object(me, msg);		
			tell_object(me,"\t"+chinese_number(REWARD_D->check_exp(me->query_temp("lvliu_jiuzhou/reward_exp")))+"点经验；\n");
			tell_object(me,"\t"+chinese_number(REWARD_D->check_pot(me->query_temp("lvliu_jiuzhou/reward_qn")))+"点潜能；\n");
			tell_object(me,"\t"+chinese_number(REWARD_D->check_rep(me->query_temp("lvliu_jiuzhou/reward_re")))+"点江湖声望。\n\n");
			tell_object(me,HIW"如果你继续往前闯，将面临更难缠的对手，但收获也将更加丰厚：\n");
			tell_object(me,"\t"+chinese_number(REWARD_D->check_exp(reward_exp2))+"点经验；\n" );	
			tell_object(me,"\t"+chinese_number(REWARD_D->check_pot(reward_qn2))+"点潜能；\n");
			tell_object(me,"\t"+chinese_number(REWARD_D->check_rep(reward_re2))+"点江湖声望。\n\n" NOR);
		}		
		if (objectp(mate) && mate->query_temp(mark))
		{
			tell_object(mate, msg);		
			tell_object(mate,"\t"+chinese_number(REWARD_D->check_exp(mate->query_temp("lvliu_jiuzhou/reward_exp")))+"点经验；\n");
			tell_object(mate,"\t"+chinese_number(REWARD_D->check_pot(mate->query_temp("lvliu_jiuzhou/reward_qn")))+"点潜能；\n");
			tell_object(mate,"\t"+chinese_number(REWARD_D->check_rep(mate->query_temp("lvliu_jiuzhou/reward_re")))+"点江湖声望。\n\n");
			tell_object(mate,HIW"如果你继续往前闯，将面临更难缠的对手，但收获也将更加丰厚：\n");
			tell_object(mate,"\t"+chinese_number(REWARD_D->check_exp(reward_exp2))+"点经验；\n" );	
			tell_object(mate,"\t"+chinese_number(REWARD_D->check_pot(reward_qn2))+"点潜能；\n");
			tell_object(mate,"\t"+chinese_number(REWARD_D->check_rep(reward_re2))+"点江湖声望。\n\n" NOR);
		}		
	}
	destruct(ob);
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
	tell_object(me, HIR"生死之战，岂容你逃避？！\n"NOR);
	me->add_busy(1+random(4));
	return 1;
}

int kill_target()
{
	object tar1, tar2, ob;
	ob = this_object();
	tar1 = query("uni_target/1");
	if(objectp(tar1))
	{
		if (environment(tar1)==environment(ob))
			ob->kill_ob(tar1);
		else
			tar1 = 0;
	}
	tar2 = query("uni_target/2");
	if(objectp(tar2))
	{
		if (environment(tar2)==environment(ob))
			ob->kill_ob(tar2);
		else
			tar2 = 0;
	}
	if (!objectp(tar1) && !objectp(tar2))
		destruct(this_object());
	remove_call_out("kill_target");
	call_out("kill_target", 10);
	return 1;
}

varargs int receive_damage(string type, int damage, mixed who)
{
    object ob = this_object();
	int ret=0;
    ret=::receive_damage(type, damage, who);

	if(ob->query("job_level") >= 8 && ob->query_busy()>=10)
	{
		if(!random(3))
		{
			message_vision(HIR"$N强运真气冲击经脉，怒吼一声，以自身经脉受创为代价摆脱了纠缠！\n"NOR, ob);
			ret+=::receive_damage(type, damage/10, who);
			ob->start_busy(0);
		}
	}
	return ret;
}
