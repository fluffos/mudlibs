inherit NPC;

void create()
{
        set_name("赤身鬼使", ({"guard"}));
        set("long", "一个青面獠牙的红须赤身鬼使。\n");
        set("age",450);
	set("attitude", "heroism");
        set("gender", "男性");
        set_level(45);
        set("per", 10);

        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed",450);
        set_skill("force",450);
        set_skill("dodge",450);
	set_skill("fork",450);
	set_skill("yueya-chan",450);
	map_skill("fork", "yueya-chan");
	map_skill("parry", "yueya-chan");
        setup();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}