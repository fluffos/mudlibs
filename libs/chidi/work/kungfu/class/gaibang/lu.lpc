// jzad 2001/8/2

#include <ansi.h>
#include <command.h>
inherit BHNPC;
inherit F_MASTER;
string ask_work();
string ask_fail();
string ask_gonglao(object who);
void create()
{   set("inquiry", ([
             "work" : (: ask_work :),
             "fail" : (: ask_fail :),
             "gonglao" : (: ask_gonglao :),
             "功劳" :  ( : ask_gonglao :),               ]));  
    set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
    set("title", "丐帮九袋长老");
    set("nickname", "掌棒龙头");
    set("gender", "男性");
    set("age", 45);
    set("long", 
        "鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
        "因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
    set("attitude", "peaceful");
    set("str", 25);
    set("int", 12);
    set("con", 25);
    set("dex", 20);
    set("qi", 900);
    set("max_qi", 900);
    set("jing", 100);
    set("max_jing", 100);
    set("neili", 1200);
    set("max_neili", 1200);
    set("jiali", 100);    
    set("combat_exp", 700000);    
    set_skill("force", 150);                // 基本内功
    set_skill("huntian-qigong", 150);   // 混天气功
    set_skill("unarmed", 150);          // 基本拳脚
    set_skill("xianglong-zhang", 150);  // 降龙十八掌
    set_skill("dodge", 150);                // 基本躲闪
    set_skill("xiaoyaoyou", 150);       // 逍遥游
    set_skill("parry", 150);                // 基本招架
    set_skill("club", 150);             // 基本棍杖
    set_skill("begging", 150);
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("parry", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    create_family("丐帮", 18, "九袋长老");
    setup();

}

void attempt_apprentice(object ob)
{
    if ((int)ob->query("shen") < 5000) {
        command("say 我丐帮乃忠义之门，行事光明磊落。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
            "是否还做得不够？");
        return;
    }
    command("say 好吧，希望" + RANK_D->query_respect(ob) +
    "能好好学习本门武功，将来在江湖中闯出一番作为。");
    command("recruit " + ob->query("id"));
    if((string)ob->query("family/family_name") != "丐帮")
        ob->set("class", "beggar");
}
string ask_work()
{
        object ob = this_player();
        object ob1,ob2;
        mapping quest,fam; 
        quest = (__DIR__"where")->query_quest();
          if (ob->query("combat_exp")>1000000)
        {
                return "你现在必须去做更艰巨的任务，去找彭长老要任务吧\n";}
           if (ob->query("combat_exp")<100000)
        {       
                return "你现在经验太底，我还不放心！" ;                
                }
          if (interactive(ob) && (int)ob->query_condition("job_busy"))  
         {     
                return "现在我可没有给你的任务，等会再来吧。\n";  }
          if (interactive(ob) && (int)ob->query_condition("job_mission"))
        {
                return "不是刚给你任务吗，怎么又来了？";}     
         
        ob->set("do_job",1);
        
        ob2 = new(__DIR__"richman");
        ob2->move(quest["place"]);
       ob->apply_condition("job_mission",30);
      
        command("nod" + ob->query("id"));
        command("say 听说有个大富翁在『" + quest["short"] + "』出现!");
          return "快去吧";
 }
string ask_fail()
 {
         object ob = this_player();
         object ob1;
         if ((int)ob->query("do_job")==0)
               {return "你没有要任务啊?";
             }
         
           ob -> delete("do_job");
         if (ob -> query("finish_coin"))
              {ob -> delete("finish_coin");}
         ob->clear_condition("job_mission");
           ob->apply_condition("job_busy",2+random(5));
         return "没关系，下次努力";
              
            
  }

        
 int accept_object(object ob,object ob1)
  {     
         int i,exp,pot,count;
         i = ob->query_skill("begging",1);
         if ((int)ob->query("do_job")!=1)
          {command("say 无功不受赂，这些东西我不能要.");
            return 1;}
          if ((int)ob->query("finish_coin")!=1)
          {command("say 这是你要来的吗？");
          return 0;
          }
        
        if ( ob1->query("money_id") != "coin" )
           {
            command ("say 我丐帮弟子虽然很穷，但从不做违法的事，你这些钱哪来的？");
            return 1;}
        
        command ("say 做的好，不愧是我丐帮的弟子，大有前途!\n");
        command ("say 好，给你一些奖励,以后要多加努力");
        if (!ob->query ("finish_job_count"))
        {ob->set("finish_job_count",1);
        }
        ob->add("finish_job_count",1);
        count=ob->query("finish_job_count");
          exp = 200 + count/5;
        pot = exp/2;
        ob->add("combat_exp",exp);
        ob->add("potential",pot);
        tell_object(ob,HIW"你被奖励了：\n" + 
        chinese_number(exp) + "点实战经验\n" +
        chinese_number(pot) + "点潜能\n"+
        NOR);
          ob -> delete("do_job");
          ob -> delete("finish_coin");
        ob->clear_condition("job_mission");
        ob->apply_condition("job_busy",random(5));
        call_out("destroying", 1, ob1);
        return 1;
  }
  void destroying(object obj)
 {
        destruct(obj);
        return;
 } 
string ask_gonglao(object who)
{
  object me;
  int i;
  me = this_player();
  if(!me->query("finish_job_count"))
  i=0;
  else 
  i =(int)me->query("finish_job_count"); 
  message_vision(CYN"$N对$n说道:你已经完成了" + chinese_number(i) + "次任务。\n"NOR,who,me);
  return "继续努力吧！";
}
