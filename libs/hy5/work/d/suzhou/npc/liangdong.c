 inherit NPC;

void create()
{
       set_name("赵良栋", ({ "zhao liangdong", "zhao" }));
       set("title", "苏州守将");
       set("gender", "男性");
       set("age", 33);
       set("str", 25);
       set("dex", 16);
       set("long", "赵良栋因为连年征战有功，新近被升官调任苏州。他生得一脸络腮胡子，很是骁勇。\n");
            set("combat_exp", 450000);
       set("shen_type", 1);
       set("attitude", "heroism");
       set("inquiry", ([
                "韦小宝" : "多亏韦爵爷给下官提携，下官感激不尽。\n",
                "韦爵爷" : "多亏韦爵爷给下官提携，下官感激不尽。\n",
        ]));

       set_skill("unarmed", 100);
       set_skill("force", 100);
       set_skill("sword", 100);
       set_skill("dodge", 100);
       set_skill("parry", 100);
       set_skill("taiji-jian", 80);
        set_skill("tiyunzong", 80);
        set_skill("taiji-shengong", 80);
        map_skill("force", "taiji-shengong");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        map_skill("dodge", "tiyunzong");
        set_temp("apply/attack", 90);
        set_temp("apply/defense", 90);
        set_temp("apply/armor", 90);
        set_temp("apply/damage", 40);
       

       set("max_qi", 1700);
       set("qi", 1700);
       set("neili", 2000); 
       set("max_neili", 2000);
       set("jiali", 30);

       setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/armor/cloth")->wear();
}

int accept_fight(object me)
{
       command("say 老夫久未和江湖人动手过招了，今日也不想破例。");
       return 0;
}

void init()
{
       object ob;
       ::init();
       if (interactive(ob = this_player()) && living(this_object()) &&
               (int)ob->query_condition("killer")) {
               remove_call_out("kill_ob");
               call_out("kill_ob", 0, ob);
       }
}

