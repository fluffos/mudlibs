// weishi.c -- 王府卫士
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

inherit NPC;

void create()
{
	set_name("王府卫士", ({ "wei shi", "weishi", "wei", "shi" }));
	set("long", "他是一位来自蒙古的精壮武士，马上、步下、摔跤、骑射样样皆能。\n");

	set("gender", "男性");
	set("age", random(10) + 20);


	set("shen_type", 1);
  set("shen", 10000);
	set("attitude", "peaceful");	

	set("str", 30);
	set("int", 20);
	set("con", 25);
	set("dex", 30);
	set("per", random(10) + 15);

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
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/bianxian-ao")->wear();
}

int accept_fight(object me)
{
	command("say 你当这是比武场啊，这里是王府，撒野也不看看地方！");
	return 0;
}