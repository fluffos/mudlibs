inherit NPC;

void create()
{
	set_name("ÊØÎÀ", ({ "shou wei","dizi" }));
	set("age", 34);
	set("gender", "ÄĞĞÔ");
       set("title","ÁôÔÂ¾Ó");
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
