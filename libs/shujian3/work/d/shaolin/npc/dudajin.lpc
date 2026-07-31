//dudajin.c少林俗家弟子
//by hunthu 
#include <ansi.h>

inherit NPC;
string *names = ({"菜地种菜","服侍玄慈方丈","粥房",});


string ask_job();

void create()
{
       set_name("都大锦", ({ "du dajin","du","dajin" }));
       set("title", "多臂熊");
       set("gender", "男性");
       set("age", 45);
       set("str", 27);
       set("dex", 26);
       set("long", "这人相貌堂堂，身材魁梧，一看就知是条好汉。\n");
       set("combat_exp", 500000);
       set("shen_type", 1);
       set("attitude", "friendly");
       set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),(: perform_action, "finger.wofo" :),
        }) );

       set_skill("force", 100);
       set_skill("finger", 120);
       set_skill("yizhi-chan", 120);
       set_skill("yijin-jing", 120);
       set_skill("shaolin-shenfa", 120);
       set_skill("dodge", 100);
       set_skill("parry", 100);
      map_skill("dodge", "shaolin-shenfa");
      map_skill("parry", "yizhi-chan");
      map_skill("force", "yijin-jing");
      map_skill("finger", "yizhi-chan");
      prepare_skill("finger","yizhi-chan");
     /*  set_temp("apply/attack", 100);
       set_temp("apply/defense", 100);
       set_temp("apply/armor", 100);
       set_temp("apply/damage", 100);*/


       set("qi", 2000);
       set("max_qi", 2000);
       set("neili", 2500); 
       set("max_neili", 2500);
       set("jiali", 150);
 set("inquiry", 
                ([
                       "工作" : (: ask_job :),
                            "job" : (: ask_job :),
                    
                ]));

      create_family("少林派", 38, "弟子");
//     carry_object("/d/shaolin/obj/hui-cloth")->wear();
    setup();
}
void init()
{
        object ob;

        ::init();
       if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
//             add_action("do_task","task");
}
string ask_job()
{
        object me;
        object ob;
        string target;
        ob=this_player();
        me=this_object();
              target = names[random(sizeof(names))];
        if (ob->query_temp("job_name"))
                return ("你不是已经领了工作吗？还不快去做。\n");
            if (ob->query("combat_exp")>=30000)
                     return ("你已经有了基础了，没必要再找我来领活了。\n");
          if ((string)ob->query("class")!="bonze")
          return ("俗家弟子不能领工作。");
          ob->set_temp("job_name",target);
       //ob->apply_condition("wuguan_job",random(3)+4);
        return "做僧侣就要能吃苦耐劳，你去"+ target+ "吧。";
    }

int do_task(string arg)
{
       object ob,me;
       ob=this_player();
       me=this_object();
       if(!arg) return 0;
       if(arg!="ok") return notify_fail("哈哈哈!\n");
       if(!ob->query_temp("job_name")) 
            return notify_fail("我没给你工作，你怎么跑来覆命了？\n");
      if(!(ob->query_temp("mark/按摩完")||ob->query_temp("mark/浇完")||ob->query_temp("mark/做完")))
            return notify_fail("不能偷懒啊，干活就要认真去干! \n");
      if(arg=="ok"&&(ob->query_temp("mark/浇完")||ob->query_temp("mark/按摩完")||ob->query_temp("mark/做完")))
       { 
         command("pat "+ob->query("id"));
         command("say 好，"+RANK_D->query_respect(ob)+"，不怕吃苦，定能在寺内修成正果！\n");
         if (random((int)ob->query("kar",1))>10)
        {
         command("say 今天我就指点你几手基本武功吧。\n");                
         switch (random(4))
        {
          case 0:
          tell_object(ob,"都大锦详细的给你讲解基本轻功的诀窍，你受益匪浅。\n");
          ob->improve_skill("dodge", me->query("int")*2);
          break;
          case 1:
          tell_object(ob,"都大锦详细的给你讲解基本招架的诀窍，你受益匪浅。\n");
          ob->improve_skill("parry", me->query("int")*2);
          break;
          case 2:
          tell_object(ob,"都大锦详细的给你讲解基本内功的诀窍，你受益匪浅。\n");
          ob->improve_skill("force", me->query("int")*2);
          break;
          case 3:
          tell_object(ob,"都大锦详细的给你讲解基本指法的诀窍，你受益匪浅。\n");
          ob->improve_skill("finger", me->query("int")*2);
          break;
         } 
               }
                    ob->add("potential",(int)(ob->query_skill("buddhism",1)/5)+30);
                if(ob->query("potential") > ob->query("max_pot")) ob->set("potential", ob->query("max_pot"));
                  ob->add("combat_exp",(int)(ob->query_skill("buddhism",1)/5)+60);
             ob->delete_temp("job_name");
             ob->delete_temp("mark");
          return 1;
         }
       return 1;
    }          

void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
         
      if(ob->query_temp("job_name")) return; 
       if ((ob->query("combat_exp") < 30000)&&((string)ob->query("class")=="bonze")) {
       command("buddhi "+ob->query("id"));
       command("say 这位" + RANK_D->query_respect(ob)
                               + "，为少林寺干点活吧，可以向我要工作。"HIR"(ask du about job)"NOR"来做。\n");
       }
}                            