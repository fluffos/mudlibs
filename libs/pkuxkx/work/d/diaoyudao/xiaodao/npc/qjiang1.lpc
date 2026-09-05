#include <ansi.h>
inherit NPC;

int do_copy(object me,int flag);
int do_back(object me);
string ask_xiuxi(); 

void create()
{
        string weapon;
        set_name("戚家军千总", ({ "qian zong","jiang"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "一个威武的戚家军千总。\n");
        set("combat_exp", 10000000 + random(4000000));
      //  set("attitude", "aggressive");
        set("inquiry",([          
           "休息"       : (:ask_xiuxi:),     
           "回去"   : (:ask_xiuxi:),
                          ]));  
        set_skill("force", 800);
        set_skill("sword", 800);
        set_skill("dodge", 800);
        set_skill("parry", 800);
        set_skill("cuff", 800);
        set_skill("blade", 800);
        set_skill("taizu-quan", 800);
        set_skill("qingmang-jian", 800);
        set_skill("wind-blade", 1000+random(180));
          map_skill("blade", "wind-blade");
          map_skill("parry", "wind-blade");
          map_skill("dodge", "qingmang-jian");
          map_skill("sword", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense",500);
        set_temp("apply/armor", 300);
        set_temp("apply/damage", 220);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
                set("max_qi", 4500);
        set("eff_jingli", 8000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 300);
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
        setup();
        add_money("silver", random(100));


        
        carry_object(weapon)->wield();
        carry_object("/clone/misc/cloth")->wear();
}

//#include "bing.h"

string ask_xiuxi()    
{             
          object me=this_player();                   
          message("vision","大侠辛苦了。请您回去休息吧。 \n",me); 
          me->move("/d/diaoyudao/xiaodao/muchuan");                    
          call_out("wait4", random(10) , me );
          return "谢谢英雄为民除倭！";     
                  
        
}   

void wait4(object me)
{
        me->move ("/d/diaoyudao/xiaodao/dazhang") ;
        message_vision("$N感觉过了好长时间，正在昏昏欲睡间，感觉船震了一下，原来是靠岸了。\n",me);      
        message_vision("$N整理弹了一下身上的土，朝兵丁挥了挥手跨上岸向戚家军大帐走去。\n",me);
        message_vision("$N进到戚家军大帐。\n",me);
        
}
