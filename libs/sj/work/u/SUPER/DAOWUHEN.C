inherit NPC;
int do_fengyin();
#include <ansi.h>
int do_quest();
int do_finish();

void create()
{
        set_name(HIG"血无痕"NOR, ({"doctor"}));
        set("nickname", HIB"刀过无痕"NOR);
        set("title",HIR"特种部队总指挥"NOR);
        set("gender", "男性");
        set("age", 100);
        set("long", 
                "他就是特种部队的总指挥了，也是特种部队的最高级首领。\n");
        set("attitude", "peaceful");
        
        set("str", 100);
        set("int", 100);
        set("con", 100);
        set("dex", 100);
        set("qi", 50000);
        set("max_qi", 50000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 90000);
        set("max_neili", 90000);
        set("jiali", 500);
        
        set("combat_exp", 9000000);
        set("score", 999999);
         
        set_skill("force", 300);            
        set_skill("duanqing-xinfa", 300);    
        set_skill("blade", 300);          
        set_skill("lengxue-dao", 300);   
        set_skill("dodge", 300);            
        set_skill("jiqi-qudong", 300);     
        set_skill("parry", 300);             
        set_skill("unarmed", 300);           
        set_skill("yinyang-zhang", 300);        
        set_skill("rennai",300);
        set_skill("jianti-shu",200);
        map_skill("force", "duanqing-xinfa");
        map_skill("rennai","jianti-shu");
        map_skill("unarmed", "yinyang-zhang");
        map_skill("dodge", "jiqi-qudong");
        map_skill("parry", "lengxue-dao");
        map_skill("blade", "lengxue-dao");
        set("inquiry",([
                  "老婆婆" : (: do_quest :),
                  "完成"  : (: do_finish :),
                  "死神的封印" : (: do_fengyin :),
                  ]));

        setup();
}
int do_quest()
{
      object me,thing;
      object room;
      me = this_player();
      if (!(me->query_temp("大任务")))
      return notify_fail("老婆婆…………不知道！\n");
      if (me->query("family")["family_name"]!="特种部队")
      return notify_fail("她是我们特种部队的，你又不是特种部队的，问她干嘛？\n");
      if (me->query("combat_exp") < 1000000)
      return notify_fail("唉，罢了，罢了！人都死了！\n");
      command("say 什么？？！她被人杀了…………哇，我要为他报仇！！\n");
      command("tell"+me->query("id")+"你帮我去了撑这件事，好不好，我给你几样东西！");
      thing = new("/d/budui/obj/miji");
      thing->move(me);
      thing = new("/d/budui/obj/fuchou-zhan");
      thing->move(me);
      message_vision("刀无痕给了$N一本"HIR"〈噬血刀法〉\n"NOR,room);
      message_vision("刀无痕给了$N一把"HIB"复仇-斩\n"NOR,room);
      command("xixi"+me->query("id"));
      command("addoil"+me->query("id"));
      me->set_temp("又一个任务",1);
      me->delete_temp("大任务");
      return 1;
}
int do_finish()
{
      object me;
    
      me = this_player();
      if (!(me->query_temp("又一个任务"))) 
      return notify_fail("你完成什么了？\n");
      if (!(me->query_temp("完成")))
      return notify_fail("你还没有帮刀无痕报仇！\n");
      command("say 恩，不错，你干得好！不愧是我特种部队的一员！");
      message_vision("你被奖励了1000点战斗力,300点学习值,5000点电子货币",this_player());
      me->add("combat_exp",1000);
      me->add("money",5000);
      me->add("potential",300);
      me->delete_temp("又一个任务");
      me->set_temp("还有一个任务",1);
}
int do_fengyin()
{
     object me,thing;
     me = this_player();
     if (!(me->query_temp("还有一个任务")))
     return notify_fail("不晓得！\n");
     if (me->query("family")["family_name"]!="特种部队")
     return notify_fail("你没有权利知道关于这个的事情！\n");
     command("say 哦，对对对，我还有件东西忘记给你了！\n");
     thing=new("/d/budui/obj/sishenfengyin");
     thing->move(me);
     message_vision("刀无痕给$N一块死神的封印。\n");
     me->delete_temp("还有一个任务");
     return 1;
}    

