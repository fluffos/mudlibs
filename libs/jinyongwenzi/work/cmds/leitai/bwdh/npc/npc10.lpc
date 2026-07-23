// modified by explorer, 3/9/97
inherit NPC;
void create()
{
        set_name("小洪七公", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "九指神丐");
        set("gender", "男性");
        set("age", 75);
        set("long", 
                "他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
        set("attitude", "friendly");
        set("str", 40);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("eff_jingli", 1000);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 400000);    
        set("unique", 1);
         
        set_skill("force", 100);             // 基本内功
        set_skill("huntian-qigong", 100);    // 混天气功
        set_skill("strike", 100);            // 基本掌法
        set_skill("xianglong-zhang", 100);   // 降龙十八掌
        set_skill("dodge", 100);             // 基本躲闪
        set_skill("xiaoyaoyou", 100);        // 逍遥游
        set_skill("parry", 100);             // 基本招架
        set_skill("stick", 100);             // 基本棍杖
        set_skill("dagou-bang", 100);        // 打狗棒法
        set_skill("begging", 100);           // 叫化绝活
        set_skill("checking", 100);          // 道听途说
        set_skill("bangjue",100);            // 棒决  

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("stick", "dagou-bang");
        prepare_skill("strike", "xianglong-zhang");  

        create_family("丐帮", 17, "帮主");
        setup();

        carry_object(__DIR__"obj/yzb")->wield();
        carry_object("/d/gb/npc/obj/jiaohuaji");
        carry_object("/d/gb/npc/obj/bainayi")->wear();
        carry_object("/d/gb/npc/obj/gb_budai10")->wear();
        carry_object("/clone/medicine/badan");
}
