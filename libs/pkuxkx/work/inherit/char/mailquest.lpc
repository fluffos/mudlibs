#pragma save_binary

#include <ansi.h>

int accept_object(object who,object obj)
{
   object me = this_object();                        
   mapping quest;
   if(undefinedp(quest = who->query("quest")))
      return 0;  
   if(obj->query("name")==HIG"信"NOR && !userp(obj) 
      && me->query("name") == quest["quest"] && quest["quest_type"] == "送" )
      {   
         remove_call_out("accept_ok");
         call_out("accept_ok",0,me,who,obj);   
         return 1;
      }
   else 
      return 0;  
}     

void accept_ok(object me,object who,object obj)
{
  who->set_temp("quest_finish",1);
  message_vision("$N愉快的接受了$n送来的信。\n"
       +me->query("name")+"说：“快回去向你师父复命吧。”\n",me,who);
  destruct(obj);
}
