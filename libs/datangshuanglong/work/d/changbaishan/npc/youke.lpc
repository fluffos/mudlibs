// 大唐双龙传


inherit NPC;

void create()
{
  set_name("游客", ({"you ke","ke"}));
  set("long","这是一位游客。\n");
  set("gender", "男性");
  set("combat_exp",80000);

  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  
  setup();
  carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
   object ob;
   
   ob=this_player();
   
   if(!ob||is_fighting()) return;
   
   remove_call_out("welcome");
   call_out("welcome",1,ob);
   
}

void welcome(object ob)
{
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
   
   switch(random(2)){
    case 0:
     command("say 长白山的景色真不错，没白来一次！");
     break;
    case 1:
     command("say 看，看那的风景，真是太美了。");
   }
   
}

