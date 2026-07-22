// /u/beyond/mr/npc/yan.c
// this is made by beyond
// update 1997.7.1
#include <ansi.h>
inherit NPC;

string ask_job();

void create()
{
        set_name("严妈妈", ({ "yan mama", "mam", "yan" }));
        set("gender", "女性");
        set("age", 50);      
	set("title",BLU	"花肥房管事"NOR);
	set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
set("no_get","你没办法拿起这个人");
        set("neili",1000);
        set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

        set_skill("cuff", 70);
	set_skill("parry",70);
	set_skill("yanling-shenfa",70);
        set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);
        set_skill("blade",70);
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object(__DIR__"obj/blade")->wield();
        set("inquiry", ([
            "name" : "我是曼佗罗山庄的花房管事。\n",
            "here" : "这里是花肥房，专门把夫人让处死的人做花肥。\n",
            "rumors" : "最近一个姓段的小子从我手里跑了。\n",
            "工具" : (: ask_job :),
        
 ]));           
}
void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && ( (fam = ob->query("family")) && fam["family_name"] != "姑苏慕容" ) )
        {
                        command("say 近来花肥不太够，让老婆子我拿你做花肥吧！！！\n");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}


string ask_job()
{
	object me = this_player();
	object ob = this_object();
	object tools1;
	mapping fam;
	
	if (!(fam = me->query("family")) || fam["family_name"] != "姑苏慕容") // 必须是慕容派弟子
               return RANK_D->query_respect(me) +
               "与本派素无来往，不知此话从何谈起？";               
            
        if ((int)me->query_temp("yanpopo")==2 )
               return "你不是已经领了工具么，还不快去做！\n";
       
        me->set_temp("yanpopo",2);
        
        tools1 = new(BINGQI_D("piao"));
        tools1->move(me);
       
        
        message_vision("$N交给$n一件工具。\n", ob, me); 
        
        me->add_temp("mark/次",0);
        
        return "快去给庄里的茶花浇浇水！\n";
}

int accept_object(object me, object obj)
{
      object ob;
      me=this_object();
      ob=this_player();
      
      if(!ob->query_temp("mrhua")){  
              command("consider " + ob->query("id"));
              command("say 你没有接任务呀，是不是要利用bug？");
              return 0;
      }
      if (!(int)ob->query_condition("mrhua_job"))
      {
            command("disapp");		
      	    command("say 你时间已过，任务失败。\n");
      	    ob->delete_temp("mrhua");      	    
      	    return 0;
      }
      if(!ob->query_temp("mark/ok"))
      {
              command("say 你还没完成工作，怎么就回来还工具了，偷懒吗？");
	      return 0;
      }
      if (obj->query("id")!="piao")
      {
              command("say 你还错东西了吧，我从没有发过这样工具。");
              return 0;
      }
     
     command("kiss " + ob->query("id"));
     command("say 不错，去找王夫人要赏钱吧");
     ob->set_temp("mark/还了",1);
     ob->delete_temp("mark/ok");
     call_out("destroying", 1, me, obj);           
     return 1;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}