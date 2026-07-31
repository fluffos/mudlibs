#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("断肠人", ({ "duanchang ren","ren" }) );
        set("gender", "男性" );
        set("long",
                "一个四处漂泊，无家可归的落魄人。\n"
                );
        set("title", WHT"天涯孤旅"NOR);
        set("attitude", "peaceful");
    set("age", 25);
        set("str", 10);
        set("cor", 18);
        set("agi", 20);
        set("per", 20);
        set("combat_exp", 20000);
        set("max_qi", 900);
        set("max_gin", 700);
        set("max_sen", 700);
        set("max_force", 400);
        set("force", 500);
        set("force_factor", 10);
        set_temp("apply/damage", 50); 
        set("chat_chance", 1);
        set("chat_msg", ({
                "断肠客喃喃吟道：枯藤老树昏鸦, 小桥流水人家, 古道西风瘦马.夕阳西下，\n断肠人在天涯。。好一个断肠人在天涯。。\n",
                }) ); 
        set_skill("unarmed", 80);
        set_skill("parry", 100);
        set_skill("dodge", 300);
    set_skill("doomforce", 10);
    set_skill("doomstrike", 10);
    set_skill("doomsteps", 20);
    map_skill("unarmed", "doomstrike");
    map_skill("dodge", "doomsteps");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}    
