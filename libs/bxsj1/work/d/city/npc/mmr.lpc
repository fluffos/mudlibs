// mmr.c 蒙面人

inherit NPC;

void create()
{
	object ob;
	set_name("蒙面人", ({"mengmian ren", "mengmian", "ren"}));
	set("long", "一个莫名其妙的家伙。\n");
        set("attitude", "heroism");
        set("age", 30);
        set("shen", -2000);

        set("str", 28);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("neili", 800);
        set("max_qi", 800);
        set("max_neili", 800);
        set("jiali", 50);
        set("combat_exp", 250000);
	set("env/wimpy", 40);
        set_temp("apply/attack",  100);
        set_temp("apply/defense", 100);

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :)
        }) );

	setup();

	if (clonep()) {
		carry_object("/clone/weapon/changjian")->wield();
        	if (ob = carry_object(("/clone/misc/mask"))) ob->wear();
		carry_object("/clone/armor/shuikao")->wear();
		add_money("silver", 80);
	}
}
