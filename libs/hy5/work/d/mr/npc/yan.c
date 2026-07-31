// /u/beyond/mr/npc/yan.c
// this is made by beyond
// update 1997.7.1
#include <ansi.h>
int give_tools();
inherit NPC;

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
                         "工具" : (: give_tools :),
                         "tools" : (: give_tools :),
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
int give_tools()
{
       object tools,ob,me;
       me = this_object();
       ob = this_player();
       if( !ob->query_temp("mr_job")){
          say (CYN"严妈妈说道：你没跟王夫人说过，跑来要什么工具。\n"NOR);
          return 1;
          } 
       if(ob->query_temp("mark/工具")){
          say (CYN"严妈妈说道：你先把工具还了，再领工具吧。\n"NOR);
          return 1;
          } 
       if(ob->query_temp("mark/还了")){
          say (CYN"严妈妈说道：你还没覆命(task ok)领新活吧，跑来要什么工具。\n"NOR);             
          return 1;
          }  
          say(CYN"严妈妈说道：既然你已经领了活，我就给你这把工具，小心保管，别弄丢了。\n"NOR);
          message_vision("$N交给$n一把工具。\n", me, ob);
       if(ob->query_temp("mr_job")=="浇花"){
         tools = new(__DIR__"obj/shuihu");
         tools->move(this_player());
         say(CYN"严妈妈说道：我们这有很多花，你去花丛中中浇浇花吧(jiaoshui hua)。\n"NOR);
          say(CYN"严妈妈说道：干完活后，先来我这还工具，再去告诉王夫人(task ok)。\n"NOR);
        ob->set_temp("mark/工具",1);
        return 1;
}
}

int accept_object(object me, object obj)
{
      object ob;
      me=this_object();
      ob=this_player();
     if(!(ob->query_temp("mark/浇完")))
        {
        say(CYN"严妈妈说：你还没完成工作，怎么就回来还工具了，偷懒吗？\n"NOR);
                 return 1;
              } 
     if (obj->query("id")!="shui hu")            
        {  
        command("say 你还错东西了吧，我从没有发过这样工具。\n");
                 return 1;
              }
               command("nod");
               command("say 干得不错，王夫人会高兴的!");
               ob->set_temp("mark/还了",1); 
               call_out("destroying", 1, me, obj);           
               return 1;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
