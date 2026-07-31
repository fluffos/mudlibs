// feizei.c
//by luoyun 2016.7.6

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

void create()
{
	set_name("飞贼",({ "fei zei","fei" }) );
	set("title",HIY"飞天遁地"NOR);
	set("gender", "男性" );
	set("age", 33);
	set("long", "这是无恶不做的飞贼，背上有一个小小包裹，看样子是才偷了什么东西在手。\n");

	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("no_magic", 1);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 5000);

	set_skill("unarmed",90);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("staff", 100);
	set_skill("literate", 80);
	
	set("chat_chance", 80);
	set("chat_msg", ({
		(: random_move :),
	}) );
	
	set_basic();
	
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void init(object me)
{
	object ob;
	mapping skills;
	string *sk;
	int j, jiali, i, lvl;
	
	me = this_player();
	ob = this_object();
	::init();
	
	if (userp(me)) {
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 1);
		if (!random(3))
			ob->do_clone(me, 1);
		
		lvl = 240;//设置所有技能120级
		
		set("int", 30);
		set("str", 30);
		set("con", 30);
		set("dex", 30);
		set("qi", 2000);
		set("max_qi", 2000);
		set("jing", 1000);
		set("max_jing", 1000);
		set("neili", 1000);
		set("max_neili", 1000);
		set("combat_exp", 5000);
		
		skills = ob->query_skills();
		if (mapp(skills))
		{
			sk = keys(skills);
			j = sizeof(sk);
			for (i = 0; i < j; i++)
				skills[sk[i]] = lvl;
		}
		jiali = ob->query_skill("force", 1) / 5;
		if (jiali > 100) jiali = 100;
		ob->set("jiali", jiali);
	}
}

void die()
{
	object ob,obj;
     int num;
		ob = new("clone/shizhe/baozhu");
		num=random(4)+4;
        ob->set_amount(num);
		ob->move(this_object());

	//95%几率出藏宝图
	if (random(100) < 50)
	{
		ob = new("/d/fuben/obj/heifeng1");
		ob->move(this_object());
	}
	
	//if (random(100) < 50)
	//{
	//	ob = new("/clone/shizhe/baozhu");
	//	ob->move(this_object());
	//}
	if (objectp(obj = query_last_damage_from()))
		message("channel", HIR"【官府】:"HIY"听说有飞贼已被"+HIG+obj->query("name")+HIY"捉拿归案！"NOR"\n", users());
	else
		message("channel", HIR"【官府】:"HIY"听说有飞贼已被捉拿归案！"NOR"\n", users());
	::die();
}
