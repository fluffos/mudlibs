inherit COMMAND_BASE;

string construct_shield_message( object player, int not_self );

int cmd() {

   int size;
   string *shields, mess;

   shields = this_player()->query_arcane_shields();
   size = sizeof( shields );

   mess = construct_shield_message( this_player(), 0 );
   
   /* If they have shields, give message,
    * otherwise, tell them the bad news. */

   if( sizeof( mess ) )
   {
      tell_object( this_player(), "Arcane protection status:\n" + mess );
   }
   else
   {
      tell_object( this_player(), "You do not have any arcane protection.\n" );
   }
   
   return 1;

} /* cmd() */


string construct_shield_message( object player, int not_self )
{
   
   int i, size;
   string mess, *shields;
   
   mess = "";
   shields = player->query_arcane_shields();
   size = sizeof( shields );

   if( not_self > 1 )
   {
      not_self = 1;
   }

   if( not_self < 0 )
   {
      not_self = 0;
   }
   
   for( i = 0; i < size; i += 2 )
   {
      mess += " * $I$+3,+0=$C$" + shields[ i + not_self ] + "$I$-3,-0=\n";
   }

   return mess;

} /* construct_shield_message() */


mixed *query_patterns() {
  return ({ "", (: cmd :) });
}
