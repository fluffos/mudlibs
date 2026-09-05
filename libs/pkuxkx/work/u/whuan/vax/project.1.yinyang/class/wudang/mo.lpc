#include <ansi.h>
// yu.c ，莫声谷

inherit NPC;
inherit F_MASTER;

void heal();

void create()
{
        set_name("莫声谷", ({ "mo shenggu", "mo" }));
       set("nickname", RED "武当七侠" NOR);
        set("long",
                "这是武当七侠中最小的莫声谷，\n"
                "他生的浓眉方脸，一副疾恶如仇的样子，令人不敢逼视。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

/*        set("chat_chance_combat", 100);
//        set("chat_msg_combat", ({
//                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );*/

        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 400000);
        set("score", 150000);

        set_skill("force", 120);
        set_skill("yinyun-ziqi", 120);
        set_skill("dodge", 80);
        set_skill("tiyunzong", 80);
        set_skill("cuff", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("taiji-jian", 120);
//        set_skill("taoism", 150);
//        set_skill("literate", 120);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}
