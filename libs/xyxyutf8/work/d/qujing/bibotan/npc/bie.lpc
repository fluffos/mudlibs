inherit NPC;

void create()
{
	set_level(45);
        set_name("古波儿西", ({"guboer xi", "xi"}));
        set("long", "他是乱石山碧波潭的老鳖精。\n");
        set("age", 30);
	set("title", "殿前右使");
        set("attitude", "peaceful");
        set("gender", "男性");
	set("class", "yaomo");
        set("per", 10);
        set("eff_dx", 20000);
        set("nkgain", 250);

        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed",450);
        set_skill("force",450);
        set_skill("spells",450);
        set_skill("dodge",450);
	set_skill("fork",450);
	set_skill("yueya-chan",450);
	map_skill("fork", "yueya-chan");
	map_skill("parry", "yueya-chan");
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}