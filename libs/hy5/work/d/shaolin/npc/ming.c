#include <ansi.h>


inherit NPC;



void create()
{
        object ob;
        set_name("商剑鸣", ({"shang jianming", "shang", "jianming"}));
        set("gender", "男性");
        set("title", "商家堡堡主");
        set("nickname", YEL "八卦刀" NOR);
        set("age", 45);
        set("long", @LONG
这人身着长衫，身材高大魁梧，留着短须，神
情严肃，模样甚为威严。他就是山东大豪、商
家堡的现任堡主「八卦刀」商剑鸣，相传他刀
掌双绝，武功了得，在江湖上罕逢敌手。
LONG);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 45);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 17000);
        set("max_qi", 17000);
        set("jing", 17300);
        set("max_jing", 17300);
        set("neili", 27000);
        set("max_neili", 27000);
        set("jiali", 180);
        set("combat_exp", 1800000);
        set("score", 10000);

           set_skill("force", 300);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("strike", 250);
        set_skill("sword", 280);
        set_skill("blade", 280);
        set_skill("literate", 260);
        set_skill("mahayana", 500);
        set_skill("buddhism", 500);
        set_skill("jinding-zhang", 180);
        set_skill("tiangang-zhi", 180);
        set_skill("huifeng-jian", 180);
        set_skill("yanxing-dao", 180);
        set_skill("zhutian-bu", 180);
        set_skill("linji-zhuang", 180);
        set_skill("bagua-dao", 180);
        set_skill("bagua-zhang", 180);
set_skill("unarmed", 280);
        set_skill("huixin-strike", 180);
        set_skill("piaoxue-hand", 180);
        set_skill("yinlong-whip", 180);
        set_skill("yitian-jian", 180);
        set_skill("whip", 220);
        set_skill("hand", 220);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","bagua-dao");
        map_skill("parry","bagua-dao");
          map_skill("hand","piaoxue-hand");
        map_skill("strike","bagua-zhang");

        prepare_skill("strike", "bagua-zhang");

        set("class", "fighter");

        create_family("商家堡", 3, "堡主");

        set("inquiry", ([

                "胡一刀"     : "哦？听说此人刀法甚是了得，可惜我没见过他。",
                "苗人凤"     : "哼，这贼鸟厮居然敢号称天下无敌，改天一定要去会会。"
        ]));


        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "strike.ding" :),
                (: perform_action, "strike.jia" :),
                (: perform_action, "blade.feiyan" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.mang" :),
                (: perform_action, "blade.sha" :),
                (: perform_action, "blade.tian" :),                                
        }) );  

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
       
}

