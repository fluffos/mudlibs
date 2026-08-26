
inherit COMMAND_BASE;

int cmd() {
   int no_limbs;
   string stuff;
   object thing, *equipped, *things;
   equipped = ({ });
   things = all_inventory( TP ) - (object *)TP->query_wearing();
   foreach ( thing in things ) {
      if ( thing->query_wearable() ) {
         if ( !TP->wear_armour( thing, 0 ) )
            equipped += ({ thing });
         continue;
      }
      no_limbs = (int)thing->query_no_limbs();
      if ( !no_limbs || no_limbs > (int)TP->query_free_limbs() )
         continue;
      if ( sizeof( (int *)TP->set_hold( thing,
            member_array( 0, (object *)TP->query_holding() ) ) ) )
         equipped += ({ thing });
   }
   if ( !sizeof( equipped ) )
      return notify_fail( "You have no equippable items.\n" );
   stuff = query_multiple_short( equipped );
   say( (string)TP->one_short() +" equips "+ stuff +".\n" );
   write( "You equip "+ stuff +".\n" );
   return 1;
} /* cmd() */

mixed *query_patterns() { return ({ "", (: cmd() :) }); }
