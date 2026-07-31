inherit NPC;

void create()
{
        set_name("萧升", ({ "xiao sheng", "xiao" }));
        set("title","振远镖局总镖头");
        set("gender", "男性");
        set_level(37);
        set("age", 35);
        set("long",
                "他就是振远镖局现在的当家－－萧升。
他不但武艺高强，而且为人豪侠仗义。 \n");

        set("combat_exp", 100000);
	set("str", 25);
        set_skill("sword", 170);
        set_skill("unarmed", 170);
        set_skill("dodge", 170);
        set_skill("parry", 170);
	set_skill("fonxansword", 150);
	set_skill("yanxing-steps", 150);
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "yanxing-steps");
	set("force_factor", 10);
        setup();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"sword",random(2))->wield();
}

