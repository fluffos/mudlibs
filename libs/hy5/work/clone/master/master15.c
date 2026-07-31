//TIE@FY3
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("李玉函", ({ "master li", "master","li" }) );
	set("gender", "男性" );
        set("title", HIC"黄山派掌门"NOR);
	set("age", 25);
	set("int", 30);
	set("per", 30);
        set("apprentice_available", 50);
	set("long",
		"李玉函乃天下第一剑客李观鱼之子，出身拥翠山庄，因少年有为而被任为黄山派掌门\n"
		);
        set("force_factor", 20);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_neili", 3000);
        set("neili", 3000);

        set("combat_exp", 59999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("yunwu-strike", 200);
	set_skill("qiusheng-blade", 230);
	set_skill("xianjing", 250);
	set_skill("liuquan-steps", 200);

	map_skill("unarmed", "yunwu-strike");
        map_skill("blade", "qiusheng-blade");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan" :),
                (: perform_action, "unarmed.miwu" :),
                (: perform_action, "blade.jingsheng" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
set("pubmaster",1);
if (random(2)==0)
{
	set_name(HIR"卜鹰"NOR, ({ "master ying", "master"}) );
        set("title", WHT"风铃中的刀声"NOR);
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
	set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
	carry_object(__DIR__"obj/greencloth")->wear();
        carry_object(__DIR__"obj/yuhuan")->wield();
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
