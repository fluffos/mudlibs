//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
"/fuben/box/box1",
"/fuben/box/box1",
"/fuben/box/box1",
"/fuben/box/box2",
"/fuben/box/box2",
});

void create()
{
object ob = this_player();
int lvl = ob->query("qi");
int sklv = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333)+random(15));
if (lvl > 7000){
lvl = 7000*2;
}
	set_name(HIB"厉魂"NOR,({"li hun"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 250);
	set("int", 250);
	set("con", 250);
	set("dex", 50);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 5000000);
	set("max_qi", 5000000);
	set("jing", 100000);
	set("max_jing", 100000);
	set("neili", 100000);
	set("max_neili", 100000);
	set("jiali", 2500);
	set("combat_exp", 5000000);
	set("score", 2500);
    set_skill("force", 2500+random(2500));
    set_skill("unarmed", 2500+random(2500));
    set_skill("dodge", 1000+random(2500));
    set_skill("parry", 1000+random(2500));
    set_skill("sword", 2500+random(2500));
    set_skill("hand", 2500+random(2500));
    set_skill("cuff", 2500+random(2500));
    set_skill("strike", 2500+random(2500));
    set_skill("finger", 2500+random(2500));
    set_skill("claw", 2500+random(2500));
    set_skill("blade", 2500+random(2500));
    set_skill("staff", 2500+random(2500));
    set_skill("hammer", 2500+random(2500));
    set_skill("club", 2500+random(2500));
    set_skill("whip", 2500+random(2500));
    
    set_skill("xiuxian-gongfas", 2500+random(2500));
    set_skill("xiuxian-gongfas", 2500+random(2500));
    set_skill("xiuxian-gongfas", 2500+random(2500));
    set_skill("xiuxian-gongfas", 2500+random(2500));
    set_skill("xiuxian-gongfas", 2500+random(2500));
    set_skill("xiuxian-gongfas", 2500+random(2500));
    set_skill("xiuxian-gongfas", 2500+random(2500));
		
	map_skill("force", "xiuxian-gongfas");
    map_skill("sword", "xiuxian-gongfas");
    map_skill("parry", "xiuxian-gongfas");
    map_skill("unarmed", "xiuxian-gongfas");
    map_skill("dodge", "xiuxian-gongfas");
	map_skill("hand", "xiuxian-gongfas");
    map_skill("cuff", "xiuxian-gongfas");
    map_skill("strike", "xiuxian-gongfas");
    map_skill("finger", "xiuxian-gongfassA");
    map_skill("claw", "xiuxian-gongfas");
	map_skill("blade", "xiuxian-gongfas");
    map_skill("staff", "xiuxian-gongfas");
    map_skill("hammer", "xiuxian-gongfas");
    map_skill("club", "xiuxian-gongfas");
    map_skill("whip", "xiuxian-gongfas");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.xiuxianb1" :),
		(: perform_action, "force.xiuxianb2" :),
		(: perform_action, "force.xiuxianb3" :),
		(: perform_action, "force.xiuxianb4" :),
		(: perform_action, "force.xiuxianb5" :),
		(: perform_action, "force.xiuxianb6" :),
		(: perform_action, "force.xiuxianb7" :),
		(: exert_function, "force.xiuxiana1" :),
	}));
	set_temp("apply/attack", 10000);
	set_temp("apply/defense", 2000);
	set_temp("apply/unarmed_damage", 10000);
	set_temp("apply/armor", 2000);

    setup();
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer,ob;
	int exp;

	if (objectp(killer = query_last_damage_from()))
	{
	killer->add("combat_exp",350000);
		tell_object(killer,"你杀死"+name()+"，35万修为。\n");
		if(killer->query("zhanling/s4") < 1000)
		{
		killer->add("zhanling/a4",50);
		killer->add("zhanling/s4",50);
		tell_object(killer,"你杀死"+name()+"，获得50战令修为。\n");
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
//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在十三皇陵中获得了"+id->short()+"。");	
message("channel:chat",HIW"十三皇陵"HIR"："+killer->query("name")+"在十三皇陵中获得"+id->short()+"\n"NOR,users());								
		break;
	}
	::die();
}

void unconcious()
{
	die();
}