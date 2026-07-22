// huo.c 
// Modify By River 98/12
inherit NPC;

void create()
{
	set_name("霍先生", ({ "huo xiansheng", "huo","xianshen" }));
	set("title", "镇南王府管家");
	set("gender", "男性");
	set("age", 40);
	set("str", 25);
	set("dex", 25);
        set("unique", 1);
        set("long", "这是一个形貌猥琐的笑嘻嘻的老头儿，是帐房中相助昭管杂务的。 
此人每日不是在醉乡之中，便是与下人赌钱，最是惫懒。\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
        set_skill("hammer", 80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 20);

	set("max_qi", 800);
	set("neili", 800); 
	set("max_neili", 800);

	setup();
	carry_object(__DIR__"obj/suanpan")->wield();
	carry_object("/d/dali/npc/obj/qingpao")->wear();
}

int accept_fight(object me)
{
	command("say 您这是哪里话，小人哪里是您的对手，不敢不敢。");
	return 0;
}
