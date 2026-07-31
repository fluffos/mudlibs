// 大唐双龙传


inherit NPC;

void create()
{
  set_name("强盗", ({"qiang dao","dao"}));
  set("long","这是一个强盗。\n");
  set("gender", "男性");
  set("combat_exp",200000);

  set_skill("unarmed", 110);
  set_skill("dodge", 140);
  set_skill("parry", 130);
  
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
     command("say 很久没有生意做了，谁会是今天幸运的第一个呢？");
     break;
    case 1:
     command("say 这几天风声太紧，我还是先歇着吧！");
   }
   
}

