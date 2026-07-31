// servant.c
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("楚留香", ({ "master chu", "chu", "master" }) );
        set("title", HIG"盗帅"NOR);
              set("title", HIY "妙绝天下" NOR);
        set("gender", "男性");
        set("age", 34);       

        set("long",
"他双眉被面长，充满粗犷的男性魅力，但那双清澈的眼晴，却又是那麽秀逸。他鼻子
挺直，象征坚强、决断的铁石心肠，他那薄薄的，嘴角上翘的嘴，看来也有些冷酷，但
只要他一笑起来，坚强就变作温柔，冷酷也变作同情，就像是温暖的春风吹过了大地。\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 10000000);
        set("agi",25);
        set("int",40);
        set("skill_public",1);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "楚留香道：四年前见过枯梅大师一次，那次我是陪蓉儿她们去游华山时远远瞧过她一眼。 \n",
                (: random_move :),
        }) );

        set("str", 30);
        set("int", 40);
        set("cor", 5);
        set("cps", 5);
        set("con", 25);
        set("agi", 50);
        set("per", 40);
	 set("fle", 15);

        set("neili", 7000);
        set("max_neili", 3500);
        set("force_factor", 70);
        set("skill_public", 1);

        set_skill("force", 150);
        set_skill("unarmed", 120);
        set_skill("parry", 150);
        set_skill("dodge", 320);
        set_skill("dodge", 320);
        set_skill("literate", 150);

        set_skill("bibo-force", 150);
        set_skill("luoriquan", 200);
        set_skill("fengyu-piaoxiang", 320);
        set_skill("stealing",200);

        map_skill("force", "bibo-force");
        map_skill("unarmed", "luoriquan");
        map_skill("dodge", "fengyu-piaoxiang");
        map_skill("dodge", "fengyu-piaoxiang");
set("pubmaster",1);
if (random(2)==0)
{
	set_name(HIB"胡铁花"NOR, ({ "master hu", "master"}) );
        set("title", HIY"老臭虫"NOR);
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
                (: perform_action, "unarmed.luori" :),
                (: perform_action, "dodge.zonghengsihai" :),
        }) );
        set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();

        carry_object(__DIR__"obj/whitecloth")->wear();

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
