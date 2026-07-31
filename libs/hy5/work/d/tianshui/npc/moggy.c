// moggy.c
inherit NPC;

void create()
{
	set_name("牛犊", ({ "niu du", "du" }) );
	set("race", "野兽");
	set("age",1);
	set("max_kee",800);
	set("long", "牦牛正在一边吃草一边看护着小牛犊。\n");

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 70000);
	set_temp("apply/attack",40);
	set_temp("apply/defense",50);
	set_temp("apply/damage",20);
	set_temp("apply/armor",20);
	setup();
}
