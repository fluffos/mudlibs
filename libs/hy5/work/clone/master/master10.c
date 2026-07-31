
inherit NPC;

#include <ansi.h>
void create()
{
	set_name(YEL"葛伦"NOR, ({ "master gelun", "master","gelun" }) );
	set("gender", "男性" );
	set("age", 99);
	set("int", 30);
        set("apprentice_available", 20);

	set("long",
		"葛伦高僧已在大昭寺主持多年。男女弟子遍布关外。\n"
		);
	set("inquiry", ([
		"舍利子": "嗯....舍利子.....在舍利塔里。\n",
		"普松": "普松在大昭寺的木屋里。",
	]) );
        set("combat_exp", 6000000);
        set("score", 90000);
         set("max_neili", 3500);
        set("neili", 3500);
        set("force_factor", 30);
	set("max_qi",2999);
        set("max_jing",2999);
	set("eff_qi",2999);
	set("qi",2999);
	set("eff_jing",2999);
	set("jing",2999);
       set_skill("unarmed", 50);
	set_skill("staff", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 80);
	set_skill("iron-cloth", 150);

	set_skill("bloodystrike", 100);
	set_skill("cloudstaff", 100);
	set_skill("bolomiduo", 200);
	set_skill("buddhism", 200);
        set_skill("jin-gang", 250);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        set("agi",25);
        set("int",30);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
set("pubmaster",1);
if (random(2)==0)
{
	set_name(HIG"花无缺"NOR, ({ "master hua", "master"}) );
        set("title", HIG"绝代双骄"NOR);
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
	carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
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
