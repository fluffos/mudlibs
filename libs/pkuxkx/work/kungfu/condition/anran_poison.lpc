//anran_poison.c
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
   int damage_qi,damage_jing;
   object where = environment(me);
    if( duration < 1 || !where)
    {
        me->delete_temp("death_cond_origin/anran_poison");
        return 0;
    }

   if( !living(me) ) {
      message("vision", HIR""+me->name() + "身中情毒，痛苦的按着胸口。\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIR "你略一动情，心如刀绞。\n" NOR );
      message("vision", HIR""+me->name() + "身中情毒，痛苦的按着胸口。\n"NOR,environment(me), me);
   }
   damage_qi=me->query("qi")/10;
   damage_jing=me->query("jing")/15;
   if(damage_qi<1) damage_qi=1;
   if(damage_jing<1) damage_jing=1;
   damage_qi=damage_qi/2+random(damage_qi/2);
   damage_jing=damage_jing/2+random(damage_jing/2);
   F_POISON->poison_eff(me,"anran_poison",(["qi":({1,damage_qi}),"jing":({1,damage_jing}),]),1); 
   if(!me->is_busy()) me->start_busy(1);
   me->apply_condition("anran_poison", duration - 1);

   return CND_CONTINUE;
}

string query_type(object me)
{
    return "poison";
}

