// tomcat

inherit __DIR__"fei.c";


void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j= 200+random(150);
        create_family("ÉÙÁÖÅÉ", 35, "µÜ×Ó"); 
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("sword",j); 
        
        me->set_skill("hunyuan-yiqi", j+random(15));
        me->set_skill("shaolin-shenfa", j+random(15));
        me->set_skill("jingang-quan", j+random(15));
        me->set_skill("damo-jian", j+random(15));

        me->map_skill("force", "hunyuan-yiqi");
        me->map_skill("unarmed", "jingang-quan");
        me->map_skill("sword", "damo-jian");
        me->map_skill("dodge", "shaolin-shenfa");
        me->map_skill("parry", "damo-jian");

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"sword.sanjue" :),
        (: exert_function, "recover" :),
        }) );        
/*
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
     
        command("wield all");
*/
    carry_object("/clone/misc/cloth")->wear();
     carry_object("/clone/weapon/changjian")->wield();
}
