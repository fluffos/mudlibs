
inherit NPC;

void create()
{
   set_name("剑客",({ "jian ke","jian","ke" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是一个普通的剑客。\n");
       
   set("combat_exp",200000);
   set("attitude", "peaceful");
   set_skill("parry",80);
   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("sword",80);

   setup();
   carry_object(__DIR__"sword")->wield();
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
   message_vision("$N朝$n看了几眼，然后低声道：你敢来刺杀任少名，真是条汉子！\n",this_object(),ob);
  else
   if(ob->query("class")=="bonze")
    message_vision("$N朝$n看了几眼，又把头转到了一边。\n",
     this_object(),ob);
   else
   message_vision("$N朝$n摆摆手:来来，"+RANK_D->query_respect(ob)+",都是武林中人，一起来喝一杯吧！\n",
   this_object(),ob);
   return;
}
