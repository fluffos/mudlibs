inherit NPC;
int ask_job();
void consider();

void create()
{
        set_name("武敦儒", ({ "wu dunru","wu","dunru" }) );
        set("gender", "男性" );
        set("age", 28);
        set("long", "身材健壮，浓浓的眉毛，一副精神饱满的样子。\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("con", 30);
        set("int", 20);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
         
        set("combat_exp", 1000000);

        set_skill("force", 160); 
        set_skill("hand", 160);
        set_skill("blade", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("huntian-qigong", 160);
        set_skill("literate", 160);
        set_skill("suohou-shou", 160); 
        set_skill("liuhe-daofa", 160);
        set_skill("xiaoyaoyou", 160);
        

        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("blade","liuhe-daofa");
        map_skill("hand", "suohou-shou");
        map_skill("parry", "liuhe-daofa");
        prepare_skill("hand", "suohou-shou");

        set("inquiry", ([
                "守城": (: ask_job :),
        ]) );

        create_family("丐帮", 19, "挂名弟子");

        setup();
        carry_object("/d/city/bqp_obj/blade")->wield();
        carry_object("/d/city/obj/cloth")->wear();
         
}

int ask_job()
{
       object me = this_player();
       if (!me->query_temp("xy/job"))
       {
               command("say 请先向我师父请示。");
               return 1;
       }
      if (me->query("family/family_name") != "古墓派")
      {
               command("say 你快去指定的地点吧，看来蒙古兵就要攻城了！");
               return 1;
      }
      command("say 小心了。");
      command("addoil " + me->query("id"));
      me->set_temp("xy/job",2);
      return 1;
}
