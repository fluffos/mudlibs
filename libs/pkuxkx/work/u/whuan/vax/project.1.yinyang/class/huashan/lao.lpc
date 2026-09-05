// laodenuo.c 劳德诺

inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("劳德诺", ({ "lao denuo", "lao" }));
        set("long",
                "他就是岳不群的二弟子老德诺。\n"
                "他年纪比大弟子令狐冲大，只是带艺投师，只能排老二了。\n");
        set("gender", "男性");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 24);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 15000);
        set("score", 6000);

        set_skill("force", 80);
        set_skill("huashan-xinfa", 70);
        set_skill("dodge", 70);
        set_skill("huashan-shenfa", 70);
        set_skill("cuff", 40);
        set_skill("poyu-quan", 30);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("huashan-jianfa", 60);
//      set_skill("literate", 50);

        map_skill("force", "huashan-xinfa");
        map_skill("dodge", "huashan-shenfa");
        map_skill("cuff", "poyu-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        prepare_skill("cuff", "poyu-quan");

        create_family("华山派", 19, "弟子");


        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();

}

void attempt_apprentice(object ob)
{
        command("say 师傅没让我收徒。");
        return;
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (present("zixia miji", this_player()))
        {
                me->set_leader(ob);
        call_out("kill_ob", 1, this_player());
        set("shen_type", -1);
        set("jiali", 60);
        set("combat_exp", 20000);
        set("score", 6000);

        set_skill("force", 80);
        set_skill("zixia-shengong", 70);
        set_skill("dodge", 90);
        set_skill("huashan-shenfa", 80);
        set_skill("cuff", 100);
        set_skill("poyu-quan", 50);
        set_skill("parry", 90);
        set_skill("sword", 90);
        set_skill("huashan-jianfa", 80);

        map_skill("force", "zixia-shengong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("cuff", "poyu-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("cuff", "poyu-quan");

        command("say 你拿了师傅的秘籍，还想出华山，拿命来。");
        }
}
