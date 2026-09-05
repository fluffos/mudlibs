// By Zine
               
#include <ansi.h>

inherit FAMILY_NPC;

varargs void wield_weapon(string weapon);
void die();
void create()
{
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        
	set("long",
	"他是一名地宫七层的守卫，武功高强，不太好惹。\n"
         );
	set("is_KARMA_GUARD",1);
	set("gender", "男性");
	set("title",HIW"地宫守卫"NOR);
	set("age", 100);
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
	setup();
	carry_object("/clone/armor/bianfuxuejia")->wear();
	

}
void attempt_kill(object me)
{
	command("say "+me->query("name")+"小辈，竟敢擅闯地宫！");
	kill_ob(me);
}
int copy(object me,object user,string family)
{
	int qi,jing,jingli,neili,exp=me->query("combat_exp")/2,skill = to_int(pow(exp/100,0.333)*10);
	
	
	set("combat_exp",exp);
	qi=me->query("max_qi")*3/2;
	set("qi", qi);
	set("eff_qi",qi);
	set("max_qi",qi);
	jing=me->query("max_jing")*3/2;
	set("jing", jing);
	set("eff_jing",jing);
	set("max_jing",jing);
	neili=me->query("max_neili")*3/2;
	set("max_neili", neili);
	set("neili", neili);
	jingli=me->query("max_jingli")*3/2;
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
		set("title",HIW"地宫守卫 "+HIR+user->query("family/family_name")+"派高手"NOR);
		set_name(user->query("name"),({user->query("id")+" npc","npc"}));
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
	object *inv=all_inventory(env),pl;
	for (int i=0;i<sizeof(inv);i++)
	{
		if (inv[i]->query("is_KARMA_GUARD")&&inv[i]!=this_object())
		guard=1;
		if (userp(inv[i]))
		pl=inv[i];
	}
	if (!guard)
	{
		env->delete("max_user");
		env->Add_Credit(env,"karma_given",pl,1450);
	}
	message_vision(HIW"$N"+HIW+"但见不敌，又藏身到了暗处。\n"+NOR,this_object());
	destruct(this_object());
	return;
}
void die()
{
	object env=environment(this_object()),*inv=all_inventory(env);
	int exp=0,pl_num,bonus_exp=1000+env->query("path")*30,bonus_pot=750+env->query("path")*20,bonus_rep=750+env->query("path")*15,myExp,myPot,myRep;
	if (env->query("level")!=7||!env->query("path"))
	return check_env(env);
	inv=filter(inv,(:userp:));
	inv=filter(inv,(:living:));
	if (sizeof(inv)<1)
	return check_env(env);
	pl_num=sizeof(inv);
	for (int i=0;i<pl_num;i++)
	exp+=inv[i]->query("combat_exp");
	for (int i=0;i<pl_num;i++)
	{
		myExp=REWARD_D->add_exp(inv[i],Bonus(bonus_exp,pl_num,to_float(inv[i]->query("combat_exp")),to_float(exp)));
		myPot=REWARD_D->add_pot(inv[i],Bonus(bonus_pot,pl_num,to_float(inv[i]->query("combat_exp")),to_float(exp)));
		myRep=REWARD_D->add_rep(inv[i],Bonus(bonus_rep,pl_num,to_float(inv[i]->query("combat_exp")),to_float(exp)));
		inv[i]->add_temp("karma/exp_gained",myExp);
		inv[i]->add_temp("karma/pot_gained",myPot);
		inv[i]->add_temp("karma/rep_gained",myRep);
		tell_object(inv[i],HIR+"打败"+this_object()->name()+HIR+"，你获得了"+myExp+"点经验，"+myPot+"点潜能，"+myRep+"点声望奖励。\n"NOR);
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