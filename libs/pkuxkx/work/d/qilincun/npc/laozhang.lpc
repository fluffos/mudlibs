#include <ansi.h>
inherit NPC;

void create()
{
        set_name("张老汉", ({ "zhang laohan", "zhang"}));
        set("gender", "男性");
        set("age", random(20) + 55);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "一个慈祥的老人。\n");
        set("combat_exp", 8000 + random(4000));
        set("attitude", "peaceful");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 220);

        set("max_qi", 450);
        set("eff_jingli", 400);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 30);

        set("shen_type",1);set("score",200);setup();
        carry_object("/clone/misc/cloth")->wear();
}