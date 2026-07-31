inherit NPC;
#include <ansi.h>

void create()
{
        set_name("剑宗弟子", ({ "jianzong dizi", "dizi" }) );
        set("gender", "男性");
        set("class", "swordsman");
        set("title", "华山剑宗第十四代弟子");
        set("age", 30);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 30);
        set("max_qi",10000);
        set("max_jing",10000);

        set("combat_exp", 2000000);
        set("shen", -200000);

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
              (: perform_action, "sword.feilong" :),
                (: perform_action, "sword.kuangfeng" :),
                (: perform_action, "sword.kuanglong" :),
                (: perform_action, "sword.sao" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),   
                (: exert_function, "powerup" :),
        }) );
     
        set_skill("zixia-shengong", 200);
        set_skill("unarmed", 200);
        set_skill("strike", 200);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 200);
        set_skill("kuangfeng-jian", 200);
        set_skill("huashan-neigong", 200);
        set_skill("huashan-ken", 200);
        set_skill("huashan-zhangfa", 200);
        set_skill("huashan-shenfa", 200);
        set_skill("zhengqijue",200);
        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

        create_family("华山派", 14, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
