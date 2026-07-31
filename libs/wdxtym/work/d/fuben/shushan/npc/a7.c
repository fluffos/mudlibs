// tufei.c

inherit NPC;
#include <ansi.h>

mixed ask_yinguo();

//可爆出物品列表
string *random_ob = ({
    "/clone/vip/putao",
    "/clone/money/gold",
});

void create()
{
	set_name(HIY"看"HIW"剑"HIY"者"NOR, ({ "a7"}) );
	set("gender", "男性");
	set("age", 45);

	set("combat_exp", 10000+random(3000));

	set("attitude", "peaceful");
	set("str", 3);
	set("int", 3);
	set("con", 3);
	set("dex", 3);
	set("max_qi", 5400);
	set("max_jing", 85200);
	set("neili", 50800);
	set("max_neili", 58000);
	set("jiali", 50088);

	set("combat_exp", 1800);
	set("shen_type", -1);
	set("apprentice_available", 3);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.feilong" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	set_skill("unarmed", 210);
	set_skill("martial-cognize", 220);
	set_skill("sword-cognize", 220);
	set_skill("sword", 210);
	set_skill("force", 212);
	set_skill("parry", 10);
	set_skill("strike", 210);
	set_skill("dodge", 220);
	set_skill("literate", 110);
	set_skill("lonely-sword", 250);
	set_skill("huashan-xinfa", 150);
	set_skill("huashan-quanfa", 310);
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
			ob->do_clone(me, 40);
		if (!random(3))
			ob->do_clone(me, 40);
		kill_ob(me);
		me->kill_ob(this_object());
	}
}

void die()
{

           ::die(); 
}