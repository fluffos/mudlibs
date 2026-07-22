// yanshang.c 盐商

inherit NPC;

void create()
{
	set_name("盐商", ({ "yan shang", "yanshang", "shang ren", "trader"}));
	set("gender", "男性");
	set("age", 32+random(20));
	set("long", "他是一个贩江北淮盐的盐商，每次到扬州一定去鸣玉坊排筵席嫖妓。\n");

	set("combat_exp", 3000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 30);
	set_skill("dodge", 20);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 10);
}
