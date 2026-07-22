inherit NPC;

void create()
{
        set_name("大肚虾婆", ({"xia po", "po"}));
        set_level(42);
        set("long", "一个挺着肚子走来走去的老虾婆。\n");
        set("age", 50);
        set("attitude", "peaceful");
        set("gender", "女性");
        set("per", 10);

	set("eff_dx", -2000);
	set("nkgain", 200);

        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed",420);
        set_skill("force",420);
        set_skill("spells",420);
        set_skill("dodge",420);
	set_skill("hammer",420);
	set("chat_chance", 10);
	set("chat_msg", ({	
	"大肚虾婆挺了挺肚子。\n",
	(: random_move :)
}));
        setup();
	add_money("silver", random(2)+1);
        carry_object("/d/obj/cloth/skirt")->wear();
}