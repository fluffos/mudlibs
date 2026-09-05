#include <ansi.h>
inherit NPC;

void create()
{
        set_name("万夫长", ({ "wangfu zhang","zhang"}));
        set("gender", "男性");
        set("long","据说他能在万兵之中取首帅的首级。\n");
        set("age", 36);
        set("attitude", "aggressive");
        set("shen", -8000);
        set("str", 28);
        set("int", 20);
        set("con", 25);
        set("dex", 27);

        set("max_qi", 2500);
        set("max_jing", 1500);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 100);
        set("combat_exp", 2200000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.diezhang" :),
         }));
         set_skill("force", 200);
         set_skill("xuantian-wuji", 290);
         set_skill("dodge", 200 + random(30));


        set_skill("kunlun-shenfa", 290);
        set_skill("strike", 260 + random(30));
        set_skill("kunlun-zhang", 270 + random(30));
        set_skill("parry", 180);
        set_skill("literate", 80);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "kunlun-zhang");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 90);
        prepare_skill("strike", "kunlun-zhang");

        setup();

        carry_object("/d/migong/obj/shen_dan4");
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", random(4));
}
