// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

//杀头领可爆出物品列表
string *random_ob = ({
	"/clone/boss/caifuyingbixiao",
	"/clone/boss/caifuyingbixiao",
	"/clone/boss/caifuyingbixiao",
});

void create()
{
	set_name("教头", ({ "jiaotou", }) );
	set("gender", "男性");
	set("age", 35);
	set("long", "这家伙满脸横肉一付凶神恶煞的模样，令人望而生畏。\n");

	set("combat_exp", 1000000+random(3000000));

	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set_basic();
	setup();

	add_money("gold", 1+random(3));
	
}
void init(object me)
{
	object ob;
	me = this_player();
	ob=this_object();
	::init();

	if (userp(me)) {
		command("say 小子，有点本事啊，我来会会你！\n");
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 40);
		if (!random(3))
			ob->do_clone(me, 40);
		kill_ob(me);
		me->kill_ob(this_object());
	}
}
void die()
{
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	object killer,ob,env;
	int exp;
	int jinbi;
	
	jinbi = new("/clone/boss/caifuyingbixiao");
    jinbi->set_amount(2);
	env = environment(this_object());

	if (objectp(killer = query_last_damage_from()))
	{
		exp = this_object()->query_skill("force",1)*4;
		killer->add("combat_exp",exp);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点修为。"ZJBR+ZJBR"\n");
	}
	
	switch (random(1))
	{
		case 0 : 
		case 1 :
		    new(id)->move(this_object());
		case 9 :
			new(id)->move(this_object());
		break;
	}
	::die();
}
