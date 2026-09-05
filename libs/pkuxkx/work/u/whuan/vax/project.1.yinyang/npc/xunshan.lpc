// Npc a test for 巡山弟子 
// By bibi 

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("巡山弟子", ({"xunshan dizi" , "dizi" ,}));
        set("long",
                "这是一位峨嵋派的弟子，她负责守卫峨眉的工作。\n"
                "别看她年岁不大，但是一脸老成持重。\n"
        );

        set("gender", "女性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 400);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 400);
        set("jiaji", 50);
        set("combat_exp", 20000);
        set("score", 1);
        set("chat_chance",10);
        set("chat_msg",({(:random_move:),}));
 
        set_skill("force", 50);
        set_skill("linji-zhuang", 50);
        set_skill("dodge", 50);
        set_skill("zhutian", 50);
        set_skill("strike", 50);
        set_skill("jinding-mianzhang", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("fuliu-jian", 50);

        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("parry", "fuliu-jian");
        map_skill("sword", "fuliu-jian");
        create_family("峨嵋派",6,"弟子");
        setup();

        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (ob->query("gender")=="男性")
        {     say("巡山弟子大叫：“明年的今天就是你的祭日！”\n");
              remove_call_out("kill_ob");
              call_out("kill_ob",1,ob);     
        }
        else 
        {
              if (interactive(ob)
              // && !environment(ob)->query("no_fight")
              && (!(fam = ob->query("family")) || fam["family_name"] != "峨嵋派"))
              {
                    if( !ob->query_temp("warned") ) 
                    {                    
                          command("say 你竟敢闯到峨嵋来撒野，真是不要命了！");
                          command("say 快给我速速离开，下次看到决不轻饶！");
                          ob->set_temp("warned", 1);
                    }
                    else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                    else 
                    {
                          command("say 大胆狂徒，既然你不听警告，此地就是你的葬身之处！！\n");
                          me->set_leader(ob);
                          remove_call_out("kill_ob");
                          call_out("kill_ob", 1, ob);
                    }
              }

          } 
}
