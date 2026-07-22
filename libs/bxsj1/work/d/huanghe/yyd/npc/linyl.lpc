inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("林玉龙", ({ "lin yulong", "lin", "yulong"}));
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("unique", 1);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 10);
        set("max_qi",1200);
        set("max_jing",800);
        set("combat_exp", 600000);
        set("shen_type", 1);

        set_skill("force", 140);             // 基本内功
        set_skill("huntian-qigong", 140);    // 混天气功
        set_skill("blade", 140);             // 基本刀法
        set_skill("wuhu-duanmendao", 140);
//      set_skill("fuqi-daofa", 180);        // 夫妻刀法
        set_skill("dodge", 140);             // 基本轻功
        set_skill("xiaoyaoyou", 140);        // 逍遥游
        set_skill("parry", 140);             // 基本招架
        
        map_skill("force", "huntian-qigong");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuhu-duanmendao");
     
        setup();

        carry_object("/clone/weapon/blade")->wield();        
        carry_object(__DIR__"obj/changpao")->wear();        
        add_money("silver",10);
}

