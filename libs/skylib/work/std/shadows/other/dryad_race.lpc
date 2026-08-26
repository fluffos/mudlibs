/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: dryad_race.c,v 1.1 1998/01/06 04:42:56 ceres Exp $
 * $Log: dryad_race.c,v $
 * Revision 1.1  1998/01/06 04:42:56  ceres
 * Initial revision
 * 
*/
object person;

void setup_shadow( object thing ) {
   shadow( thing, 1 );
   person = thing;
} /* setup_shadow() */

void destruct_shadow( object thing ) {
   if ( thing == this_object() )
      destruct( this_object() );
   else
      thing->destruct_shadow( thing );
} /* destruct_shadow() */

varargs int query_ac( string type, int damage, string zone ) {
   int amount;
   object attacker, weapon;
   amount = (int)person->query_ac( type, damage, zone );
   if ( ( type != "pierce" ) && ( type != "sharp" ) )
      return amount;
   if ( ( type == "pierce" ) && ( zone == "neck" ) )
      return amount;
   if ( ( type == "fire" ) )
      return amount*2;
   attacker = (object)this_object()->query_attacker();
   if ( attacker ) {
      weapon = (object)attacker->query_weapon();
      if ( weapon && ( weapon != attacker ) )
         weapon->adjust_cond( -(int)weapon->query_cond() / 6 );
   }
   return damage;
} /* query_ac() */   
