// master.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("李寻欢", ({ "master li", "master", "master li xunhuan" }) );
        set("nickname", RED"小李飞刀"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("str", 30);
        set("dex", 130);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","friendly");
        set("max_neili", 15000);
        set("neili", 15000);
	set("courage",1000);
        set("force_factor", 3);

        set("rank_info/respect", "李探花");

        set("long",
"李寻欢别号李探花，又有江湖绰号小李飞刀。
一手飞刀绝技，在百晓生的兵器谱上排行第三。
不发则已，但例无虚发。\n"                
	);
	set("student_title","人杰");
        set("combat_exp", 10000000);
        set("score", 200000);
set("pubmaster",1);
        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",19999);
	set("qi",19999);
	set("eff_jing",19999);
	set("jing",19999);

        set("chat_chance", 10);
        set("chat_msg", ({
                "李寻欢不停的在咳，嘴角流下一丝鲜血。\n",
                "李寻欢的脸色越发苍白了。\n",
"李寻欢叹口气，呆呆地望着手里的木像。\n",
               (: random_move :),
        }) );
       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.xiaoli-feidao" :),
                (: perform_action, "throwing.xiaoli-feidao" :),
        }) );
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
	set_skill("feidao", 320);
        set_skill("force", 40);
        set_skill("literate", 200);
       	map_skill("throwing", "feidao");
if (random(2)==0)
{
	set_name(HIG"叶开"NOR, ({ "master ye", "master"}) );
        set("title", HIY"飞刀传人"NOR);
        set("long",
"当代绝顶高手之一．．\n"
               ); 
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
        }) );

}

        set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();
carry_object(__DIR__"obj/xlfd_knife")->wield();
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
