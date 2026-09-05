#include <ansi.h>
inherit NPC;

int ask_me();
void consider();
void create()
{

set_name("田伯光", ({ "tian boguang", "tian" }));
        set("title", HIR"万里独行"NOR);
        set("gender", "男性");
        set("age", 33);
        set("str", 15);
         set("dex", 16);
    set("long", "田伯光是个采花大盗，但凭一把快刀而走江湖，也没多少人能奈何他。\n");
     set("combat_exp",150000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 80);
        set("rank_info/rude", "淫贼");
        set_skill("force", 70);
set("chat_chance_combat", 100);
 set("chat_msg_combat", ({
                (: consider :)
                
        }) );
        set_skill("blade",70);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("kuai-dao", 80);

        set("max_qi", 2000);
        set("neili", 2000);
        set("max_neili", 1000);
        set("jiali", 20);

        map_skill("blade","kuai-dao");
        map_skill("parry","kuai-dao");
        map_skill("dodge","kuai-dao");


       set("inquiry", ([
                "name" : "我叫田...田伯伯。",
                "rumors" : "听说扬州中央广场附近有个宝库...", //add by iszt, 2006-08-14
                "淫贼" : (: ask_me :),
                "采花大盗" : (: ask_me :),
        ]) );
        set("shen_type",1);set("score",3000);setup();

         carry_object(__DIR__"obj/dandao")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
    
 }

void init()
{
        ::init();
        add_action("do_accept", "accept");
}

int ask_me()
{
    object weapon;

   if (this_player()->query("combat_exp")<1000) 
      {
   message_vision("田伯光对着$N一乐：乳臭未干的小孩子懂什么！\n",this_player());
   return 1; 
        }
   if (this_player()->query_temp("marks/田3"))
     {

message_vision(HIR"田伯光对$N喝到：奶奶的，杀人不过头点地，凭你那两下子，\n",this_player());
say("还来威胁老子，拿命来吧！\n");


      if (!objectp(weapon = this_object()->query_temp("weapon")) )
            {
             remove_call_out("wielding");
             call_out("wielding",0,this_object());
             }        
       this_object()->kill_ob(this_player());
                return 1;
      }
say("田伯光懒懒的神了神腰，揉了揉眼，满不在乎的说道：\n"
"我就是人称采花大盗的田伯光，你要怎麽样？看你好象有点打抱不平\n"
"还不服气吧， 那好，咱俩过两招，\n" 
"要是你能接我三招，也算江湖上的英雄之辈了，以后我就收敛点。\n"
"你要接不了，也别来充这大头。怎麽样，敢不敢接(accept)三招?\n");

        this_player()->set_temp("marks/田2", 1);
        return 1;
}

int do_accept()
{
        object me, obj, book,weapon;
        int current_qi;
        me = this_object();
        obj = this_player();
        book = new(__DIR__"obj/blade_book");

if( obj->query_temp("marks/田2") ) 
  {
message_vision("$N对田伯光说：好吧，那" + RANK_D->query_self_rude(obj)+"就接你三招。\n",obj);
     
      if (!objectp(weapon = this_object()->query_temp("weapon")) )
    {

             remove_call_out("wielding");
             call_out("wielding",0,this_object());
    }  
      
     remove_call_out("testing");
     call_out("testing",2,this_object(),this_player());
       return 1;
}
say("田伯光吃惊的说：你要干什么？！\n");
    return 1;

}
void consider()
{
  if(!present("dan dao",this_object()) )
  {
     object weap=new("/d/city/npc/obj/dandao");
        weap->move(this_object());
   }
   command("wield blade");
   return;   
              
    
}
void testing(object me,object obj)
{
  
   object book=new(__DIR__"obj/blade_book");
 
 
          me->set("jiali",0);             
  while ( ((int)obj->query("qi")*100 / (int)obj->query("max_qi"))> 50) 
       {
                  if( !present(obj->query("id"), environment(me)))
                                return;

           if(objectp(present(obj, environment(me)))) 
              {
                COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
              }


       if(((int)obj->query("qi")*100 / (int)obj->query("max_qi"))< 40)
              {
message_vision("田伯光对$N说：呵呵，才一招就熊了，滚吧！\n",obj);
          me->set("jiali",50);
         return;
              }
            if(objectp(present(obj, environment(me)))) 
              {
                COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
              }
 if(((int)obj->query("qi")*100 / (int)obj->query("max_qi"))< 20)
              {
  message_vision("田伯光对$N说：两招都接不了，再吃几年饭吧，滚吧！\n",obj);
         me->set("jiali",50);
          return;
               }
          if(objectp(present(obj, environment(me)))) 
               {
                COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
               }
         if(objectp(present(obj,environment(me))) &&((int)obj->query("qi")*100 /(int)obj->query("max_qi"))> -1 )
               {
say("田伯光说：好好，真是江山个有才人出啊，以后我就收敛点就是了。\n"
"看"+ RANK_D->query_respect(obj)+"也是个英雄，这本书也算是一点心意送给你吧，我虽
名声不好\n"
"至少还不是他妈的伪君子，是不是？\n");
me->set("jiali",50);
message_vision("田伯光交给$N一本书\n",obj);
                             book->move(obj);
                             obj->set_temp("marks/田2", 0);
                             obj->set_temp("marks/田3", 1);

                }
  return;
          }
message_vision("田伯光不屑地看了看$N撇撇嘴，说道：别来送死。\n",obj);

   return;
 }

void wielding(object obj)
 {
   
   if(!present("dan dao",this_object()) )
  {
     object weap=new("/d/city/npc/obj/dandao");
        weap->move(this_object());
   }
   command("wield blade");
   return;
}
 
