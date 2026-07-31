inherit NPC;
int give_work();
void create()
{
      set_name("宋缺",({"songque","jiangong","song"}));
      set("gender","男性");
      set("nickname","监工");
      set("age",40+random(40));
      set("shen_type",-1);
      set("combat_exp",300000+random(400000));
      set("str",45);
      set("per",16);
      set("inquiry",([
              "work":(:give_work:),
              "job":(:give_work:),
              "工作":(:give_work:),
      ]));
      set_skill("unarmed",115);
      set_skill("parry",115);
      set_skill("dodge",115);
      setup();
      carry_object("/clone/misc/cloth")->wear();
      add_money("gold",2);
 }
void init()
{  object ob;
    ::init();
      if (interactive(ob=this_player())&&!is_fighting())
          {   remove_call_out("greeting");
               call_out("greeting",1,ob);
           }
   add_action("do_say","say");
}
void greeting(object ob)
{   if(!ob||environment(ob)!=environment()) return;
    if (ob->query_temp("work/kan")==1) return;
       if (ob->query_temp("work/kan")==2)
             {    command("say 啊,"+ob->query("name")+"已经干完了，请用(say 干完了).\n");
                  return;
             }     
    command("say 这位"+RANK_D->query_respect(ob)+"是要找工作么，请用(ask song about work).\n");
    return;
}
int give_work()
{
    object me;
    me=this_player();
    if (!me||environment(me)!=environment()) return 0;
    if (me->query_temp("work/kan")==1)
   {    command("say 你刚才的活还没干完吧!\n");
            return 1;
       }
    if (me->query_temp("work/kan")==2)
     {        command("say 你的工钱还没领呢，我可不给你保管!\n");
               return 1;
     }
    command("say 好!你这就到西面的松林去伐木吧!\n");
    me->set_temp("work/kan",1);
    return 1;
}
int do_say(string str)
{   object ob,ob1;
     int money;
    ob=this_player();
    if (!str||str!="干完了") return 0;
    if (ob->query_temp("work/kan")!=2)
       {    command("say 想来骗钱么，哼!\n");
             return 0;
        }
    money=1+random(5);
    command("say 干得好，这是你的工钱.\n");
    ob1=clone_object("/clone/money/silver");
    ob1->set_amount(money);
    ob1->move(ob);
    message_vision("$N递给$n一些银两!\n",this_object(),ob);
    ob->delete_temp("work/kan");
    return 1;
} 