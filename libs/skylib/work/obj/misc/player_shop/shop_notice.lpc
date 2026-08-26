/**
 * @author Ringo
 * @started 21st September 1999
 */
inherit "/std/object";

private nosave string _office, _stock_policy;

void setup()
{
   set_name( "notice" );
   set_short( "policy notice" );
   set_long( "This is the list of shop's policies.  The policies "
      "on this notice are definitive and final." );
   add_adjective( "policy" );
   add_extra_look( this_object() );
   reset_get();
}
/* setup() */


/**
 * @ignore yes
 * Where to get the data from?
 */
void set_office( string office )
{ 
   _office = office;
   _stock_policy = _office->get_stock_policy();
}
/* set_office() */


/**
 * @ignore yes
 * Chart display
 */
string extra_look( object thing )
{
   int i;
   string display = "", policy;
   mapping policies;

   if ( thing == this_object() )
   {
      display = sprintf( "  This shop deals strictly in %s.  "
        "Items that do not fit this description should not be "
        "stocked.\n\n", "%^BOLD%^"+ _stock_policy+ "%^RESET%^" );
      policies = _office->get_policies();
      if ( !m_sizeof( policies ) )
      {
         return display;
      }
      i = 1;
      foreach( policy in m_indices( policies ) )
      {
         if( _office->query_manager( this_player()->query_name() ) || 
             _office->query_retired( this_player()->query_name() ) )
         {
            display += sprintf( "%d [%s]. %s\n", i++, policy, policies[policy] );  
         }
         else
         {
            display += sprintf( "%d. %s\n", i++, policies[policy] );  
         }    
      }
      return display;
   }
}
/* extra_look() */
