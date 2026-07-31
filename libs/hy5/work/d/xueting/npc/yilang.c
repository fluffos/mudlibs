inherit NPC;

void create()
{
        set_name("柳生一郎", ({ "yi lang", "le", "liu sheng yilang" }) );
        set("gender", "男性" );
        set("title","日本浪人");
        set("age", 38);
        set("attitude", "peaceful");

        set("long", "一个满脸横肉的日本浪人。听说在京城的巡捕房打了几天零工，
学了两手功夫准备回倭国自立门派呢。 \n\n");

        set("combat_exp", 3000000);
        set("str", 60);
        set("per", 15);
        set("max_kee",3500);
        set("qi",3500);
        set("max_gin",3500);
        set("gin",3500);
        set("max_sen",3500);
        set("sen",3500);
        set("force", 5000);
        set("max_force", 5000);
        set("atman", 5000);
        set("max_atman", 5000);
        set("mana", 5000);
        set("max_mana", 5000);
        set("force_factor", 300);

        set_skill("literate",300);
        set_skill("unarmed",260);
        set_skill("dodge",280);
        set_skill("parry",280);
        set_skill("force",300);
        set_skill("sword",300);



	set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.changen" :),
                "柳生一郎喝道：还不快放下武器束手就缚？\n",
                "柳生一郎喝道：无知懦夫居然真敢和我比试？反了！反了！\n"
        }) );
        
        set("chat_chance", 7);
        set("chat_msg", ({
        "柳生一郎傲慢的对你说道：懦夫，敢和我比试一下吗？ \n",
        }) );
        set("inquiry", ([
              "日本" : "嘿嘿，羡慕我们，那就带上你的花姑娘跟我走...",      
              "倭寇" : "八噶，看来你是活腻了。", ]) );



        setup();
        add_money("silver", 290);
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

}
