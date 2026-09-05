// 雷

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("擎雷杀手", ({ "lei",}));
	set("str", 20);
	set("gender", "男性");
	set("age", 20);
	set("long", "杀手帮擎雷杀手，是杀手帮低级杀手的一种\n");
    set("combat_exp", 250000);

    set("max_neili",801);
    set("max_jingli",300);
    set("max_jing",370);
    set("max_qi",400);
    set("neili",801);
    set("jingli",300);
    set("jing",370);
    set("qi",400);

    set_skill("force",120);
    set_skill("parry",120);
    set_skill("unarmed",120);
    set_skill("sword",120);
    set_skill("dodge",120);
    set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set("attitude", "friendly");
	set("shen_type",-1);
set("score",1000);
setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        
}

