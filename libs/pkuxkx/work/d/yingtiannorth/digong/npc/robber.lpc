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
	"他是一名沙漠中最凶恶的强盗，杀人越货，无恶不作。\n"
         );
	set("is_KARMA_ROBBER",1);
	set("gender", "男性");
	set("title",HIY"沙盗"NOR);
	set("age", 40);
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
int copy(int exp,int qi,int jing,int neili,int jingli)
{
	int skill = to_int(pow(exp/100,0.333)*10);
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
	family_skill(this_object(), "random", skill, 1);
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
void die()
{
	int exp=0,pl_num,bonus_exp=1000,bonus_pot=750,bonus_rep=750,myExp,myPot,myRep;
	object env=environment(this_object()),*inv=all_inventory(env);
	object * places=({});
	if (env->query("level")!=6||env->query("maze")!=1||env->query("outdoors")!="digong")
	::die();
	inv=filter(inv,(:userp:));
	inv=filter(inv,(:living:));
	if (sizeof(inv)<1)
	::die();
	pl_num=sizeof(inv);
	for (int i=0;i<pl_num;i++)
	exp+=inv[i]->query("combat_exp");
	for (int i=0;i<pl_num;i++)
	{
		if (inv[i]->query_temp("karma/level6/pass_places")&&arrayp(inv[i]->query_temp("karma/level6/pass_places")))
		places=inv[i]->query_temp("karma/level6/pass_places");
		if (member_array(env,places)==-1)
		places+=({env});
		inv[i]->set_temp("karma/level6/pass_places",places);
		myExp=REWARD_D->add_exp(inv[i],Bonus(bonus_exp,pl_num,to_float(inv[i]->query("combat_exp")),to_float(exp)));
		myPot=REWARD_D->add_pot(inv[i],Bonus(bonus_pot,pl_num,to_float(inv[i]->query("combat_exp")),to_float(exp)));
		myRep=REWARD_D->add_rep(inv[i],Bonus(bonus_rep,pl_num,to_float(inv[i]->query("combat_exp")),to_float(exp)));
		inv[i]->add_temp("karma/exp_gained",myExp);
		inv[i]->add_temp("karma/pot_gained",myPot);
		inv[i]->add_temp("karma/rep_gained",myRep);
		tell_object(inv[i],HIR+"打败"+this_object()->name()+HIR+"，你获得了"+myExp+"点经验，"+myPot+"点潜能，"+myRep+"点声望奖励。\n"NOR);
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