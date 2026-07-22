// modify by 
// fei-moon 神龙飞贼



inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;
       
        int j;
        j= 300+random(150);  
        create_family("明教", 34, "弟子");
        set("gender", "男性");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
    set_skill("shenlong-xinfa", j);
    set_skill("yixingbu", j);
  set_skill("shenlong-bashi", j);
    set_skill("staff", j);
set_skill("shedao-qigong", j);
map_skill("force", "shenlong-xinfa");
    map_skill("dodge", "yixingbu");
    map_skill("unarmed", "shenlong-bashi");
    map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: exert_function, "recover" :),
        }) );

/*
        if (random(2))
             weapon=new("/clone/weapon/gangzhang");
        else
           weapon=new("/clone/weapon/changjian");
        weapon->move(me);
        
        command("wield all");
*/
      carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/gangzhang")->wield();
}

