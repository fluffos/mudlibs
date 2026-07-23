// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("白三空", ({ "master bai", "master", "baisankong" }) );
        set("title", HIY"清平剑客"NOR);
        set("gender", "男性" );
        set("age", 54);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 20);
	set("attitude","peaceful");
        set("max_neili", 15000);
        set("neili", 15000);
        set("force_factor", 3);
        set("long",
"

\n"
	);

        set("combat_exp", 4000000);
        set("score", 200000);
        set("chat_chance", 10);
        set("chat_msg", ({
	"白三空摇头叹道：＂清平山庄横祸不断，人丁衰弱．．．＂\n",
                (: random_move :),
        }) );

        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("unarmed", 80);
        set_skill("bai-quan",80);
        set_skill("literate", 100);
        set_skill("sword",130);
        set_skill("qingpingsword",250);
        set_skill("qingpingforce",220);
        set_skill("chaos-steps",220);
        map_skill("force", "qingpingforce");
        map_skill("parry","qingpingsword");
        map_skill("sword","qingpingsword");
        map_skill("dodge","chaos-steps");
        map_skill("dodge","chaos-steps"); 
        map_skill("unarmed","bai-quan"); 
set("pubmaster",1);
if (random(2)==0)
{
	set_name(HIB"小雷"NOR, ({ "master lei", "lei"}) );
        set("title", RED"绝不畏死"NOR);
        set("long",
"当代绝顶高手之一．．\n"
               ); 
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
        }) );

}
        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",9999);
        set("max_jing",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("eff_jing",9999);
	set("jing",9999);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.choushen" :),
                (: perform_action, "sword.youzijue" :),
        }) );
        set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/longsword")->wield();
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
