//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
  "/fuben/wuguan/obj/jinsha",
    "/fuben/wuguan/obj/dan_chongmai1",
    "/fuben/wuguan/obj/book_tianfu",    
});

void create()
{
object ob = this_player();
int lvl = ob->query("qi");
int sklv;
sklv = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333)+random(15));
if (ob->query("combat_exp")<100000){
sklv = 100;
}
if (lvl > 7000){
lvl = 7000;
}
	set_name("蒙古兵",({"bing"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_neili", lvl);
	set("neili", lvl);
	set("eff_qi", lvl);
	set("max_qi", lvl);
	set("qi", lvl);
	set("max_jing", lvl);
	set("jing", lvl);
	set("max_jingli", lvl);
    set("eff_jingli", lvl);
 	set("jingli", lvl);
	set_temp("apply/damage", 150);
	
	set_skill("unarmed", sklv);
	set_skill("force", sklv);
	set_skill("club", sklv);
	set_skill("zhongping-qiang", sklv);
	set_skill("dodge", sklv);
	set_skill("parry", sklv);
	map_skill("club", "zhongping-qiang");
	
	setup();
	carry_object("/d/city/npc/obj/tiejia")->wear();
	carry_object("/clone/weapon/changqiang")->wield();
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer,ob;
	int exp;

	if (objectp(killer = query_last_damage_from()))
	{
		killer->add("combat_exp",5000);
		killer->add("potential",5000);
		tell_object(killer,"你杀死"+name()+"，获得5000点修为，5000点潜能。\n");
		if(killer->query("zhanling/s3") < 10)
		{
		killer->add("zhanling/a3",5);
		killer->add("zhanling/s3",5);
		tell_object(killer,"你杀死"+name()+"，获得5战令修为。\n");
		}
	}
	
	switch (random(10))
	{
		case 0 : 
			new(id)->move(killer);
			new(id)->move(killer);
		break;

		case 5 :
			new(id)->move(killer);
			new(id)->move(killer);
		break;

		case 9 :
			new(id)->move(killer);
			new(id)->move(killer);

//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在伏击金兵副本中获得了"+id->short()+"。");
		break;
//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在单骑破元副本中获得了"+id->short()+"。");	
message("channel:chat",HIW"单骑破元"HIR"："+killer->query("name")+"击败敌军"+id->short()+"\n"NOR,users());									
		break;
	}
	::die();
}

void unconcious()
{
	die();
}