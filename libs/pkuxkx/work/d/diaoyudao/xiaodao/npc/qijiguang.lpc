//戚继光负责发放剿灭倭寇的任务
//by zhx           

inherit NPC;   
#include <ansi.h>         

 
string ask_jiaomie();            
string do_confirm();      
void create()         
{
           string weapon; 
           set_name("戚继光", ({ "qi jiguang","qi" }) );    
           set("gender", "男性");   
           set("age", 45);           
           set("per",40);            
           set("long", "抗倭英雄戚继光，国民的偶像。\n"); 
           set("combat_exp", 6500000000);     
           set("shen_type", 0);      
           set("attitude", "friendly");       
           set("apply/attack",  60000);       
           set("apply/defense", 60000);       
           set("inquiry",([          
           "倭寇"       : (:ask_jiaomie:),     
           "剿灭倭寇"   : (:ask_jiaomie:),
                          ]));     
           set_skill("unarmed", 4000);        
           set_skill("parry", 4000); 
           set_skill("dodge", 4000);                      
           set_skill("force", 4000);
           set_skill("sword", 4000);
           set_skill("cuff", 4000);
           set_skill("blade", 4000);
           set_skill("taizu-quan", 4000);
           set_skill("qingmang-jian", 4000);
           set_skill("wind-blade", 4000+random(380));
           map_skill("blade", "wind-blade");
           map_skill("parry", "wind-blade");
           map_skill("dodge", "qingmang-jian");
           map_skill("sword", "qingmang-jian");
           map_skill("cuff", "taizu-quan");
           prepare_skill("cuff", "taizu-quan");
          // set_temp("apply/attack", 200);
          // set_temp("apply/defense",500);
          set_temp("apply/armor", 6000);
          set_temp("apply/damage", 4200);

          set("chat_chance_combat", 70);
          set("chat_msg_combat", ({
          (: perform_action, "blade.leitingpili" :),
          (: perform_action, "blade.kuang" :),
            }) );
          set("max_qi", 75000);
          set("jingli", 20000);
          set("max_jingli",20000);
          set("jing",20000);
          set("max_jing",20000);
          set("neili", 160000);
          set("max_neili", 160000);
          set("jiali", 2000);
          weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
          setup();
          add_money("silver", random(100));


        
          carry_object(weapon)->wield();
          carry_object("/clone/misc/cloth")->wear();
           
           
           
           
           setup();    
                    
}             
void init()   
{             
           add_action("do_confirm", "confirm");     
}             

string ask_jiaomie() 
{             
          object me=this_player(); 
          if ((int)me->query("combat_exp") < 50000000)   
               {     
                tell_object(me, "你经验太低，去了还要担心你的安全，还是不要去了？\n");      
                return "你的经验太低了！";  
               }      
          command("consider");    
          return "你真的确认要去吗？请确认（confirm）！";    
}             
string do_confirm()    
{             
          object me=this_player();                   
          me->set_temp("title","抗倭英雄");            
          message("chat",HIY+"【闲聊】戚继光(Qi jiguang):"+this_player()->name()+      
           "不忘民族大义，英勇抗击倭寇！\n"NOR,users());
          command("nod");   
                message("vision","一个戚家兵丁领你到了一个船上！ \n",me); 
                me->move("/d/diaoyudao/xiaodao/muchuan");                    
                call_out("wait4", random(30) , me );
                return "英雄保重。";     
                  
        
}   

void wait4(object me)
{
        me->move ("/d/diaoyudao/xiaodao/shanlu1") ;
        message_vision("$N感觉过了好长时间，正在昏昏欲睡间，感觉船震了一下，原来是靠岸了。\n",me);      
        message_vision("$N整理了一下装备，朝兵丁挥了挥手便英勇地跨上岸去。\n",me);
        
}

          

