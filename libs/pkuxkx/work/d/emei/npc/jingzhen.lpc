//
//create bye cuer
inherit NPC;

int ask_jueji();

void create()
{
        set_name("静真师太", ({
                "jingzhen shitai",
                "jingzhen",
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
        set_skill("jinding-mianzhang", 100);
        set_skill("strike", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("parry", "jinding-mianzhang");
        prepare_skill("strike", "jinding-mianzhang");
                          
        set("chat_chance",5);
        set("chat_msg", ({
               "静真师太叹了口气。\n",
               "静真师太说：“何时才有人能继承我的绵掌绝技啊！”\n", 
                        }) ); 
        set("inquiry",([
             "绵掌绝技" : ( : ask_jueji : ),
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
  if( (int)me->query("strike") == 1 )
     {
      say("静真师太有些发怒了。\n");
      command("say 我已经都教给你了。你还来问干什么？");
      return 1;
     }  
  else
     {
      if((int)me->query_skill("jinding-mianzhang",1) < 80 )
        {
         command("say 你的金顶绵掌的修为太低了，无法领会我的绝技啊！");
         return 1; 
        }         
      else if((int)me->query_skill("tiangang-zhi",1) < 80 )
        {
         command("say 你的天罡指的修为太低了，无法领会我的绝技啊！");
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
         command("say 那我就教你绵掌绝技吧。\n");
         me->set("strike",1);
         return 1;
        }  
     }    
}
