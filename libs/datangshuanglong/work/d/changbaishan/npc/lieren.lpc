// 大唐双龙传


inherit NPC;

void create()
{
  set_name("猎人", ({"lie ren","ren"}));
  set("long","这是一个经验丰富的猎人。\n");
  set("gender", "男性");
  set("combat_exp",100000);

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
     command("say 嘘，小声点，我正在打猎呢！");
     break;
    case 1:
     command("say 打狼要打腰，这句话你可要记住。");
   }
   
}

