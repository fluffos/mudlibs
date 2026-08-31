


/* aid */

#include "chk_pres.h"

//##m## moved to defs.h
#if 0
#define HEAL   ( _tpw * 2 ) 
#endif

int aid(string arg)
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
   else if (objectp(mob = chk_present(arg,(AID/2),0)))
   {
      name = mob->query_name();
      poss = mob->query_possessive();
      if (mob != _tp) 
      {
         write(
         "You do first aid to "+name+" !\n");
         say(
         _tpn+" aids "+name+" !\n",mob,_tp);
      }
      tell_object(mob,"You feel a bit better !\n");
      to_heal = mob->query_max_hp() - mob->query_hp();

	_tp->restore_spell_point(-CURE/2);

      if (to_heal > CURE)
          to_heal = CURE;
      mob->reduce_hit_point(-to_heal);
//      _tp->restore_spell_points(-(to_heal*2/3));
      return 1;
   }
  return 0;
}

      
       

      
       
            
            
        
       
       

