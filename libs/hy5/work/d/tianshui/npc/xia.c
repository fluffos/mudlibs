// design by 发现号(find) . all right reserved.

// xia.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("夏云飞", ({ "xia yunfei","yunfei","xia" }) );
        set("gender", "男性");
        set("age", 27);
        set("long",     "这家伙长得高高瘦瘦，满脸狞笑，手里举着一把大片儿刀。\n");
	set("combat_exp", 1000000);
        set("max_kee", 1500);
        set("max_gin", 1600);
        set("max_sen", 1600);
        set("attitude", "heroism");

	set("max_force",2000);
	set("force",2000);
	set("force_factor",100);

        set_skill("blade", 500);

        set_skill("parry", 500);
        set_skill("dodge", 500);
set("combat_exp", 310000);
	set("shen_type", 1);

    set("max_neili",5500);
    set("neili",5500);
    set("qi",5500);
    set("eff_qi",5500);
    set("max_qi",5500);

    set("jing",5500);
    set("eff_jing",5500);
    set("max_jing",5500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );


        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 6);
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

void die()
{
        object killer;
        if(objectp(killer = query_temp("last_damage_from")))
            killer->set_temp("xia_killer", 1);
        ::die();
}