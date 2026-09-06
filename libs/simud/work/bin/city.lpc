#define CITYD "/daemon/city"

int main( string param )
{
   string faction = this_player()->query_faction();
   string Faction = capitalize( faction );

   if( !param )
      return notify_fail( "This command will be used for city maintenance. No help yet.\n" );

   string com;
   if( sscanf(param, "%s %s", com, param) != 2 )
      com = param;

   if( com == "annex" )
   {
      int can_annex = CITYD->query_annex_problem( faction, environment(this_player()) );
      switch( can_annex ) {
         case 0: break;
         case -1: return notify_fail( "This is not an annexable place.\n" );
         case -2: return notify_fail( "A non-citizen owns a building in this room, so you cannot annex it.\n" );
         case -3: return notify_fail( "You need at least two owned buildings in the room to annex it.\n" );
         case -4: return notify_fail( "You must be adjacent to a room owned by the same city.\n" );
         case -5: return notify_fail( "You are not currently acting as an agent of any city.\n" );
         case -6: return notify_fail( "Your city already owns this area!\n" );
         default: return notify_fail( "Unknown error prevented annexation.\n" );
      }
      this_player()->msg_local( "~CACT~Name ~verbdeclare this ground to be the property of " + Faction + "!~CDEF" );
      CITYD->add_room( faction, get_location(environment(this_player())) );
      return 1;
   }
   if( com == "release" ) {
      if( CITYD->query_annex_problem(faction, environment(this_player())) != -6 )
         return notify_fail( "Sorry, you need to own the area and be acting for the owning city to release this area.\n" );
      this_player()->msg_local( "~CACT~Name ~verbdeclare that this ground is no longer controlled by " + Faction + "!~CDEF" );
      CITYD->remove_room( faction, get_location(environment(this_player())) );
      return 1;
   }
   if( com == "addcitizen" ) {
      if( CITYD->query_mayor(faction) != this_player()->query_name() )
         return notify_fail( "Only the mayor, acting for his city, can add or remove citizens.\n" );
      if( !find_player(param) )
         return notify_fail( capitalize(param) + " isn't logged in or doesn't exist.\n" );
      CITYD->add_citizen( faction, param );
      msg_object( find_player(param), "You have been made a citizen of " + Faction + "." );
      msg( capitalize(param) + " is now a citizen of " + Faction + "." );
      return 1;
   }
   if( com == "rmcitizen" ) {
      if( CITYD->query_mayor(faction) != this_player()->query_name() )
         return notify_fail( "Only the mayor, acting for his city, can add or remove citizens.\n" );
      if( !find_player(param) )
         return notify_fail( capitalize(param) + " isn't logged in or doesn't exist.\n" );
      CITYD->remove_citizen( faction, param );
      msg_object( find_player(param), "Your citizenship in " + Faction + " has been revoked." );
      msg( capitalize(param) + " is no longer a citizen of " + Faction + "." );
      return 1;
   }
   if( com == "citizens" ) {
      mapping citizens = CITYD->query_citizens(faction);
      if( !citizens )
         return notify_fail( "You are not acting for a faction that has citizens right now.\n" );
      msg( "Citizens of " + capitalize(faction) + ": ~CBRT" + comma_list( map(m_indices(citizens), #'capitalize) ) + ".~CDEF" );
      return 1;
   }
   return notify_fail( "Command not understood.\n" );
}