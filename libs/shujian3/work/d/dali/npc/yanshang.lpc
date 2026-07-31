// yanshang.c 大理盐商

inherit NPC;

void create()
{
        set_name("大理盐商", ({ "dali yanshang", "yanshang", "trader" }));
	set("gender", "男性");
        set("age", 32);
        set("long", "他是一个专门将江北淮盐拿到大理来贩卖的盐商。\n");
	
        set("combat_exp", 3000);
        set("shen_type", 1);

	set("attitude", "peaceful");
	
        set_skill("unarmed", 30);
	set_skill("dodge", 20);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5);
}
