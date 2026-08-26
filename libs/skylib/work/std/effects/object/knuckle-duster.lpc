#include <effect.h>

string query_classification() { return "weapon.knuckle-duster"; }

string query_shadow_ob() { return "/std/shadows/object/knuckle-duster"; }


void beginning( object player, object item )
{ 
   tell_creator( player, "Adding knuckle duster effect.\n" );
}


object merge_effect( object player, object old_item, object new_item ) {
   return old_item;    // Not that it's used anywhere anyway.
} /* merge_effect() */


void end( object player, object item )
{ 
   tell_creator( player, "Removing knuckle duster effect.\n" );
} /* end() */


void person_removing_item( object item, object player )
{
   int *enums;
   
   enums = player->effects_matching( query_classification() );
  
   if( sizeof( enums ) )
      player->delete_effect( enums[ 0 ] );
} /* person_removing_item() */
