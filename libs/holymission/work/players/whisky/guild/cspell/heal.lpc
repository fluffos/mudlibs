

/* heal */

#include "chk_pres.h"

#if 0
// ##m##
#define HEAL   ( _tpw * 8 ) 
#endif

int heal(string arg)
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
   else if (objectp(mob = chk_present(arg,HEAL/2,20)))
   {
      name = mob->query_name();
      poss = mob->query_possessive();
      if (mob != _tp) 
      {
         write(
         "You heal "+name+"'s wounds !\n");
         say(
         _tpn+" heals "+name+"'s wounds !\n",mob,_tp);
      }
      tell_object(mob,"You feel much better !\n");
      to_heal = mob->query_max_hp() - mob->query_hp();

//##m##   changed to_heal to HEAL
	_tp->restore_spell_points(- HEAL/2);
	if( to_heal > HEAL )
		to_heal = HEAL;
        mob->reduce_hit_point(-to_heal);

//##m## just changed the order of the lines so it always costs full ammount

      return 1;
   }
  return 0;
}

      
       

      
       
            
            
        
       
       

