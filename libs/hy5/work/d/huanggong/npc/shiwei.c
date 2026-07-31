// shiwei.c 带刀侍卫

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("侍卫", ({ "shi wei", "shi", "wei" }));
	set("gender", "男性");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他手握钢刀，目视前方，真是威风凛凛。\n");
	set("combat_exp", 175000);
	set("shen_type", 1);
	set("attitude", "peaceful");
    set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/armor", 150);
	set_temp("apply/damage", 130);
	set("jiali", 10);
	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	add_money("silver", random(15));
}

#include "shiwei.h"


