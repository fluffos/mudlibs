// jingchengke.c

inherit NPC;

void create()
{
        set_name("京城客", ({ "jingcheng ke", "ke" }) );
        set("long","他操着满嘴的京片子，明显是从京城来的。\n");

        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 23);
        set("int", 16);
        set("con", 25);
        set("dex", 21);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("combat_exp", 40000);

        set_skill("force", 40);
        set_skill("dodge", 30);
        set_skill("unarmed", 35);
        set_skill("parry", 35);

        setup();

        carry_object(ARMOR_D("changshan"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 40);
}

