// enu.c

inherit NPC;

void create()
{
	set_name("惡奴", ({ "e nu", "nu" }));
	set("age", 32);
	set("gender", "男性");
	set("long", "他看上去膀大腰粗，橫眉怒目，滿面橫肉。看來手下倒也有點功夫 。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 20);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", -1);

	set_skill("unarmed", 40);
	set_skill("dodge", 100);
	set_skill("parry", 40);
	set_skill("blade", 100);
	set_skill("force", 40);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
