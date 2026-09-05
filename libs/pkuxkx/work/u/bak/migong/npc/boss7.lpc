#include <ansi.h>
inherit NPC;

void create()
{
        set_name("拓雷", ({ "tuo lei","tuo"}));
        set("gender", "男性");
        set("long", "他就是名闻天下的大侠郭靖的结义兄弟，如今的蒙古军的总元帅。\n");
        set("age", 36);
        set("attitude", "aggressive");
        set("shen", -8000);
        set("str", 28);
        set("int", 20);
        set("con", 25);
        set("dex", 27);

        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 4000000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: perform_action, "strike.diezhang" :),
       }));
         set_skill("force", 400);
        set_skill("xuantian-wuji", 400);
         set_skill("dodge", 400 + random(30));


        set_skill("kunlun-shenfa", 400);
        set_skill("strike", 380 + random(30));
        set_skill("kunlun-zhang", 380 + random(30));
        set_skill("parry", 370);
        set_skill("literate", 80);
        map_skill("force", "xuantian-wuji");
         map_skill("dodge", "kunlun-shnfa");
          map_skill("strike", "kunlun-zhang");
          map_skill("parry", "kunlun-zhang");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 200);
        prepare_skill("strike", "kunlun-zhang");

        setup();

       carry_object("/d/migong/obj/shen_dan7");
       carry_object("/clone/misc/cloth")->wear();
       add_money("gold", 20);
}
