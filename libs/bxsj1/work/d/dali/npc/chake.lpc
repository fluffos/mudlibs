//  chake.c
inherit NPC;

void create()
{
	set_name("茶客", ({ "cha ke","ke" }) );
	set("gender", "男性");
	set("age", 10+random(30));
	set("long",
		"这是大理城内茶馆内的一位茶客，他正蛮有滋味的品着茶。\n");
	set("combat_exp", 16000);
	set("shen_type", 1);
	set("attitude", "friendly");
	setup();

	set("apply/attack", 20);
	set("apply/defense", 20);

	set_skill("unarmed", 30);
	set_skill("strike", 30);
	set_skill("parry", 30);
	set_skill("dodge", 36);
	setup();

	carry_object("/clone/misc/cloth")->wear();
       add_money("silver", random(10));

}       

