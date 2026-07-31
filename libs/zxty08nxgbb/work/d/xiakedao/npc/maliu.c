// maliu.c 马六

inherit NPC;

void create()
{
        set_name("马六", ({ "ma liu", "ma" }));
        set("long",
                "他大约二十多岁，精明能干，总是阴沉着脸。但却嫉恶如仇，性如烈火。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 300);
        set("int", 35);
        set("con", 27);
        set("dex", 280);

        set("inquiry",([
            "here" : "这里当然就是侠客岛啦",
            "侠客行" : "往南面走，进山后就明白了",
            "腊八粥":"\n去找龙岛主看看你的缘分吧。\n",
                 "石破天":"\n他是我的结拜兄弟呀，他也在这呢。\n",
                 "赏善罚恶令":"\n这是我们兄弟的信物。\n",
        ]) );
        set("max_qi", 20000);
        set("qi", 20000);
        set("max_jing", 2000);
        set("jing", 2000);
        set("neili", 300000);
        set("max_neili", 3000);
        set("jiali", 1000);
        set("combat_exp", 100000000);
        set("score", 60000);

        set_skill("force", 1500);
        set_skill("taiji-shengong", 1500);
        set_skill("dodge", 1500);
        set_skill("tiyunzong", 1500);
        set_skill("unarmed", 1500);
        set_skill("taiji-quan", 2000);
        set_skill("parry", 1500);
        set_skill("sword", 1500);
        set_skill("taiji-jian", 2000);
        set_skill("taoism", 1000);
        set_skill("literate", 100);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        create_family("侠客岛", 2, "弟子");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

