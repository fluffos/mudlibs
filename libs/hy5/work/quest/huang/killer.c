#include <ansi.h>
inherit NPC;

int do_copy(object me,int flag);
int do_back(object me);

void create()
{
        string weapon;
        set_name("土匪", ({ "tu fei","fei"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 33);
        set("con", 36);
        set("int", 30);
        set("dex", 33);
        set("long", "一个满脸横肉的家伙。\n");
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
//        set_skill("taizu-quan", 50);
//        set_skill("qingmang-jian", 50); 
        set_skill("wind-blade", 80+random(180));
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
        
       set_skill("taiji-shengong", 50); 
        set_skill("taiji-quan", 50);
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("force","taiji-shengong");
        prepare_skill("unarmed", "taizu-quan");         
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 250);
        set_temp("apply/damage", 250);

	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :)
	}) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "blade.kuang" :),
(: perform_action, "blade.fanzhuan" :),
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
                set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        //set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/misc/cloth");
}

#include "killer.h"