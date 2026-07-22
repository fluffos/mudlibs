#include <ansi.h>
string type() { return "jueshi"; }
inherit FORCE;

mixed hit_ob(object me, object victim, int damage_bonus)
{
int maxlv;
   maxlv
     =(me->query("jiuyanglv")+2)*(me->query("jiuyanglv")+1)*(me->query("jiuyanglv")+1);
if (maxlv> 150) {maxlv=150;}
    if( damage_bonus < 100 ) return 0;
if (me->query("special_skill/jiuyangbody") == 1 && (me->query("neili")<me->query("max_neili")*5/4))
     {
    me->add("neili",random((int)me->query("jiali"))*5);
victim->receive_wound("qi", (damage_bonus ));
victim->receive_wound("jing", (damage_bonus ));
   me->add("neili",random((int)me->query("jiali"))*5);
message_vision(HIR"$N融合九阳神功的精髓，发挥出"HIY"九转十二天"HIR"的刚劲，震毁了$n的丹田！\n"NOR,me,victim);

     }
   
    if( random(3*(me->query_skill("23tian-jiuyang",1))) > (damage_bonus )) {
if (me->query("12tianlv")){
                          victim->receive_wound("qi", (damage_bonus )*(10+me->query("12tianlv"))/8);
                          victim->receive_wound("jing", (damage_bonus )*(10+me->query("12tianlv"))/10);
                         victim->add("neili", -(int)me->query("jiali")*me->query("12tianlv"));
          if (victim->query("neili")<1) victim->set("neili",1);
       if(me->query_skill("12tian-jiuyang",1)<(me->query_skill("force",1)/2)&&me->query_skill("12tian-jiuyang",1)<(me->query_skill("jiuyang-shengong",1)))
{
 me->improve_skill("12tian-jiuyang",((damage_bonus )+me->query_skill("12tian-jiuyang",1))*maxlv);
}
        return HIR "$N发挥出九转十二天残篇的第"+chinese_number(me->query("12tianlv"))+"重内劲，摧毁了$n的真元！！！！\n" NOR;
                               }
else   {
 
                        victim->receive_wound("qi", (damage_bonus )/1);
                        victim->receive_wound("jing", (damage_bonus )/1);
                        victim->add("neili", -(int)me->query("jiali"));
                         return HIR "$N的九转12天残篇摧毁了$n的真元！！！！\n" NOR;
        }
}
}

int valid_enable(string usage) 
{     return usage=="force";}

int valid_learn(object me)
{
   if ((int)me->query_skill("12tian-jiuyang",1) >= 0)
     return notify_fail("九转12天残篇只能靠战斗来提升。\n");
    return 1;
}
int practice_skill(object me)
{
   return notify_fail("九转12天残篇只能靠战斗来提升。\n");
}

void skill_improved(object me)
{
           switch (me->query_skill("12tian-jiuyang",1))
   {
                case 1001:
     {
                      
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第一重〗境界！！\n\n" NOR);
                        me->set("12tianlv",1);
                        break;
          }
                case 2001:
     {
                       
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第二重〗境界！！\n\n" NOR);
                        me->set("12tianlv",2);
                        break;
          }
                case 3001:
     {
                       
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第三重〗境界！！\n\n" NOR);
                        me->set("12tianlv",3);
                        break;
          }
                case 4001:
     {
                        
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第四重〗境界！！\n\n" NOR);
                        me->set("12tianlv",4);
                        break;
          }
                case 5001:
     {
                       
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第五重〗境界！！\n\n" NOR);
                        me->set("12tianlv",5);
                        break;
          }
                case 6001:
     {
                        
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第六重〗境界！！\n\n" NOR);
                        me->set("12tianlv",6);
                        break;
          }
                case 7001:
     {
                       
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第七重〗境界！！\n\n" NOR);
                        me->set("12tianlv",7);
                        break;
          }
                case 8001:
     {
                       
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第八重〗境界！！\n\n" NOR);
                        me->set("12tianlv",8);
                        break;
          }
                case 9001:
          {
                        message_vision(HIB "$N周身真气鼓胀，面如重枣。内劲外放，迫得周围众人连连后退，看来内功有了明显提升！\n" NOR, me);
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第九重〗境界！！\n\n" NOR);
                        me->set("12tianlv",9);
                        break;
          }
                case 10001:
          {
                        message_vision(HIB "$N周身真气鼓胀，面如重枣。内劲外放，迫得周围众人连连后退，看来内功有了明显提升！\n" NOR, me);
                        tell_object(me, HIY "由于你勤奋研习，你的九转12天残篇已经达到〖第十重〗境界！！\n\n" NOR);
                        me->set("12tianlv",10);
                        break;
          }
   }
     return;
}
string exert_function_file(string func)
{
         return __DIR__"12tian-jiuyang/" + func;
}
