// File		: target.c
// Created By	: iszt@pkuxkx, 2007-03-28

#include <ansi.h>

inherit FAMILY_NPC;
object* allob;
int fscount;
int job_level;
int reward,reward_re,reward_qn,reward_exp,reward_skills;
varargs void wield_weapon(string weapon);
void die();


void create()
{
	set_name("番邦武士", ({ "fanbang wushi", "wushi" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long", "这是一个穿着怪异的番邦武士，看上去杀气腾腾，一副致人死地的模样。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("rank_info/respect", "大哥");
	
    set("food",500);
    set("water",500);
	set("chat_chance", 25);
	set("uni_target", 1);
	set("wanansi", 1);
    set("gem_level", ({0, 8334}));
	setup();
    carry_object("/clone/armor/pifeng")->wear();
	
   if(random(5)==0)
	    add_money("gold", random(6));
   if(random(4)==1)
	    add_money("silver", 20+random(8)*10);
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

	if(!objectp(me))
		return 0;

	job_level = query("job_level");
	
	set("level",to_int(pow(me->query("combat_exp")/400, 0.333)));
	level = pow(me->query("combat_exp")/100, 0.333) * 9;
	level += level/14*job_level;
     
	if(level < 200)
	level = 200;
	set("combat_exp", me->query("combat_exp")/10*(random(job_level)+8));
	family_skill(this_object(), "random", level, 1);
    set("chat_chance_combat", 150);
	set("max_qi", level * 10);
	set("eff_qi", level * 10);
	set("qi", level * 10);
	set("max_jing", level * 10);
	set("eff_jing", level * 10);
	set("jing", level * 10);
	set("max_jingli", level * 10);
	set("jingli", level * 10);
	set("max_neili", level * 15);
	set("neili", level * 30);

	set("uni_target", me);
	wield_weapon();
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
	string* sname;
	string skill;
	if(!objectp(me)) return ::die();
	    
	respect = RANK_D->query_respect(me);
	skills = me->query_skills();
	job_lvl=query("job_level");
	room = environment(me);
	//GEM_D->drop(ob,me);
	allob = all_inventory(environment(me));
	for(int i =0;i<sizeof(allob);i++)
		{            
			if (allob[i]->query("id")=="fanbang wushi" && allob[i]->query("uni_target") == me)
			{
				fscount++;
			}
		}
	if (fscount>1)
	{
		::die();
		return;
	}

	reward = pow(2,job_lvl)*(200+random(200));  

	if (me->query("special_skill/lucky") && me->query("age")>=18)
	{
		reward = reward + reward/10; //有lucky的玩家奖励多10%
	}
     
	reward_re=reward;   //声望奖励
	me->set_temp("wananta/reward_re",reward_re);
	reward_qn = (reward_re + reward/5)* 5;  //潜能奖励
	me->set_temp("wananta/reward_qn",reward_qn);
	reward_exp = reward_re*8 + random(reward)/1000*100;  //经验奖励
	me->set_temp("wananta/reward_exp",reward_exp);
	
	if (job_lvl>3)
	{
		sname = keys(skills);
		count = random(sizeof(sname));
		skill = sname[count];
		if(SKILL_D(skill)->valid_enable("force") && !random(3))
		skill = "force";
		me->set_temp("wanansi/reward_skill",skill);
		me->set_temp("wanansi/reward_count",1+random(job_lvl));
	}
	
	if(job_lvl == 7)
	{
	    write("恭喜你！你已经通过了万安塔的全部考验！\n");
	}
	else
	{
	    write("继续前进吧！\n");
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
	
	write("你想停下来，可是"+this_object()->query("name")+"步步紧逼，直逼得你手忙脚乱！\n");
	me->start_busy(1+random(4));
	return 1;
}

int visible(object ob)
{
    if(query("uni_target") != ob) return 0;
    return 1;
}