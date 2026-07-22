// wujiang.c 武将
inherit NPC;
void create()
{
        set_name("少帅军将领", ({ "jiang ling", "jiang", "ling" }));
        set("gender", "男性");
        set("age", random(10) + 30);
	set_level(35);
        set("long", "他威风凛凛，杀气腾腾，虽然只是个守城门的小官，当年也是打过大仗的。\n");
        set("attitude", "peaceful");

        set_skill("unarmed",350);
        set_skill("force",350);
        set_skill("sword",350);
        set_skill("dodge",350);
        set_skill("parry",350);
        set("force_factor", 15);
	set("mana_factor", 5);
        setup();
        carry_object(0,"sword",random(2))->wield();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"armor",random(2))->wear();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        powerup(1,1);
}
