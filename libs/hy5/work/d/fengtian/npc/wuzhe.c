// wuzhe.c

inherit NPC;
 
void create()
{
	set_name("武者", ({"wu zhe"}));
	set("long", "这是一满脸剽悍之气的关外大
汉，看样子还身具武功。\n");
	set("gender","男性");

	set("age",35);
	set("con",20);
	set("str",20);

	set_skill("unarmed",300);
	set_skill("dodge",390);
	set_skill("parry",390);
	set_skill("sword",370);


	set("combat_exp",1250000);

	setup();

	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
