// wujiang.c 武将
inherit NPC;
void create()
{
        set_name("边防武将", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 35);
        set("int", 19);
        set("con", 30);
        set("dex", 20);
        set("long", "他是这里的副将。\n");
        set("combat_exp", 80000);
        set("attitude", "peaceful");
        set_skill("unarmed", 55);
        set_skill("force", 55);
        set_skill("sword", 55);
        set_skill("dodge", 55);
        set_skill("parry", 55);
        set_temp("apply/attack", 55);
        set_temp("apply/damage", 30);
        set("jiali", 10);
        setup();
        carry_object(BINGQI_D("gangjian"))->wield();
        carry_object(ARMOR_D("armor"))->wear();        
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && living(this_object()) &&
            (ob->query_condition("killer") || ob->query_temp("xx_rob"))) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 0, ob);
        }
}

int accept_fight(object me)
{
        command("say 大爷我守边关累得要死，没空和"+RANK_D->query_respect(me)+"过招玩。\n");
        return 0;
}

int accept_object(object me, object obj)
{      
      int j;      
      if(obj->query("money_id")){
        if(obj->value() >= 5000){
           j = obj->value()/5000;
           command("nod " + me->query("id"));
           me->add("guanbing", j);
           return 1;
           }
        else{
           command("say 才这么点？");
           return 1;
           }
        }
      command("hmm " + me->query("id"));
      command("say 我对"+obj->name()+"不稀罕。");
      return 0;
}

