inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIY "天机老人" NOR, ({ "tianji", "Tian ji", "Tian" }) );
        set("gender", "男性");
	set("title", HIC"闲云野鹤"NOR);
        set("age", 99);
        set("long",
		"天机老人年过六甲，鹤发童颜。在兵器谱上排名第一，
尤在上官，小李之上．此人亦正亦邪，凡事都由爱恶而定。天机老人收徒极挑剔．．．．\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 260);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "天机老人拿起旱烟抽了几口．．．．\n",
        }) );

	set("neili", 40000);
	set("max_neili", 80000);
	set("force_factor", 1000);

	set("combat_exp", 10000000);
	set("score", 200000);

set("pubmaster",1);
if (random(2)==0)
{
	set_name(RED"杨铮"NOR, ({ "master yang", "master"}) );
        set("title", HIY"离别钩"NOR);
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

	set_skill("unarmed", 220);
	set_skill("force", 200);
	set_skill("iron-cloth", 300);
	set_skill("yiqiforce", 230);
	set_skill("dagger",300);
	set_temp("apply/dodge",200);
	set_temp("apply/attack",200);
	set_temp("apply/armor",3500);
	set_temp("apply/damage",9000);
	map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");


        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );

	set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();

	carry_object(__DIR__"obj/jade-ring")->wear();
	carry_object(__DIR__"obj/jade-pin")->wear();
	carry_object(__DIR__"obj/jade-boots")->wear();
	carry_object(__DIR__"obj/jade-cloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
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
