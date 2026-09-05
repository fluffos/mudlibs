// weishi-zhang.c -- 卫士长
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

inherit NPC;

void create()
{
	set_name("卫士长", ({ "weishi zhang", "weishi", "zhang" }));
	set("long", "他是汝阳王府的卫士长，统领着汝阳王府的所有卫士，担负着保护汝阳王的重任。\n");

	set("gender", "男性");
	set("age", 34);


	set("shen_type", 1);
  set("shen", 10000);
	set("attitude", "peaceful");	

	set("str", 30);
	set("int", 20);
	set("con", 25);
	set("dex", 30);
	set("per", 25);

	set("combat_exp", 100000);
			set_skill("unarmed", 100);
			set_skill("force", 100);
			set_skill("parry", 100);
			set_skill("dodge", 100);
			set_skill("sword", 100);
			set_skill("blade", 100);
			set_temp("apply/attack", 100);
			set_temp("apply/defense", 100);
			set_temp("apply/armor", 100);
			set_temp("apply/damage", 100);

			set("neili", 4000); 
			set("max_neili", 4000);
			set("jiali", 100);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object(__DIR__"obj/bianxian-ao")->wear();
	carry_object(__DIR__"obj/liuye-jia")->wear();
}

int accept_fight(object me)
{
	command("say 你当这是比武场啊，这里是王府，撒野也不看看地方！");
	return 0;
}
