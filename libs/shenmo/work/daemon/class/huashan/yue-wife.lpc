//yue-wife.c    changed by cocacola on 2.19.1997 Just for adding Chushi
// 岳夫人
inherit NPC;
inherit F_MASTER;
/*
mixed out_master(mixed arg);
mixed out_master(mixed arg)
{
   object me;
   me = this_player();
   if( (string)me->query("family/family_name")!="华山派")
   {
         tell_object(me,"岳夫人疑惑地对你说:我好象在哪见过你似的!\n");
         return 1;
   }
   if(me->query("gender")!="女性")
   {
         tell_object(me,"这位小兄弟,你是我丈夫的徒弟,想出师当去找他才是!\n");
         return 1;
   }
   if(me->query("combat_exp") <= 100000) 
   {
         tell_object(me,"岳夫人对"+me->query("name")+"笑道:小姑娘,功夫还没学到家就想出去丢脸.\n");
         return 1;
   }
   tell_object(me,"岳夫人沉吟了一会,对"+me->query("name")+"说道:要想出师,
          你必须接我三招不死(accept test).\n");
   add_action("do_accept","accept");
   return 1;
}

int do_accept(string arg)
{
   mapping guild;

   if( arg== "test" ) 
   {
          say("\n岳夫人点了点头，说道：很好，小心了　，这是第一招....\n\n");
          COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
          if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment()))
          {
               say("岳夫人叹了口气，说道:连第一招都撑不过，真是自不量力....\n");
               return 1;
          }
          say("\n岳夫人道：第二招....\n\n");
          COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
          if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment())) 
          {
               say("岳夫人叹道：这样子还想出师,唉.....\n");
               return 1;
          }
          say("\n岳夫人道：第三招可没那么容易,你可要小心了!....\n\n");
          COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
          if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment())) 
          {
               say("岳夫人叹道:唉,就差一点点了,继续努力吧!.\n");
               return 1;
          }
          say("\n岳夫人微笑着道：恭喜,你出师了.你我师徒一场，为师没什么好送的 .
          \n就送你八字真言吧:天外有天,人外有人!徒儿,喔,不...大侠你好自为知.\n\n");
          this_player()->set("betrayer",this_player()->query("betrayer")-1);
          this_player()->set("title","隐士");
          this_player()->set("family/family_name","华山派");
          this_player()->set("family/generation",13);
          this_player()->set("family/master_name",0);
          command("chat " + this_player()->query("name")+"已脱离华山，日后一切江湖
           恩怨均与本派无关.\n");
          return 1;
   }
   return 0;
}
*/
void create()
{
        set_name("岳夫人", ({ "yue wife", "ning", "ning zhongze" }) );
        set("nickname", "淑女剑");
        set("gender", "女性");
        set("class", "swordsman");
        set("age", 50);
        set("long",
                "岳夫人原姓宁，闺名宁中则，是岳不群的师妹，也是他的妻子。\n");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 26);
        set("per", 26);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

        set("neili", 24000);
        set("max_neili", 22400);
        set("jiali", 30);

        set("max_qi",12000);
        set("max_jing",11000);
        set("combat_exp", 3000000);
        set("shen", 200000);

        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.ai" :),
(: perform_action, "parry.wushuang" :),	
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
/*
        set("inquiry", ([
            "出师": (: out_master :),
        ]) );
*/
        set_skill("unarmed", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
         set_skill("chongling-jian", 380);
        set_skill("huashan-sword", 200);
        set_skill("yunu-sword", 380);
        set_skill("zixia-shengong", 320);
        set_skill("huashan-ken", 200);
        set_skill("feiyan-huixiang", 200);
        set_skill("zhengqijue", 200);

        map_skill("sword", "chongling-jian");
        map_skill("parry", "yunu-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("华山派", 13, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 今天好累哟。");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "女性" ){
                 command("say 这位"+RANK_D->query_respect(ob)+
"你还是找我夫君去吧.");
        }else {
        command("say 微笑道：好，好，只要你用心学，他日必有成就。");
        command("recruit " + ob->query("id") );
   }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
        add("apprentice_availavble", -1);
}
void reset()
{
//        delete_temp("learned");
        set("apprentice_available", 3);
}
