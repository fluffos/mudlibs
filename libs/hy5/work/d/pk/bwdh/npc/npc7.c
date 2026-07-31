// miejue.c 灭绝师太
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("小灭绝师太", ({ "miejue shitai","miejue","shitai"}));
        set("long",
                "她是峨嵋派的第三代弟子，现任峨嵋派掌门人。\n");
        set("gender", "女性");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 100000);
        set("class", "bonze");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) );
        set("inquiry",([
                "剃度"  : "贫尼只知除妖杀魔，不剃度弟子。",
                "出家"  : "贫尼只知除妖杀魔，不剃度弟子。",
        ]));

        set("str", 40);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        set("per", 20);

        set("max_qi", 8000);
        set("max_jing", 8000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 2500000);
        set("score", 1000);
        set_skill("persuading", 300);
        set_skill("throwing", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("finger", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("sword", 250);
        set_skill("blade", 200);
        set_skill("literate", 160);
        set_skill("mahayana", 300);
        set_skill("buddhism", 300);
        set_skill("jinding-zhang", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("huifeng-jian", 300);
        set_skill("yanxing-dao", 300);
        set_skill("zhutian-bu", 300);
        set_skill("linji-zhuang", 300);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        prepare_skill("strike", "jinding-zhang");
//        map_skill("magic","bashi-shentong");
        create_family("峨嵋派", 3, "掌门人");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
        carry_object(__DIR__"obj/badan");

}


