#pragma save_binary
// gold_worm.c

inherit BHNPC;

void create()
{
	set_name("金色岩蛭", ({ "gold rock leech", "leech" }) );
	set("long",
		"这条岩蛭看起来金光闪闪，跟其他丑恶的岩蛭大不相同，你注意到它\n"
		"口中白牙中竟微微地发著光，不知道肚子里藏了什么东西。\n");

	set("race", "野兽");
	set("unit", "条");
	set("age", 245);

	set("max_gin", 2000);
	set("max_kee", 2500);
	set("max_sen", 2000);

 set("str", 30);
	set("con", 80);
	set("cor", 80);
	set("cps", 80);
	set("spi", 40);
	set("int", 60);
	set("kar", 80);
	set("per", 40);

	set("limbs", ({ "头部", "躯干" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 120);
	set_temp("apply/damage", 30);
	set_temp("apply/dodge", 120);
	set_temp("apply/armor", 20);
	set_temp("apply/armor_vs_force", 2000);

  set("combat_exp", 1700000);
	setup();
}
