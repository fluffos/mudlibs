// yayi.c  官府衙役
inherit NPC;

void create()
{
	set_name("衙役", ({ "ya yi", "ya" }));
	set("gender", "男性");
	set("age", 25);

	set("long", "一个高大威猛的汉子，因为久在官府做事，脸上已经磨炼得毫无表情。\n");
	set("combat_exp", 7500);
	set("shen_type", 1);
	set("combat_exp", 81000);
	set("shen_type", 1);

    set("max_neili",500);
    set("neili",500);
    set("qi",500);
    set("eff_qi",500);
    set("max_qi",500);

    set("jing",500);
    set("eff_jing",500);
    set("max_jing",500);
        set_skill("force", 80+random(80));

        set_skill("unarmed", 80+random(80));
        set_skill("blade", 80+random(80));
        set_skill("parry", 80+random(80));
        set_skill("dodge", 80+random(80));
        set_skill("kuang-blade", 80+random(80));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");

	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
	set("chat_msg_combat", ({
		"衙役说道：你当这里是什么地方，敢来这里骚扰？\n",
		"衙役说道：你要是再无理取闹，当心捕头把你抓去坐牢!\n",
		"衙役手中的刀越砍越快，让你应接不暇。\n",
		"衙役说道：衙门岂是你放肆的地方？！\n"
	}) );
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/yayifu")->wear();
}
	
