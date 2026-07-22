// /d/city/npc/yanxiao2.c 盐枭

inherit NPC;

void create()
{
        set_name("盐枭老者", ({ "yan xiao", "yanxiao"}));
	set("gender", "男性");
        set("age", 50);
        set("long", "短装结束，白布包头，青带缠腰手中拿着铁棍。\n");

        set("combat_exp", 24000);
	set("shen_type", -1);
	set("attitude", "peaceful");

        set_skill("dodge", 55);
        set_skill("staff", 60);
        set_skill("unarmed", 50);
        set_temp("apply/attack", 25);
	set_temp("apply/defense", 20);

	setup();
        carry_object(__DIR__"obj/tiegun")->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 20+random(10));
}
