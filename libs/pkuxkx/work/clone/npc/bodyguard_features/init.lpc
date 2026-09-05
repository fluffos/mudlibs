//玩家召唤保镖 zine 2014/8/13
#include <ansi.h>
#include "/clone/npc/bodyguard_config.h"
void set_desc(object ob)
{
	int pot_lv,ab_lv,*wage=({100,90,80,70,60,50,40,30,20});
	string gender=ob->query("gender")=="男性"?"他":"她";
	if (!ob->query("potential_ability")||!ob->query("ability")) 
	{
		ob->set("long",gender+"是一个普普通通的保镖。\n");
		return;
	}
	pot_lv=10-(ob->query("potential_ability")/20-1);
	ab_lv=10-(ob->query("ability")/20-1);
	ob->set("wage",random(wage[pot_lv-1])+wage[ab_lv-1]*2+random(wage[ab_lv-1]));
	ob->set("long",gender+"是一位小有名气的武林人物，具有第"+chinese_number(ab_lv)+"流的能力以及第"+chinese_number(pot_lv)+"流的潜力。\n");
	return;
}
void initialize_guard(object ob)
{
	object owner;
	int exp,age,range,*potential=({200,175,150,125,100,75}),*abilities=({50,65,80,95,110,110}),ability,pot,tmp,*skill_lv=({60,160,240,300,350,390,430,460,490,520,540});
	string *birth_places=({"冀州","兖州","青州","徐州","扬州","荆州","梁州","雍州","豫州"});
	if (owner=ob->query("owner"))
	{	
		return ob->restore_guard(owner);
	}
	else//首次生成
	{
		age=14+random(26);
		ob->set("age",age); //14-39岁，正常而言年纪越小，潜力越高，年纪越大，能力越高。
		ob->set("birth_place",birth_places[random(9)]);
		ob->set("chance",1+random(99));//差异度相关
		range=age/5-2;
		if (!random(10)&&range>0) range-=1;
		if (!random(20)&&range>0) range-=1;
		tmp=3-range;
		if (tmp<1) tmp=1;
		pot=potential[range]-random(25)*tmp;
		ob->set("potential_ability",pot);
		range=age/5-2;
		ability=abilities[range];
		if (!random(10)&&ability<200) ability+=10;
		if (!random(20)&&ability<200) ability+=10;
		if (!random(40)&&ability<200) ability+=20;
		if (!random(80)&&ability<200) ability+=40;
		if (!random(100)&&ability<200) ability+=40;
		ob->set("ability",ability);
		ability=ability/15-3;
		ob->family_skill(ob, "random", skill_lv[ability], 1);
		exp=skill_lv[ability]*skill_lv[ability]*skill_lv[ability]/10;
		ob->set("combat_exp",exp+random(exp/4));
		set_desc(ob);
	}
	return;
}