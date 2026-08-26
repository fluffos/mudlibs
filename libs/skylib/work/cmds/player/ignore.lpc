inherit COMMAND_BASE;

string *do_clean( string *people ) {
    return filter( people, (: ( find_player($1) || rank($1) ) &&
                                !creatorp($1) :) );
} /* do_clean() */

int cmd_list() {
   string *ignoring;

   if( !ignoring = TP->query_property("ignoring") )
       ignoring = ({ });

   if( !sizeof( ignoring = do_clean( ignoring ) ) ) {
       TP->remove_property("ignoring");
       write( "You are not ignoring anyone.\n" );
   } else  {
       ignoring = sort_array( ignoring, 1 );
       write( "You are currently ignoring " +
              query_multiple_short( map( ignoring, (: CAP($1) :) ) ) +
              ".\n" );
   }
   return 1;
} /* cmd_list() */

int cmd( string str ) {
   string *ignoring;


   if( !ignoring = TP->query_property("ignoring") )
       ignoring = ({ });

   if( !sizeof( ignoring = do_clean( ignoring ) ) )
       TP->remove_property("ignoring");

   if( ( str = lower_case( TP->expand_nickname(str) ) ) == TP->query_name() ) {
       add_failed_mess( "You cannot ignore yourself.\n" );
       return 0;
   }

   if( !find_player(str) && !rank(str) )  {
       add_failed_mess("Ignoring someone that doesn't exist?  Is this some "
                       "kind of zen?\n");
       return 0;
   }

   if( creatorp(str) ) {
       add_failed_mess("You cannot ignore creators, if you have an issue "
           "with a creator, please talk to the admin to solve it.\n");
       return 0;
   }

   if( member_array( str, ignoring ) == -1 )  {
       ignoring += ({ str });
       TP->add_property("ignoring", ignoring );
       write("You are now ignoring "+CAP(str)+".\n");
       return 1;
   }

   add_failed_mess( "You are already ignoring "+CAP(str)+".\n" );
   return 0;

} /* cmd() */

mixed *query_patterns() {
   return ({ "<string'person'>", (: cmd($4[0]) :),
             "", (: cmd_list() :) });
} /* query_patterns() */
