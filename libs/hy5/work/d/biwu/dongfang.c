// dongfang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("东方不败", ({"dongfang bubai", "dongfang", "bubai"}));
    set("nickname", HIY "天下无敌" NOR );
    set("title", HIM"日月神教教主"NOR);
    set("gender", "男性");
    set("shen_type", -1);
    set("age", 42);
    set("long",
        "他就是日月神教教主。号称无人可敌，因此有一称号为「东方不败」。\n");
    set("attitude", "peaceful");

    set("per", 121);
    set("str", 121);
    set("int", 130);
    set("con", 126);
    set("dex", 130);

    set("chat_chance", 1);
    set("chat_msg", ({
 "东方不败叹了口气道：“唉 …… 我的杨大哥....他怎么还不回来,我好\n"
 "挂念他 ……东方不败眼中流露无限迷茫。\n",
        }));
    set("inquiry", ([
        "杨莲亭"   : "你敢直称我爱人的名字,想找死呀？ \n",
        "葵花宝典" : "如果你能帮我取得葵花宝典上册，我一定重重谢你。\n",
    ]));

    set("qi", 356000);
    set("max_qi", 356000);
    set("jing", 351000);
    set("max_jing", 350000);
    set("neili", 358500);
    set("max_neili", 358500);
    set("jiali", 400);

    set("combat_exp", 19500000);
    set("score", 0);

    set_skill("force", 1250);             // 基本内功
    set_skill("finger", 1250);            // 基本指法
    set_skill("unarmed", 1250);           // 基本拳脚
    set_skill("dodge", 1250);             // 基本躲闪
    set_skill("parry", 1250);             // 基本招架
    set_skill("sword", 1250);             // 基本剑法
    set_skill("pixie-jian", 1350);        // 辟邪剑法
    set_skill("changquan", 1350);         // 太祖长拳
    set_skill("literate", 1300);          // 读书识字
    set_skill("kuihua-xinfa", 1350);      // 葵花心法
    set_skill("kuihua-dafa", 1350);      // 葵花大法
    set_skill("kuihua-feiying", 1350);      // 葵花身法
        
    map_skill("force", "kuihua-xinfa");
    map_skill("sword", "kuihua-dafa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "kuihua-feiying");
    map_skill("parry", "kuihua-dafa");
         set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
   create_family("日月神教", 2, "教主");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tonggui" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: command("unwield zhen") :),
                (: command("unwield zhen") :),
                (: command("wield zhen") :),
                (: exert_function, "powerup" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "powerup" :),                
                (: exert_function, "roar" :),                
        }) );

    setup();
    carry_object("/p/item/ritemtz3/wsword28")->wield();
    carry_object("/p/item/ritemtz3/ahands39")->wear();
    carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();

}

