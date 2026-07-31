// jianqiankai.c 见钱开

#include <ansi.h>

inherit NPC;
                                    
void create()
{
	set_name("见钱开", ({ "jian qian kai", "jian", "qian", "kai" }) );
	set("title", "武场武师");
	set("gender", "男性" );
	set("shen_type", 1);
	set("age", 40);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("no_clean_up",1);

	set("long",
		"这是整天笑咪咪的老板，虽然功夫不高，却也过得自在。\n" );

	set("combat_exp", 50000);
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"见钱开说道: 这位英雄，您想进馆练武吗 ?\n",
	}) );

	set("max_kee", 700);
	set("max_gin", 400);
	set("force", 7000);
	set("max_force", 7000);
	set("force_factor", 50);
	set("shen_type", 1);
                              
	set_skill("force", 60); 
	set_skill("unarmed", 100);
        set_skill("dodge", 100);
	set_skill("parry", 100);
	
	setup();
	

//	carry_object("/obj/pink_cloth")->wear();
}


int accept_object(object who, object ob)
{
	if(this_object()->query_temp("有人/mark"))
		{command("say 非常抱歉，武场爆满，请改日再来\n");
		return 0;
		}
	else
	{
		if (ob->query("money_id") && ob->value() >= 50000) 
		{
//			tell_object(who, "见钱开笑眯眯：好，英雄请进馆。\n");
                         command("say 呵呵，你来晚了，本业务已停止了\n");
                         return 0;
			who->set_temp("教钱了/mark",1);
			return 1;
		}
        }
	return 0;
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting())
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	if(this_object()->query_temp("有人/mark"))
		command("say 非常抱歉，武场爆满，请改日再来\n");
	return ;
}
