inherit NPC;
#include "biaotou.h"
void create()
{
        set_name("镖头", ({ "biao tou" }));
        set("long", "他原是少林派弟子，后来做了镖头。");
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

        set_skill("cuff",   150);
        set_skill("sword",  150);
        set_skill("dodge",  150);
        set_skill("unarmed",150); 
        set_skill("force",  150);
        set_skill("parry",  150);
        set_skill("zixia-shengong", 120);
        set_skill("huashan-jianfa",  120);
        set_skill("huashan-shenfa",  120);

        map_skill("dodge", "huashan-shenfa");
        map_skill("force","zixia-shengong");
        map_skill("sword","huashan-jianfa");
        map_skill("parry","huashan-jianfa");

        setup(); 
        add_money("gold", 2);          
        carry_object("/clone/misc/cloth")->wear();        
       carry_object("/clone/weapon/changjian")->wield();
      }


