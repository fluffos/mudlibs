//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
"/fuben/box/box5",
"/fuben/box/box5",
"/fuben/box/box5",
"/fuben/box/box6",
"/fuben/box/box6",
"/fuben/box/box3",
"/fuben/box/box3",
"/fuben/box/box3",
"/fuben/box/box4",
"/fuben/box/box4",
"/HCSP/wzzbSP/sp1",
"/HCSP/wzzbSP/sp2",
"/HCSP/wzzbSP/sp3",
"/HCSP/wzzbSP/sp4",
"/HCSP/wzzbSP/sp5",
"/HCSP/wzzbSP/sp6",
"/HCSP/wzzbSP/sp7",
"/HCSP/wzzbSP/sp8",
"/HCSP/wzzbSP/sp9",
"/HCSP/wzzbSP/sp1",
"/HCSP/wzzbSP/sp2",
"/HCSP/wzzbSP/sp3",
"/HCSP/wzzbSP/sp4",
"/HCSP/wzzbSP/sp5",
"/HCSP/wzzbSP/sp6",
"/HCSP/wzzbSP/sp7",
"/HCSP/wzzbSP/sp8",
"/HCSP/wzzbSP/sp9",
"/HCSP/wzzbSP/sp1",
"/HCSP/wzzbSP/sp2",
"/HCSP/wzzbSP/sp3",
"/HCSP/wzzbSP/sp4",
"/HCSP/wzzbSP/sp5",
"/HCSP/wzzbSP/sp6",
"/HCSP/wzzbSP/sp7",
"/HCSP/wzzbSP/sp8",
"/HCSP/wzzbSP/sp9",
});

void create()
{
object ob = this_player();
int lvl = ob->query("qi");
int sklv = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333)+random(15));
if (lvl > 7000){
lvl = 7000;
}
	set_name(HIM"教头"NOR,({"wuguan jiaotou"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 150);
	set("int", 150);
	set("con", 150);
	set("dex", 75);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 5000000);
	set("max_qi", 5000000);
	set("jing", 100000);
	set("max_jing", 100000);
	set("neili", 100000);
	set("max_neili", 100000);
	set("jiali", 1500);
	set("combat_exp", 5000000);
	set("score", 1500);
    set_skill("force", 1500+random(1500));
    set_skill("unarmed", 1500+random(1500));
    set_skill("dodge", 1500+random(1500));
    set_skill("parry", 1500+random(1500));
    set_skill("sword", 1500+random(1500));
    set_skill("hand", 1500+random(1500));
    set_skill("cuff", 1500+random(1500));
    set_skill("strike", 1500+random(1500));
    set_skill("finger", 1500+random(1500));
    set_skill("claw", 1500+random(1500));
    set_skill("blade", 1500+random(1500));
    set_skill("staff", 1500+random(1500));
    set_skill("hammer", 1500+random(1500));
    set_skill("club", 1500+random(1500));
    set_skill("whip", 1500+random(1500));
    
    set_skill("wushang-jianjing", 1500+random(1500));
    set_skill("wushang-jianjing", 1500+random(1500));
    set_skill("wushang-jianjing", 1500+random(1500));
    set_skill("wushang-jianjing", 1500+random(1500));
    set_skill("wushang-jianjing", 1500+random(1500));
    set_skill("wushang-jianjing", 1500+random(1500));
    set_skill("wushang-jianjing", 1500+random(1500));
		
	map_skill("force", "wushang-jianjing");
    map_skill("sword", "wushang-jianjing");
    map_skill("parry", "wushang-jianjing");
    map_skill("unarmed", "wushang-jianjing");
    map_skill("dodge", "wushang-jianjing");
	map_skill("hand", "wushang-jianjing");
    map_skill("cuff", "wushang-jianjing");
    map_skill("strike", "wushang-jianjing");
    map_skill("finger", "wushang-jianjingsA");
    map_skill("claw", "wushang-jianjing");
	map_skill("blade", "wushang-jianjing");
    map_skill("staff", "wushang-jianjing");
    map_skill("hammer", "wushang-jianjing");
    map_skill("club", "wushang-jianjing");
    map_skill("whip", "wushang-jianjing");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.wushangb1" :),
		(: perform_action, "force.wushangb2" :),
		(: perform_action, "force.wushangb3" :),
		(: perform_action, "force.wushangb4" :),
		(: perform_action, "force.wushangb5" :),
		(: perform_action, "force.wushangb6" :),
		(: perform_action, "force.wushangb7" :),
		(: exert_function, "force.wushanga1" :),
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
		killer->add("combat_exp",150000);
		killer->add("potential",150000);
		tell_object(killer,"你杀死"+name()+"，获得150000点修为，150000点潜能。\n");
		if(killer->query("zhanling/s1") < 1000)
		{
		killer->add("zhanling/a1",100);
		killer->add("zhanling/s1",100);
		tell_object(killer,"你杀死"+name()+"，获得100战令经验。\n");
		}
	}
	
	switch (random(15))
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
//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"在武馆训练中获得了"+id->short()+"。");	
message("channel:chat",HIW"武馆训练"HIR"："+killer->query("name")+"击败弟子"+id->short()+"\n"NOR,users());									
		break;
	}
	::die();
}

void unconcious()
{
	die();
}