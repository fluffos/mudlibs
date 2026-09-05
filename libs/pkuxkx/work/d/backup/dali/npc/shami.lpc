#include <ansi.h>
// /d/dali/shami.c
// paladin
inherit NPC;
void create()
{
        set_name("沙弥", ({ "sha mi", "sha", "mi" }));
        set("long",
                "他是天龙寺的小沙弥。\n");
        set("title",RED "天龙寺" NOR + GRN "小沙弥" NOR);
        set("gender", "男性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        set("max_qi", 200);
        set("max_jing", 150);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 3000);
        set("score", 3000);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 20);
        set_skill("parry", 30);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);
        set("times",3);
        create_family("天龙寺", 3, "弟子");
        setup();
        carry_object("/d/dali/obj/yrobe")->wear();
}




