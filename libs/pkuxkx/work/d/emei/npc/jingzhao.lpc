//
//create bye cuer
inherit NPC;

int ask_jueji();

void create()
{
        set_name("静照师太", ({
                "jingzhao shitai",
                "jingzhao",
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
        set_skill("tiangang-zhi", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        set_skill("throwing",100);
        set_skill("pili-dan",100);
        map_skill("throwing","pili-dan");
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "tiangang-zhi");
        prepare_skill("finger", "tiangang-zhi");
        
        set("chat_chance",2);
        set("chat_msg", ({
               "静照师太叹了口气。\n",
               "静照师太说：“何时才有人能继承我的暗器绝技啊！”\n", 
                        }) ); 
        set("inquiry",([
             "暗器绝技" : ( : ask_jueji : ),
              ]));
 
        create_family("峨嵋派", 4, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
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
  if( (int)me->query("throwing") == 1 )
     {
      say("静照师太有些发怒了。\n");
      command("say 我已经都教给你了。你还来问干什么？");
      return 1;
     }  
  else
     {
      if((int)me->query_skill("pili-dan",1) < 80 )
        {
         command("say 你的霹雳弹的修为太低了，无法领会我的绝技啊！");
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
         command("say 那我就教你霹雳弹的弹字诀吧。\n");
         me->set("throwing",1);
         return 1;
        }  
     }    
}
