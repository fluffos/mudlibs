// smith.c

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("ÁõÌú", ({ "liu tie" }) );
        set("gender", "ÄĞĞÔ" );
        set("age", 38);
	set("str",88);
        set("long", "ÌúÆ÷×÷·»ÀÏ°åÁõÌú¡£\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);

	//set_weapon_ability(({"blade", "axe"}));
	//set_ability_level(10);

        setup();

	carry_object("/clone/misc/cloth")->wear();
}