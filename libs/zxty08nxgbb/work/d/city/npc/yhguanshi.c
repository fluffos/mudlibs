#include <ansi.h>
#include <login.h> 
inherit NPC;


void create()
{
     //  reload("guanshi");
       set_name("客服MM", ({"kefu mm","mm"}));
       set("gender", "女性");
       set("title", HIC"天涯客服"NOR);
       set("combat_exp", 100000);
       set("age", 26);
       set("per", 24);
       set("attitude", "friendly");
       set("long","客服MM天涯第一界选美大会冠军，\n后来被巫师所赏识，提为天涯客服。\n");
       set("shen_type", 1);
      
       set("max_qi", 1100);
       set("max_jing", 1100);
       set("qi", 1100);
       set("jing", 1100);
       set("neili", 2300);
       set("max_neili", 1200);
       set("jiali", 80);
       set("max_jingli", 1200);
       set("jingli", 2300);
       set("combat_exp", 800000);

       set_skill("literate", 500);
       set_skill("unarmed", 500);
       set_skill("dodge", 500);
       set_skill("parry", 500);

       
       setup();


}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 12);
        set("inquiry", ([
                "here" : "这是由天涯MUD所开的VIP潜能银行。\n",

   ]) );


      
    ob = this_player();
    ::init();
    if (userp(ob))
    if(random(10)>3)
       remove_call_out("greeting");
       call_out("greeting", 1, ob);
}

void accept_kill(object me)
{       

        me->add("daoluan",1);
        command("sigh2");
        command("chat 救命啊！");
          
        me->add("daoluan",1);
        me->save();
        return;

}

void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
if(!userp(ob)) return;
message_vision( "$N对$n抱拳行礼.\n\n",this_object(),ob );
if(ob->query("id")=="yuchang")
  {
          command("say 噢，"+ob->query("name")+"公子,您回来了。");
  }
else
  {
command("say 这位" + RANK_D->query_respect(ob)
+ "，又要出去冒险，所以来存潜能吧？\n");
if (ob->query("gender") == "女性"||ob->query("gender") == "无性")
    {
        command("say "+"这位" + RANK_D->query_respect(ob)+"，欢迎你有空来坐坐。");
        command("xixi");
    }
else
    {
        command("say 平常总是有美女来我这，不想今日却来了一位" + RANK_D->query_respect(ob)+"\n");
        command("say 看来我下辈子的幸福有望了！\n"); 
        command("grin");
    }
  }
}

