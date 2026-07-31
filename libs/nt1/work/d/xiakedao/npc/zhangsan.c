// zhang.c 张三

inherit NPC;

void create()
{
        set_name("张三", ({ "zhang san", "zhang" }));
        set("nickname", "侠客岛赏善罚恶使者");
        set("title", "笑面佛");
        set("long",
                "他就是江湖传闻中赏善罚恶使者之一。\n"
                "他大约二十多岁，精明能干，笑嘻嘻的和蔼可亲。但却嫉恶如仇，性如烈火。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 35);
        set("con", 27);
        set("dex", 28);

        set("liquiry", ([
                 "腊八粥":"\n去找龙岛主看看你的缘分吧。\n",
                 "石破天":"\n他是我的结拜兄弟呀，他也在这呢。\n",
                 "赏善罚恶令":"\n这是我们兄弟的信物。\n",
        ]) );

        set("max_qi", 2000);
        set("qi", 2000);
        set("max_jing", 2000);
        set("jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 3000000);
        set("score", 60000);

        set_skill("force", 150);
        set_skill("taiji-shengong", 150);
        set_skill("dodge", 150);
        set_skill("tiyunzong", 150);
        set_skill("unarmed", 150);
        set_skill("taiji-quan", 200);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 100);
        set_skill("literate", 100);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

