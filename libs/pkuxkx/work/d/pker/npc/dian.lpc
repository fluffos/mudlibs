// 雷

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("涟电杀手", ({ "dian",}));
	set("str", 20);
	set("gender", "男性");
	set("age", 20);
	set("long", "杀手帮涟电杀手，是杀手帮低级杀手的一种\n");
	set("combat_exp", 450000);

    set("max_neili",851);
    set("max_jingli",400);
    set("max_jing",470);
    set("max_qi",600);
    set("neili",851);
    set("jingli",400);
    set("jing",470);
    set("qi",600);

    set_skill("parry",160);
    set_skill("unarmed",170);
    set_skill("sword",170);
    set_skill("dodge",170);
    set_temp("apply/attack",  90);
	set_temp("apply/defense", 90);
        
	set("attitude", "friendly");
	set("shen_type",-1);
    set("score",1000);
    setup();
	carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
        
}

