
inherit NPC;
#include <ansi.h>
int place_room(object me,object ob);
int ask_kill();
string ask_biwu();
string ask_kill();
int ask_shibai();
int quest_cancel(object who);
void create()
{
        set_name(HIY"天神"NOR, ({ "mud tianshen", "tianshen"}));
        set("gender", "男性");
        set("age", 120);
        set("title", HIG"[古 往 今 来"HIR" * * *"HIG" 唯 我 独 尊]"NOR); 
        set("long", 
"他就是本MUD的开天劈地的天神，武学至尊是也。\n");
        set("combat_exp", 30000000);
        set("shen_type", 0);
        set("max_neili", 500000);
        set("neili", 500000);
        set("max_qi",40000);
        set("max_jing",20000);
        set("max_jingli",20000);
        set("jingli",20000);
        set("per",25);
        set("jiali", 400);
        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("jiuyang-shengong",500);

    set("chat_chance", 5);
    set("chat_msg", ({  
CYN"天神叹了口气道：“江湖恩仇，是是非非，何时能了啊。不知还有
谁能为老夫分忧解难呢？”\n"NOR  
    }));  

        set("inquiry", ([
                "比武大会" : (: ask_biwu :), 
                "分忧解难" : (: ask_kill :),
                "江湖恩仇" : (: ask_kill :),
                "fangqi" :   (: ask_shibai:),
                "放弃":      (: ask_shibai:)
             ]) );
        set("no_clean_up",1);
        set("no_dun",1);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");
}

int ask_kill()
{   
    int kill_count,reward;
    object me,killer;
    mapping quest;
    me=this_player();

       if(me->query("combat_exp")<100000000) {
       write(HIW"你乳臭未刚，怕是不行哟！\n"NOR);
       return 1; 
       }

       if(me->query("combat_exp")>2100000000) {
      write(HIW"这位老大已经这么厉害了,我这里恐怕留不住您！\n"NOR);
      return 1;
      }

       if(me->query("kill_quest")
       && me->query_temp("kill_quest/have_task")) {
       write(HIW"你现在的任务是去除掉在『"
         +me->query("kill_quest/killed_place_name")
         +"』一带活动的"+me->query("kill_quest/killed_name")+"("
         +me->query("kill_quest/killed")+")。\n"NOR);
       return 1;
       }

    if(!me->query_temp("kill_quest/killed")
      && (time()-me->query("kill_quest/time"))<1) {
    write(CYN"小小年纪不学乖，跑哪里去啦，过会再来！\n"NOR);
    return 1;
    }

    if( me->query_temp("kill_quest/count") > 14
     && !me->query_temp("kill_quest/reward"))
    {
    reward=(int)me->query("combat_exp")/1000;
    if(reward>10000) reward=10000; 
    reward=reward+random(reward);
    me->add("kill_quest/reward_exp",reward*10);
    me->add("kill_quest/reward_potential",reward*4);
    me->add("combat_exp", reward*10);
    me->add("potential", reward*4);
    me->set_temp("kill_quest/reward",1); 
    
    write( 
HIW+me->query("name")+", 老夫得你帮助，真乃如虎添翼也！鉴于你出色的
表现，老夫要额外嘉奖你"+CHINESE_D->chinese_number(reward)+
"点经验和\n"+CHINESE_D->chinese_number(reward/5)+
"点潜能，好好干，哈哈哈哈！\n"NOR);
    return 1;
    }

/*   
    if ( me->query_temp("dugu_wait") > time()) {
   write(HIG"你刚刚才取消任务,等一下再来接任务吧。\n"NOR); 
   return 1;
   }

  if ((time()-me->query("kill_quest/time"))<15) {
   write(
     CYN"你已经累了一天了，老夫吩咐你的任务都完成了，先回去歇息吧。\n"NOR);
   return 1;
   }
*/

 if( me->query_temp("kill_quest/count") > 14)
  {
   me->set_temp("kill_quest/reward",0); 
   me->set_temp("kill_quest/count", 0);
  }
   killer=new(__DIR__"quest_npc");
   place_room(me,killer);
   killer->start_escape(killer,me);
   me->set("kill_quest/killed",killer->query("id"));
   me->set("kill_quest/killed_name",killer->query("name"));
   me->set("kill_quest/killed_place_name",killer->query("area"));
   me->set("kill_quest/time",time());
   me->set_temp("kill_quest/have_task",1);
   write( 
    HIC"难得"+me->query("name")+"有心为老夫分忧解难，老夫近日获悉\n"
    +killer->query("title")+killer->query("name")+"("+killer->query("id")
    +")在『"+killer->query("area")+"』一带活动，\n"
    +"你就替老夫前去除掉他吧，切记在十五分钟内完成。\n"NOR);
   return 1;
}


string ask_biwu()
{
    object me=this_player();
    call_out("send_me",2,me);
    command("haha "+me->query("id"));
    return RANK_D->query_respect(me)+"原来也想参加武林大会？"
    +"那就让老夫送你一程吧！\n";
}

int send_me(object me)
{
    if(objectp(me))
    {
    message_vision(HIW"只见$N一招手，两名黑衣大汉走了过来，象拎小鸡似地一把将$n"
    +"架起，\n扔进了一辆马车......\n"+"不一会儿，马车停了下来，$n连忙爬下马车，"
    +"原来已经到了华山了！\n"NOR,this_object(),me);
    me->move("/d/huashan/houzhiwangyu");
    }
    return 1;
}

int ask_shibai( )
{       
        object me;
        int i;
        me = this_player();
        i = me->query("potential");

         if(!me->query("kill_quest")) {
         write(HIM"你没有领任务,跑这里瞎嚷嚷什麽?\n"NOR);
         return 1;
         }
 
         if (me->query("potential") -                     (int)me->query("learned_points")<=800) {
         write(CYN"你的pot不够取消任务了!\n"NOR);
         return 1;
         }

         me->add("potential",-800);
         me->delete("kill_quest/time");
         me->delete("kill_quest");
         me->delete("dugu_wait");
         me->set_temp("dugu_wait",time()+20);
         quest_cancel(me);
         write(CYN"我看错你了，我只能找别人了,扣你800点POT.\n"NOR);
         return 1;
}
  

int quest_cancel(object who){
             object killer;   

             who->set_temp("kill_quest/have_task",0); 
             if(who->query("kill_quest/killed"))
              killer=find_living(who->query("kill_quest/killed"));
              who->set_temp("shan_quest/killed","canceled"); 
         if(killer)
         killer->escape_me(killer,who);   

       return 1;
}
void unconcious()
{
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        say( "任务NPC,请勿伤害！\n");
      }
void die()
{
        unconcious();
}
#include "quest_kill.h" 