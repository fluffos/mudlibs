
inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIB"老刀把子"NOR, ({ "master laodao", "lao dao"}) );
	set("gender", "男性" );
	set("long", "他身穿灰袍，头戴竹笠，就象个有刑无质的鬼魂。\n" );
if (random(2)==0)
{
	set_name(HIY"郭嵩阳"NOR, ({ "master songyang", "songyang"}) );
	set("title",YEL"嵩阳铁剑"NOR);
}
	set("age", 45);
	set("int", 30);
	set("str", 30);
	set("per", 30);
        set("apprentice_available", 50);
        set("class", "ghost");

        set("max_neili", 3500);
        set("neili", 3500);
        set("force_factor", 30);
	set("max_qi",2999);
        set("max_jing",2999);
	set("eff_qi",2999);
	set("qi",2999);
	set("eff_jing",2999);
	set("jing",2999);
        set("chat_chance", 1);
        set("combat_exp", 9999999);
        set("score", 90000);
        set("skill_public", 1);
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("force", 200);
        set_skill("parry", 150);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("three-sword", 200);
	set_skill("taiji-quan", 200);

  	 map_skill("unarmed", "taiji-quan");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");

        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
set("pubmaster",1);
        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",9999);
        set("max_jing",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("eff_jing",9999);
	set("jing",9999);
       set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.nianzijue" :),
        }) );
	set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
        carry_object(__DIR__"obj/cloth3")->wear();
        carry_object(__DIR__"obj/hat")->wear();
        carry_object(__DIR__"obj/swordd")->wield();
}



int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say 既然你诚心想学我的武功，我就成全成全你吧。");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
