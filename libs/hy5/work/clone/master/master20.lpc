// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("上官金虹", ({ "master shangguan", "master", "master shang" }) );
        set("title", RED"龙凤双环"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 30);
        set("attitude","friendly");
        set("max_neili", 15000);
        set("neili", 15000);
        set("force_factor", 3);
        set("max_mana",1000);
        set("mana",1000);

        set("long",
"
一个人正站在桌子前翻阅着，不时用朱笔在卷宗上勾划，批改，嘴里偶而会露出一丝
得意的笑容。他是站着的。他认为一个人只要坐下来，就会令自己的精神松弛，一个
人的精神若松弛，就容易造成错误。
\n"
	);

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

        set("combat_exp", 30000000);
        set("score", 200000);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "hammer.longfengshuangfei" :),
        }) );
        set_skill("dodge", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("literate", 60);
        set_skill("jingxing",220);
        set_skill("hammer", 150);
        set_skill("jinhong-steps",220);
        set_skill("longfenghuan",250);
        map_skill("dodge", "jinhong-steps");
        map_skill("hammer", "longfenghuan");
        map_skill("parry", "longfenghuan");
        map_skill("force", "jingxing");
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
set("pubmaster",1);

if (random(2)==0)
{
	set_name(HIY"快活王"NOR, ({ "master jia", "master"}) );
        set("title", YEL"大漠枭雄"NOR);
        set("long",
"当代绝顶高手之一．．\n"
               ); 
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
        }) );

}
  
        set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/longfenghuan")->wield();
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
