inherit NPC;

void create()
{
        set_name("耶律燕", ({ "yelv yan","yelv","yan" }) );
        set("gender", "女性" );
        set("age", 25);
        set("long", "她是耶律齐的师妹，功夫走灵巧的路子。\n");
        set("attitude", "friendly");
        set("str", 35);
        set("con", 30);
        set("int", 20);
        set("dex", 30);
 

        set("max_qi", 6500);
        set("max_jing", 6500);
        set("neili", 6000);
        set("eff_jingli", 6500);
        set("max_neili", 7000);
        set("jiali", 100);
         
        set("combat_exp", 1000000);

        set_skill("force", 160); 
        set_skill("strike", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("xuantian-wuji", 160);
        set_skill("literate", 160);
        set_skill("liangyi-jian", 160); 
        set_skill("taxue-wuhen", 160);
        set_skill("kunlun-zhang",160);

        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "taxue-wuhen");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "liangyi-jian");
        map_skill("sword","liangyi-jian");
        prepare_skill("strike", "kunlun-zhang");

        create_family("丐帮", 20, "弟子");

        setup();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("/d/emei/obj/changjian")->wield();         
}
