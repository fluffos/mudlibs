
inherit NPC;

void create()
{
        set_name("五毒教女弟子", ({ "wudujiao dizi", "dizi"}));
        set("long", 
                "一个教主贴身的五毒教女弟子，功夫已有小成。\n");
        set("gender", "女性");
         set("age", 15 + random(10));
        set("attitude", "peaceful");
        set("shen", -1000);
   

        set("str", 30);
        set("int", 20);
        set("con", 24);
        set("dex", 24);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 70);
        set("combat_exp", 220000 + random(50000));

        set_skill("force", 80);
        set_skill("yinyun-ziqi", 80);
        set_skill("dodge", 80);
        set_skill("tiyunzong", 80);
        set_skill("strike", 80);
        set_skill("chousui-zhang", 80);
        set_skill("parry", 80);
        set_skill("poison", 80);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "chousui-zhang");
           prepare_skill("strike", "chousui-zhang");

        create_family("五毒教", 2, "弟子");

        setup();

        carry_object("/clone/armor/armor")->wear();
     

}

