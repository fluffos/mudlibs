inherit NPC;
#include <ansi.h> 

int ask_jueji();
int ask_zd();
void create()
{
        set_name("静迦师太", ({
                "jingjia shitai",
                "jingjia",
                "shitai",
        }));
        set("long",
                "她是一位中年师太。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 70);
        set("combat_exp", 150000);
        set("score", 100);
        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("yanxing-dao", 100);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "yanxing-dao");
        prepare_skill("blade", "yanxing-dao");
        
        set("chat_chance",5);
        set("chat_msg", ({
               "静迦师太叹了口气。\n",
               "静迦师太说：“何时才有人能继承我的幻影绝技啊！”\n", 
                        }) ); 
        set("inquiry",([
             "幻影绝技" : ( : ask_jueji : ),
             "指点" : (: ask_zd :),
                 "zhidian" : (: ask_zd :),
              ]));
 
        create_family("峨嵋派", 4, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/gangdao")->wield();
}

int ask_zd()
{
    object me=this_player();
    object ob=this_object();
    object thing,user;
    object key=load_object("/d/emei/houshan/jxan");
    if (ob->is_busy()||ob->is_fighting())
    {
        command("hmm");
        return 1;
    }
    if (!me->query("emeinewbiejobdone"))
    {
        command("hmm");
        return 1;
    }
   
    if (me->query("family/family_name")!="峨嵋派")
    {
        command("hmm");
        return 1;
    }
    if (me->query("emeinewbiejobdonedone3"))
    {
        command("hmm");
        return 1;
    }
    me->set("emeinewbiejobdonedone3",1);
    thing=new(__DIR__"obj/blade");
    thing->move(me);
    message_vision("$N道：既然$N艺成下山，这柄"+thing->name()+"就交给你了，希望不令神兵蒙尘。\n",ob,me);
    return 1;
}

int ask_jueji()
{
 object me = this_player();
 if( (string)me->query("family/family_name") != "峨嵋派" )
     {
      command("say 施主与本派素无渊源，问这干吗？");
      command("? "+(string)me->query("id"));
      return 1; 
     }
  if( (int)me->query("blade") == 1 )
     {
      say("静迦师太有些发怒了。\n");
      command("say 我已经都教给你了。你还来问干什么？");
      return 1;
     }  
  else
     {
      if((int)me->query_skill("yanxing-dao",1) < 80 )
        {
         command("say 你的雁行刀法的修为太低了，无法领会我的绝技啊！");
         return 1; 
        }         
      else if((int)me->query_skill("linji-zhuang",1) < 80 )
        {
         command("say 你的临济十二庄的修为太低了，无法领会我的绝技啊！");
         return 1; 
        }  
      else 
        {
         command("smile"); 
         command("say 那我就教你幻影绝技吧。\n");
         me->set("blade",1);
         return 1;
        }  
     }    
}
