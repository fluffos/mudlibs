inherit NPC;
int about_cry();
void create()
{
     set_name("小孩子",({"xiaohai","kid","xiaohaizi"}));
     set("shen_type",1);
     set("gender","男性");
     set("age",5);
     set("combat_exp",400);
     set("str",13);
     set_skill("unarmed",13);
     set_skill("parry",10);
     set_skill("dodge",10);
     set("inquiry",([
            "cry":(:about_cry:),
            "哭":(:about_cry:),
            ]));
    set("chat_chance",3);
    set("chat_msg",({
          "小孩子偷偷地用袖口抹了抹眼泪!\n",
          "小孩子泪眼盈盈地看着你.\n",
               }));
     setup();
     carry_object("/clone/misc/cloth")->wear();
     add_money("coin",30);
  }
int about_cry()
{    object ob;
      ob=this_object();
      if (present("ren fanzi",environment(ob)))
     {message_vision("$N胆怯地看了看人贩子，低着头,不出声了!\n",ob);
         return 1;
      }
       command("say 我找不到回家的路了!\n");
       return 1;
}