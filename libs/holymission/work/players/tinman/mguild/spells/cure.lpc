

/* cure */

#include "chk_pres.h"

//##m## is in defs.h now
#if 0
#define HEAL   ( _tpw * 4 ) 
#endif

int cure(string arg)
{
   object mob;
   string name;
   string poss;
   int to_heal;

   _chk_ghost();

   if (arg && lower_case(arg)==_tp->query_real_name() && _tp->query_attack())
   {
      write("You are much too busy to cure yourself !\n");
      return 1;
   }
   else if (objectp(mob = chk_present(arg,(CURE/2),8)))
   {
      name = mob->query_name();
      poss = mob->query_possessive();
      if (mob != _tp) 
      {
         write(
         "You lay your hands on "+name+" and cure "+poss+" wounds !\n");
         say(
         _tpn+" lays both hands on "+name+" !\n",mob,_tp);
      }
      tell_object(mob,"You feel better !\n");
      to_heal = mob->query_max_hp() - mob->query_hp();

	-_tp->restore_spell_point(-CURE);
      if (to_heal > CURE)
          to_heal = CURE;
      mob->reduce_hit_point(-to_heal);
      return 1;
   }
  return 0;
}
