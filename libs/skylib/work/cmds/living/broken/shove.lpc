
#include <dirs.h>
#include <tasks.h>

inherit COMMAND_BASE;

mixed cmd( object *indirect_obs, string *args) {
   string verb, word, *bits, *exits;
   object ob;
   
   if ( !creatorp(TP) )
      return 0;
   if ( this_player()->query_property( "dead" ) )
      return notify_fail( "You're dead.  You can't shove anything.\n" );
   if ( !living( indirect_obs[ 0 ] ) )
      return notify_fail( "You can't shove "+
            (string)indirect_obs[ 0 ]->the_short() +
            "; try dragging it.\n" );
   verb = args[ 1 ];
   bits = explode( args[ 1 ], " " );
   if ( sizeof( bits ) > 1 )
      word = implode( bits[ 1 .. ], " " );
   else
      word = "";
   if ( LENGTHEN[ verb ] )
      verb = LENGTHEN[ verb ];
   exits = (string *)environment( this_player() )->query_exits();
   if ( !exits )
      return notify_fail( "There don't seem to be any exits here.\n" );
   /*
    * Put this here, because the same message is needed, but "verb"
    * may change.
    */
   notify_fail( "There is no exit \""+ verb +"\".\n" );
   if ( member_array( verb, exits ) != -1 ) {
      if ( environment( this_player() )->query_relative( verb ) )
         return 0;
   } else {
      verb = (string)this_player()->reorient_rel( verb );
      if ( member_array( verb, exits ) == -1 )
         return 0;
      verb = (string)indirect_obs[ 0 ]->find_rel( verb );
   }
   foreach(ob in indirect_obs) {
     if(this_player() == ob)
       continue;
     
     if(!ob->exit_command( verb ) )
       return notify_fail( "Ack!  Something went wrong!\n" );
   }
   return 1;
} /* cmd() */

mixed *query_patterns() {
   return ({ "<indirect:living> <word'direction'> [stealthily]",
         (: cmd($1, $4) :),
               });
} /* query_patterns() */
