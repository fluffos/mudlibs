// tufei.c

inherit NPC;
#include <ansi.h>

mixed ask_yinguo();

//可爆出物品列表
string *random_ob = ({
});

void create()
{
	set_name(MAG"蜀山弟子"NOR, ({ "a1"}) );
	set("gender", "男性");
	set("age", 45);
	set("long", "他是一名蜀山弟子。\n");

	set("combat_exp", 1000+random(3000));

	set("attitude", "peaceful");
	set("str", 1);
	set("int", 1);
	set("con", 1);
	set("dex", 1);
	
	set("max_qi", 1700);
	set("max_jing", 2400);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 500);

	set("combat_exp", 1800);
	set("shen_type", -1);
	set("apprentice_available", 3);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.feilong" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	set_skill("unarmed", 110);
	set_skill("martial-cognize", 120);
	set_skill("sword-cognize", 120);
	set_skill("sword", 110);
	set_skill("force", 112);
	set_skill("parry", 110);
	set_skill("strike", 110);
	set_skill("dodge", 110);
	set_skill("literate", 110);
	set_skill("lonely-sword", 150);
	set_skill("huashan-xinfa", 150);
	set_skill("huashan-quanfa", 150);
	set_skill("huashan-zhangfa", 150);
	set_skill("huashan-shenfa", 150);

	map_skill("sword", "lonely-sword");
	map_skill("parry", "kuangfeng-jian");
	map_skill("force", "huashan-xinfa");
	map_skill("unarmed", "huashan-quanfa");
	map_skill("strike", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yi" :),
		(: perform_action, "parry.po" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/attack", 220);
	set_temp("apply/defense", 220);
	set_temp("apply/damage", 200);
	set_temp("apply/unarmed_damage", 200);


	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();

	setup();
}

void init(object me)
{
	object ob;
	me = this_player();
	ob = this_object();
	::init();

	if (userp(me)&&!me->query_temp("zxt_again")) {
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 1);
		if (!random(3))
			ob->do_clone(me,1);
		kill_ob(me);
		me->kill_ob(this_object());
	}
}

void die()
{

           ::die(); 
}