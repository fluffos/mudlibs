// yiren.c 艺人

inherit NPC;

void create()
{
        string gender;

        set_name("江湖艺人", ({ "yi ren", "yiren" }));
        gender = random(2)?"男性":"女性";
	set("gender", gender);
        set("age", 23+random(10));
        set("long", "一个走南闯北的江湖艺人。\n");

	set("combat_exp", 7000);
        set("shen_type", 0);
	set("attitude", "peaceful");

	set_skill("unarmed", 25);
	set_skill("dodge", 25);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 10);
}