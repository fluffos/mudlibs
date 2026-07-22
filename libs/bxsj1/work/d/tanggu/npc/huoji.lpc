
inherit NPC;

void create()
{
	set_name("伙计", ({ "huo ji", "huoji" }));
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 20);
	set("long",
		"一个小伙计，又瘦又小。\n");
	set_skill("cuff", 20);
	set_skill("dodge", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 2000);
	set("attitude", "friendly");
		
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
}
