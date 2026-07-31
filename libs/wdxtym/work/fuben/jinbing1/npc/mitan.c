//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
   "/clone/fuben/dan/dan_chongmai1",
   "/clone/fuben/dan/dan_chongmai2",
   "/clone/fuben/dan/dan_chongmai3",
   "/clone/fuben/dan/dan_chongmai4", 
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

	set_name(HIY"神秘高手"NOR,({"gaoshou"}));
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
		
	set_skill("force", sklv);
	set_skill("dodge", sklv);
	set_skill("hand", sklv);
	set_skill("cuff", sklv);	
	set_skill("parry", sklv);
    set_skill("mizong-neigong", sklv);	
    set_skill("shenkong-xing", sklv);
    set_skill("dashou-yin", sklv);	
    set_skill("yujiamu-quan", sklv);	        	    	
	
	map_skill("force", "mizong-neigong");
	map_skill("dodge", "shenkong-xing");
	map_skill("hand", "dashou-yin");
	map_skill("cuff", "yujiamu-quan");	
	map_skill("parry", "dashou-yin");	
	
	prepare_skill("hand", "dashou-yin");
	prepare_skill("cuff", "yujiamu-quan");
	setup();
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer,ob;
	int exp;

	if (objectp(killer = query_last_damage_from()))
	{
		killer->add("combat_exp",500);
		killer->add("potential",500);
		tell_object(killer,"你杀死"+name()+"，获得5000点修为，5000点潜能。\n");
		if(killer->query("zhanling/s2") < 10)
		{
		killer->add("zhanling/a2",5);
		killer->add("zhanling/s2",5);
		tell_object(killer,"你杀死"+name()+"，获得5战令修为。\n");
		}
	}
	
	switch (random(3))
	{
		case 0 : 
		
		case 1 :
			new(id)->move(killer);
			new(id)->move(killer);

//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在伏击金兵副本中获得了"+id->short()+"。");
message("channel:chat",HIW"虚拟空间"HIR"："+killer->query("name")+"击败敌军"+id->short()+"\n"NOR,killer);											
		break;
		case 3 :
			new(id)->move(killer);
			new(id)->move(killer);

//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在伏击金兵副本中获得了"+id->short()+"。");
message("channel:chat",HIW"虚拟空间"HIR"："+killer->query("name")+"击败敌军"+id->short()+"\n"NOR,killer);											
		break;
	}
	::die();
}

void unconcious()
{
	die();
}