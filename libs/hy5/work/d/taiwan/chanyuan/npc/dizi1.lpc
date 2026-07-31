
inherit NPC;

string *names=({
"净","jing",
"念","nian",
"空","kong",
"缘","yuan",
"无","wu",
"智","zhi",
"慧","hui",
"明","ming",
"欲","yu",
});

int do_jiangjing(string arg);
int do_hua(string arg);

void create()
{
   int i,j;
   i=random(sizeof(names));
   
   if(i%2!=0) i--;
   j=i+1;
   
   set_name("虚"+names[i],({ "xu"+" "+names[j],"xu",names[j] }));
   set("gender", "男性" );
   set("class","bonze");
   set("long","这是净念禅院弟子，练功走火入魔了。");
   set("combat_exp",50000);
  setup();
  
}

void init()
{
   object ob;
   
   add_action("do_jiangjing","jiangjing");
   add_action("do_hua","hua");
   
   ob=previous_object();
   if(!ob||!living(ob)||!userp(ob)||
      query("target_id")!=ob->query("id")) return;
   if(query("target_id")==ob->query("id"))
    call_out("show_msg1",1,ob);
}

void show_msg1(object ob)
{
   string msg;
   
   if(!ob||!living(ob)) return;
   
   msg="\n$N朝$n呵呵傻笑了几声。\n";
   message_vision(msg,this_object(),ob);
}

int do_jiangjing(string arg)
{
  object ob,obj;
  string msg;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("你要对谁讲经？\n");
  
  if(!objectp(obj=present(arg,environment(ob))))
  return notify_fail("这里没有这个人。\n");
  if(obj->query("target_id")!=ob->query("id"))
  return notify_fail("对方可不听你胡扯。\n");
  
  msg="\n$N朝$n念了几句经文，$n一呆，突然手舞足蹈，状似疯癫！\n";
  msg +="\n你心中一急，猛地记起师傅曾经说过：天罡拳的精髓意在\n"+
        "「降兵」，看来此时可化$n内力(hua)来消除他的走火入魔之难！\n\n";
  message_vision(msg,ob,obj);
  set("crazy",1);
  call_out("do_destruct",15);
  return 1;
}

int do_hua(string arg)
{
  object ob,obj;
  string msg;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("你要化谁的内力？\n");
  
  if(!objectp(obj=present(arg,environment(ob))))
  return notify_fail("这里没有这个人。\n");
  if(obj->query("target_id")!=ob->query("id"))
  return notify_fail("你不能化对方的内力。\n");
  if(!obj->query("crazy"))
  return notify_fail("他没有疯癫，没必要化内力。\n");
  
  msg="\n$N气集双拳，运用天罡拳威力，朝$n用力打去！\n"+
      "$n顿觉内力全失，$N也觉得浑身酸软，内力全无。\n\n"+
      "$n静下心来，觉得灵台空明，朝$N一施礼：多谢"+RANK_D->query_respect(ob)+"救我一命！\n\n"+
      "$N低头沉思一会，领会出了天罡拳的精髓之处！\n\n";
  message_vision(msg,ob,obj);
  ob->set("perform_quest/tiangang",1);
  ob->set("neili",0);
  set("last",0);
  return 1;
}

void do_destruct()
{
  string msg;
  
  if(!query("crazy"))
   return;
  msg="$N仰头哈哈一笑，疯疯癫癫朝远处跑了。\n";
  message_vision(msg,this_object());
  destruct(this_object());
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N匆匆地走了。\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
   object ob;
   if(clear())
   return 1;
   
   return ::chat();
}
