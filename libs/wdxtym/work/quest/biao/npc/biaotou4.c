inherit NPC;
#include "biaotou.h"
void create()
{
        set_name("镖头", ({ "biao tou" }));
        set("long", "他原是峨嵋派弟子，后来做了镖头。");
        set("age", random(20) + 20);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);

        set("max_qi", 300);
        set("eff_qi", 300);
        set("qi", 300);
        set("max_jing", 100);
        set("jing", 100);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);

        set("combat_exp", 50000);
        set("score", 500000);
        set("shen", 0);

        set_skill("linji-zhuang", 130);
        set_skill("huifeng-jian", 130);
        set_skill("literate", 130);
        set_skill("sword", 130);
        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("force", 130);
        set_skill("anying-fuxiang", 130);

        map_skill("force", "linji-zhuang");
        map_skill("sword", "huifeng-jian");
        map_skill("parry", "huifeng-jian");
        map_skill("dodge", "anying-fuxiang");
        setup(); 
        add_money("gold", 2);        
        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();        
      }



