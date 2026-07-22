// 大唐双龙传


inherit NPC;

void create()
{
  set_name("二楞子", ({"er lengzi","lengzi"}));
  set("long","这是一个傻呼呼的家伙。\n");
  set("gender", "男性");
  set("combat_exp",10000);

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
     command("say 都说俺长的帅，咋没大姑娘喜欢俺呢？");
     break;
    case 1:
     command("say 其实我一点也不愣，头脑聪明得紧。");
   }
   
}

