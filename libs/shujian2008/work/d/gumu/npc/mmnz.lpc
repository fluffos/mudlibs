// mmnz.c
// By River 98/09
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skill.h"
#include "mmnz.h"
void create()
{
        set_name("蒙面女子", ({ "mengmian nuzi", "mengmian", "nuzi" }) );
        set("gender", "女性");
        set("age", 25 );
        set("long", "一个风姿秀逸的女子，虽然蒙着面，但掩饰不了其咄咄的杀气。\n");
        set("combat_exp", 10000);
        set("shen", -1500);
        set("attitude", "firendly");
        set("age", 25 + random(3));      
        set("str", 10+random(10));
        set("int", 20);
        set("con", 20);
        set("dex", 10+random(10));
        set("per", 30);
        set("no_quest", 1);

        set("combat_exp", 50000);
        set("shen_type", -1);
        set("attitude", "friendly");
        set("max_qi",700);
        set("max_jing",700);
        set("neili",500);
        set("max_neili",500);
        set("score", 5000);

        
        set_skill("force", 60); 
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);

        setup();
        carry_object("/d/gumu/obj/qun1")->wear();
}
