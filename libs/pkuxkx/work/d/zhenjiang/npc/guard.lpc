// By Zine
               
#include <ansi.h>

inherit FAMILY_NPC;

varargs void wield_weapon(string weapon);
void die();
void create()
{
	int i=random(2);
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title",HIR"山贼小头目"NOR);
	set("long","他是一名山贼小头目，武功高强，不太好惹。\n");
	set("is_BANDIT",1);
	set("gender", "男性");
	set("age", 30+random(20));
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 1000);
	set("qi", 1000);
	set("neili", 900);
	set("max_neili", 900);
	set("jiali", 50);
	set("combat_exp", 650000);
	set("random_npc",1);
	setup();
	carry_object("/clone/armor/tiejia")->wear();
	

}
void attempt_kill(object me)
{
	command("say 无知"+RANK_D->query_rude(me)+"，你的死期就是今日！");
	kill_ob(me);
}
int copy(object me,object user,string family,int room_id)
{
	int skill,qi,jing,jingli,neili,exp=me->query("combat_exp")*2/3;
	if (query("Leader"))
	{
		exp*=2;
		set("chat_chance_combat", 80);
	}
	else
	{
	if (room_id>9)
	{
		exp=exp*5/4;
		set("chat_chance_combat", 50);
	}
	else
		{
		set("chat_chance_combat", 1+random(30));
		}
	}
	skill = to_int(pow(exp/100,0.333)*10);
	qi=me->query("max_qi")*2/3;
	jing=me->query("max_jing")*2/3;
	neili=me->query("max_neili")*2/3;
	jingli=me->query("max_jingli")*2/3;
	set("combat_exp",exp);
	set("qi", qi);
	set("eff_qi",qi);
	set("max_qi",qi);
	set("jing", jing);
	set("eff_jing",jing);
	set("max_jing",jing);
	set("max_neili", neili);
	set("neili", neili);
	set("max_jingli", jingli);
	set("jingli", jingli);
	set("str", 25+random(5));
	set("int", 25+random(5));
	set("con", 25+random(5));
	set("dex", 25+random(5));
	if (user&&userp(user))
	{
		set("age",user->query("age"));
		set("gender",user->query("gender"));
		set("title",HIR"山贼小头目  "+MAG+user->query("family/family_name")+HBMAG+HIW+"弃徒"NOR);
		set_name(user->query("name"),({"bandit "+user->query("id"),"bandit"}));
	}
	if (query("Leader"))
	{
		set("title",HBMAG+HIW+"山大王"+NOR);
		if (user&&userp(user))
		{
			set_name(user->query("name"),({"lord "+user->query("id"),"lord","bandit"}));
			set("age",user->query("age"));
			set("gender",user->query("gender"));
		}
	}
	family_skill(this_object(), family, skill, 1);
	wield_weapon();
}
int Bonus(int base,int pl_num,float exp,float total_exp)
{
	float res;
	int result;
	res=to_float(base*pl_num);
	res=res*(exp/total_exp);
	result=to_int(res);
	return result>100?result:100;
}
void check_env(object env)
{
	int guard=0;
	object *inv=all_inventory(env);
	for (int i=0;i<sizeof(inv);i++)
	{
		if (inv[i]->query("is_BANDIT")&&inv[i]!=this_object())
		guard=1;
	}
	message_vision(HIR"$N"+HIR+"被击中要害，惨叫着从山坡滚落下去。\n"+NOR,this_object());
	if (!guard&&env->query("OUST_FORTRESS"))
	{
		env->delete("max_user");
		if (env->query("finish_Line"))
		{
			inv=filter(inv,(:userp:));
			inv=filter(inv,(:living:));
			for (int i=0;i<sizeof(inv);i++)
			{
				inv[i]->delete_temp("OustBandit");
				inv[i]->add("newjobs/completed/Oust",1);
				tell_object(inv[i],"你累计完成了"+inv[i]->query("newjobs/completed/Oust")+"次清剿山寨任务。\n");
			}
		}
	}
	destruct(this_object());
	return;
}
void die()
{
	object pl,env=environment(this_object()),*inv=all_inventory(env);
	int times=2,lv_bonus,exp=0,pl_num,bonus_exp=1250+env->query("room_id")*40,bonus_pot=750+env->query("room_id")*25,bonus_rep=750+env->query("room_id")*15,myExp,myPot,myRep;
	if (!env->query("OUST_FORTRESS")||!env->query("room_id"))
	return check_env(env);
	if (time()<1407715199) times=3;
	if (!env->query("finish_Line"))
	{
		pl=get_damage_origin_object();
		lv_bonus=pl->query("level")*25;
		if (pl->query("level")>100)
		lv_bonus+=(pl->query("level")-100)*50;
		bonus_exp=(lv_bonus+600+env->query("room_id")*40)*times;
		bonus_pot=(lv_bonus/2+380+env->query("room_id")*25)*times;
		bonus_rep=(lv_bonus/4+180+env->query("room_id")*15)*times;
		if (bonus_exp>5000)
		log_file( "user/OUST", sprintf("%s在%d级别时获得%d的奖励基数。\n", pl->query("id"),pl->query("level"),bonus_exp)) ;  	
		myExp=REWARD_D->add_exp(pl,bonus_exp);
		myPot=REWARD_D->add_pot(pl,bonus_pot);
		myRep=REWARD_D->add_rep(pl,bonus_rep);
		pl->add("exp/oust",myExp);
		pl->add("pot/oust",myPot);
		pl->add("pot/oust",myRep);
		tell_object(pl,HIR+"击败"+this_object()->name()+HIR+"后，你获得了"+myExp+"点经验，"+myPot+"点潜能，"+myRep+"点声望。\n"NOR);
		return check_env(env);
	}
	inv=filter(inv,(:userp:));
	inv=filter(inv,(:living:));
	if (sizeof(inv)<1)
	return check_env(env);
	pl_num=sizeof(inv);
	for (int i=0;i<pl_num;i++)
	exp+=inv[i]->query("combat_exp");
	for (int i=0;i<pl_num;i++)
	{
		myExp=REWARD_D->add_exp(inv[i],Bonus(bonus_exp+inv[i]->query("level")*10,pl_num,to_float(inv[i]->query("combat_exp")),to_float(exp))*times);
		myPot=REWARD_D->add_pot(inv[i],Bonus(bonus_pot+inv[i]->query("level")*8,pl_num,to_float(inv[i]->query("combat_exp")),to_float(exp))*times);
		myRep=REWARD_D->add_rep(inv[i],Bonus(bonus_rep+inv[i]->query("level")*4,pl_num,to_float(inv[i]->query("combat_exp")),to_float(exp))*times);
		inv[i]->add("exp/oust",myExp);
		inv[i]->add("pot/oust",myPot);
		inv[i]->add("pot/oust",myRep);
		tell_object(inv[i],HIR+"打败"+this_object()->name()+HIR+"，你获得了"+myExp+"点经验，"+myPot+"点潜能，"+myRep+"点声望。\n"NOR);
		if (query("Leader")&&inv[i]->query_temp("OustBandit/team")&&arrayp(inv[i]->query_temp("OustBandit/team"))&&sizeof(inv[i]->query_temp("OustBandit/team"))>0)
		{
			for (int j=0;j<sizeof(inv[i]->query_temp("OustBandit/team"));j++)
			if (objectp(inv[i]->query_temp("OustBandit/team")[j])&&environment(inv[i]->query_temp("OustBandit/team")[j])==env
			&&inv[i]->query_temp("OustBandit/team")[j]!=inv[i])
			{
				inv[i]->add("BrotherHood/"+inv[i]->query_temp("OustBandit/team")[j]->query("id"),1);
				tell_object(inv[i],"通过团队合作，你和"+inv[i]->query_temp("OustBandit/team")[j]->query("name")+"之间的互相了解有所加深。\n");
			}
		}
	}
	return check_env(env);
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