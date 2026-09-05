#include <ansi.h>
inherit NPC;

void create()
{
        set_name("千夫长", ({ "qianfu zhang","zhang"}));
        set("gender", "男性");
        set("long",  "他看起来威风凛凛，满脸杀气。\n");
        set("age", 36);
        set("attitude", "aggressive");
        set("shen", 0);
        set("str", 28);
        set("int", 20);
        set("con", 25);
        set("dex", 27);

        set("max_qi", 1400);
        set("max_jing", 1400);
        set("neili", 1400);
        set("max_neili", 1800);
        set("jiali", 100);
        set("combat_exp", 1600000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.diezhang" :),
         }));
         set_skill("force", 100);
         set_skill("xuantian-wuji", 250);
         set_skill("dodge", 220 + random(30));


        set_skill("kunlun-shenfa", 250);
        set_skill("strike", 220 + random(30));
        set_skill("kunlun-zhang", 120 + random(30));
        set_skill("parry", 200);
        set_skill("literate", 80);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "kunlun-zhang");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 80);
        prepare_skill("strike", "kunlun-zhang");

        setup();

        carry_object("/d/migong/obj/shen_dan3");
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", random(250));
}
//#include "bing.h"
