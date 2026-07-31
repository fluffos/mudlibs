// jiaotou.c

inherit NPC;
 
void create()
{
	set_name("武馆教头", ({"wuguan jiaotou", "jiaotou"}));
	set("long", "这位是武馆的教头正在督促弟子们练功。\n");
	set("gender","男性");

	set("age",38);
	set("con",30);
	set("str",30);
	set("max_kee",900);
	set("max_gin",750);
	set("max_sen",750);
	set("max_force",500);
	set("force",500);
	set("force_factor",10);

	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("unarmed",70);

	set("combat_exp",150000);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
