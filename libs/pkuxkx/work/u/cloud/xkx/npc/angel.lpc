// angel.c

inherit NPC;

void create()
{
	set_name("天使",({ "angel" }) );
        set("gender", "女性" );
        set("age", 20);
        set("long", 
"这是一位可爱的天使，身着洁白无暇的绸裳，背后立着一对翅膀，正笑盈盈地看着你。\n");
        set_temp("apply/defense", 5000);
	set("combat_exp", 700000);
        set("shen", 100000);
	set("shen_type", 1);
        set("str", 24);
        set("dex", 25);
        set("con", 36);
        set("int", 35);
        set("kar",50);
        set("per",50);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/agnelcloth")->wear();
        carry_object(__DIR__"obj/angelsword")->wield();
}

