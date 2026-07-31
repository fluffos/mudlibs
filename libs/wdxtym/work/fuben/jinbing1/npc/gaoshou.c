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
	set_name(HIM"神秘人"NOR,({"shenmi"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_neili", lvl*2);
	set("neili", lvl*2);
	set("eff_qi", lvl*2);
	set("max_qi", lvl*2);
	set("qi", lvl*2);
	set("max_jing", lvl*2);
	set("jing", lvl*2);
	set("max_jingli", lvl*2);
    set("eff_jingli", lvl*2);
 	set("jingli", lvl*2);
		
	set_skill("force", sklv);
	set_skill("dodge", sklv);
	set_skill("hand", sklv);
	set_skill("cuff", sklv);	
	set_skill("parry", sklv);
    set_skill("longxiang", sklv);	
    set_skill("shenkong-xing", sklv);
    set_skill("dashou-yin", sklv);	
    set_skill("yujiamu-quan", sklv);	        	    	
	
	map_skill("force", "longxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("hand", "dashou-yin");
	map_skill("cuff", "yujiamu-quan");	
	map_skill("parry", "dashou-yin");	
	
	prepare_skill("hand", "dashou-yin");
	prepare_skill("cuff", "yujiamu-quan");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "hand.jingang" :),
		(: perform_action, "cuff.chen" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));		
	setup();
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品

	object killer,ob;
	int exp;
	int num;
	if (objectp(killer = query_last_damage_from()))
	{
	    num=10+random(killer->query("kar"));	
		killer->add("combat_exp",10000);
		killer->add("potential",10000);
	   
		tell_object(killer,"你杀死"+name()+"，获得10000点修为，10000点潜能。\n");
		if(killer->query("zhanling/s2") < 10)
		{
		killer->add("zhanling/a2",10);
		killer->add("zhanling/s2",10);
		tell_object(killer,"你杀死"+name()+"，获得10战令修为。\n");
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