// biaoshi.c

inherit NPC;
 
void create()
{
	set_name("镖师", ({"biao shi"}));
	set("title","威远镖局");

	set("long", "这是一位精壮的大汉。\n");
	set("gender","男性");

	set("age",28);
	set("con",30);
	set("str",30);
	set("kar",40);
	set("max_kee",900);
	set("max_gin",750);
	set("max_sen",750);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",10);

	set_skill("dodge",100);
	set_skill("parry",90);
	set_skill("unarmed",80);

	set("combat_exp",150000);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
