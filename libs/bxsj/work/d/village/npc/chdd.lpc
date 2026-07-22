// NPC: /d/village/chdd.c
// Date: Look 99/07/25

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skill.h"
#include "mmr.h"
void create()
{
        set_name("采花大盗", ({ "caihua dadao", "dadao", "caihua" }) );
        set("gender", "男性");
        set("age", 18+random(15));
        set("long",
                "这家伙满脸横肉一付凶神恶煞的模样，令人望而生畏。\n");
        set("shen", -50000);
        set("attitude", "aggressive");
        set("age", random(20)+25);      

        set("str", 25+random(10));
        set("int",30+random(5));  
        set("con",30+random(5));     
        set("dex",30+random(5));
        set("combat_exp", 100000);
        set("shen_type", -1);
 	set("attitude", "peaceful");
        set("max_qi",1200);
        set("max_jing",1200);
        set("eff_jingli", 3500);
        set("neili",1000);
        set("jiali", 50);
        set("max_neili",1000);
        set("score", 10000);
        
        set_skill("force", 100); 
        set_skill("dodge", 100);
        set_skill("parry", 100);
        if (random(2))
	add_money("gold", random(5));

        setup();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}
