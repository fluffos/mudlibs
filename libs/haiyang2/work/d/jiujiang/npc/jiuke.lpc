
inherit NPC;

void create()
{
   set_name("酒客",({ "jiu ke","jiu","ke" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是一个经常在春在楼喝酒的人，看起来有些饱经沧桑的样子。\n");
       
   set("combat_exp",30000);
   set("attitude", "peaceful");
   add_money("coin",30);
   setup();
  
}

void init()
{
   object ob;
   ob=previous_object();
   if(userp(ob)&&!ob->is_fighting()&&living(ob))
    call_out("welcome",1,ob);
   return;
}

void welcome(object ob)
{
  if(!ob||
  environment(this_object())!=environment(ob)
  ||!living(ob))
  return;
  if(ob->query_temp("dtsl_job_cisha/step2"))
   message_vision("$N朝$n看了几眼，然后低声叹道：又来了个不怕死的。\n",this_object(),ob);
  else
   if(ob->query("class")=="bonze")
    message_vision("$N横了$n一眼：竟然碰到出家的，今天真是倒霉透顶！！\n",
     this_object(),ob);
   else
   message_vision("$N朝$n摆摆手:来来，"+RANK_D->query_respect(ob)+",一起来喝一杯吧！\n",
   this_object(),ob);
   return;
}
