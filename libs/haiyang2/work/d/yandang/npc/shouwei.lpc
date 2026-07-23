inherit NPC;

void create()
{
	set_name("守卫", ({ "shou wei","dizi" }));
	set("age", 34);
	set("gender", "男性");
       set("title","留月居");
	set("str", 34);
	set("dex", 36);
	set("combat_exp", 90000);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("force", 80);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
add_money("silver",30);
}
