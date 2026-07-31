//ssnake.c

#include <ansi.h>

int update_condition(object me, int duration)
{
       if( duration < 1 ){
           me->set_temp("apply/damage",me->query_temp("back/damage",1));
           me->set_temp("apply/attack",me->query_temp("back/attack",1));
           me->clear_condition("ssnake");
       }
       if ( !duration) return 0;
       me->apply_condition("ssnake", duration-1);
       return 1;
}

string query_type(object me)
{
       return "poison";
}
