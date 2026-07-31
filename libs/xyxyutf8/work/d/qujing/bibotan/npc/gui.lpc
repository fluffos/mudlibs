inherit NPC;

void create()
{
	set_level(45);
        set_name("西波儿古", ({"xiboer gu", "gu"}));
        set("long", "他是乱石山碧波潭的老龟精。\n");
        set("age", 30);
	set("title", "殿前左使");
        set("attitude", "heroism");
	set("class", "yaomo");
        set("gender", "男性");
        set("per", 10);

        set("eff_dx", -20000);
        set("nkgain", 250);

        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 450);
        set_skill("force", 450);
        set_skill("spells", 450);
        set_skill("dodge", 450);
	set_skill("fork", 450);
	set_skill("yueya-chan", 450);
	map_skill("fork", "yueya-chan");
	map_skill("parry", "yueya-chan");
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}