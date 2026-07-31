// toumu.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("小头目", ({ "tou mu" }) );
        set("gender", "男性");
        set("age", 27);
        set("long",     "这家伙长得高高瘦瘦，满脸狞笑，手里举着一把大片儿刀。\n");
        set("combat_exp", 700000);

	set("max_kee", 1200);
        set("max_gin", 1600);
        set("max_sen", 1600);
        set("attitude", "heroism");

	set("max_force",2000);
	set("force",2000);
	set("force_factor",50);

        set_skill("blade", 120);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
	{
		this_object()->kill_ob(ob);
        }
}
