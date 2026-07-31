// heaven_soldier.c
#include <ansi.h>
inherit HUFA;

varargs void setskills(int i)
{
	string *order = ({"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"});
	set_name( (order[random(12)]) + "阴鬼卒", ({ "hell guard", "guard","hufa","hu fa" }) );
	set("look_msg", "这是一位来自阴界的守护神，专门担任护法之责。\n");
	set("attitude", "heroism");
	set("chat_chance", 50);
	set("chat_msg_combat", ({
        	name() + "喝道：孽障！随我赴阴司受审吧。\n"
	}) );
	set_skill("parry", i);
	set_skill("kusang-bang",i);
	set_skill("stick",i);
	map_skill("stick","kusang-bang");
	map_skill("parry","kusang-bang");
	set_skill("ghost-steps",i);
	set_skill("dodge", i);
	map_skill("dodge","ghost-steps");
	set_skill("force",i);
	set_skill("tonsillit",i);
	map_skill("force","tonsillit");
	set_skill("spells",i);
	set_skill("gouhunshu",i);
	map_skill("spells","gouhunshu");

	set("max_force",query_skill("force")*10);
	set("max_mana",query_skill("spells")*10);
	if( this_object()->query_level()<70 )
	{
		add_temp("apply/max_kee",500);
		add_temp("apply/max_sen",500);
	}
	else if( this_object()->query_level()<90 )
	{
		add_temp("apply/max_kee",800);
		add_temp("apply/max_sen",800);
	}
	else
	{
		add_temp("apply/max_kee",1000);
		add_temp("apply/max_sen",1000);
	}
	set("env/msg_min",HIB "一道蓝光从地底升起，蓝光中出现一个手执钢叉、面目狰狞的鬼卒。$N"HIB"说道：末将奉法主召唤，特来护法！\n" NOR);
	set("env/msg_mout",HIB"$N"HIB"说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！$N"HIB"的身形发出幽暗的蓝光，沈入地下不见了。\n"NOR);
}

int heal_up()
{
	int i,p;
	if( i=::heal_up()>1 )
	{
		if( query_owner() && living(query_owner())
		 && present(query_owner(),environment())
		 && query_owner()->query("mana")>15 )
		{		 
		 	if( query_owner()->query("eff_kee")<query_owner()->query_maxkee() )
			{
				p = query_owner()->query_maxkee()-query_owner()->query("eff_kee");
				if( query("mana")>(p/20+5) )
				{
					add("mana",-5-p/20);
					query_owner()->receive_curing("kee",p);
				}
			}
		 	if( query_owner()->query("eff_sen")<query_owner()->query_maxsen() )
			{
				p = query_owner()->query_maxsen()-query_owner()->query("eff_sen");
				if( query("mana")>(p/20+5) )
				{
					add("mana",-5-p/20);
					query_owner()->receive_curing("sen",p);
				}
			}
		}
	}
	return i;			
}