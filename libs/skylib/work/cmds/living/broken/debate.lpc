#include <tasks.h>

#define EFFECT "/std/effects/religious/theological_debate"
#define HANDLER "/handlers/philosophies"

#define DEBATE_MULT 4

inherit COMMAND_BASE;

mixed *debaters = ({ });

mixed cmd( object *indirect_obs, string indir_match, string dir_match,
      mixed *args, string pattern ) {
   int i, bonus;
   string topic, type, needed;
   object target;
   if ( sizeof( (int *)this_player()->effects_matching( "debating" ) ) )
      return notify_fail( "You are already engaged in a debate.\n" );
   i = member_array( this_player(), debaters );
   if ( ( i != -1 ) && !( i % 3 ) ) {
      if ( objectp( debaters[ i + 1 ] ) )
         if ( environment( this_player() ) ==
               environment( debaters[ i + 1 ] ) )
            return notify_fail( "You have already challenged "+
                  (string)debaters[ i + 1 ]->the_short() +" to a debate.\n" );
      debaters = delete( debaters, i, 3 );
   }
   target = indirect_obs[ 0 ];
   if ( target == this_player() )
      return notify_fail( "How can you hold a debate with yourself?  "
            "What are you, schizoid?\n" );
   if ( userp( target ) && !interactive( target ) )
      return notify_fail( "How can you debate anything with a net-dead "
            "statue?\n" );
   topic = args[ 0 ];
   if ( ( i != -1 ) && ( i % 3 == 1 ) ) {
      if ( objectp( debaters[ i - 1 ] ) )
         if ( ( debaters[ i - 1 ] == target ) &&
               ( debaters[ i + 1 ] == topic ) ) {
            write( "You accept "+ (string)target->the_short() +
                  "'s challenge to debate "+ topic +".\n" );
            say( (string)this_player()->the_short() +" accepts "+
                  (string)target->the_short() +"'s challenge to debate "+
                  topic +".\n", target );
            tell_object( target, (string)this_player()->the_short() +
                  " accepts your challenge to debate "+ topic +".\n" );
            debaters = delete( debaters, i - 1, 3 );
            this_player()->add_effect( EFFECT, target );
            target->add_effect( EFFECT, this_player() );
            return 1;
         } 
   }
   if ( !HANDLER->query_philosophy( topic ) )
      return notify_fail( "You cannot debate \""+ topic +"\".  You can "+
            "debate "+ query_multiple_short( (string *)HANDLER->
            query_philosophy_names() ) +".\n" );
   type = (string)HANDLER->query_philosophy_type( topic );
   bonus = (int)HANDLER->query_philosophy_bonus( topic );
   needed = (string)HANDLER->query_philosophy_needed( topic );
   if ( (int)this_player()->query_skill_bonus( type +".points" ) < bonus )
      return notify_fail( needed +" is not sufficient to debate "+
            topic +" at the moment.\n" );
   if ( (int)this_player()->query_specific_gp( type ) < bonus )
      return notify_fail( "You are too tired to debate "+ topic +
            " at the moment.\n" );
   this_player()->adjust_gp( -(bonus*DEBATE_MULT) );
   if ( ( i != -1 ) && ( i % 3 == 1 ) ) {
      if ( objectp( debaters[ i - 1 ] ) )
         if ( environment( this_player() ) ==
               environment( debaters[ i - 1 ] ) )
            tell_object( debaters[ i - 1 ], "Your challenge is ignored.\n" );
      debaters = delete( debaters, i - 1, 3 );
   }
   write( "You challenge "+ (string)target->the_short() +" to a debate on "+
         topic +".\n" );
   say( (string)this_player()->one_short() +" challenges "+
         (string)target->one_short() +" to a debate on "+ topic +".\n",
         target );
   tell_object( target, (string)this_player()->one_short() +
         " challenges you to a debate on "+ topic +".\n" );
   debaters += ({ this_player(), target, topic });
   call_out( "answer_challenge", 5, this_player(), target, topic );
   return 1;
} /* cmd() */

void answer_challenge( object challenger, object target, string topic ) {
   int i, bonus, diff;
   string type;
   if ( !challenger )
      return;
   if ( !target )
      return;
   if ( environment( challenger ) != environment( target ) )
      return;
   i = member_array( challenger, debaters );
   if ( ( i == -1 ) || ( i % 3 ) )
      return;
   if ( ( debaters[ i + 1 ] != target ) || ( debaters[ i + 2 ] != topic ) )
      return;
   if ( pk_check( challenger, target ) ) {
      tell_object( target, "Use \"debate "+ topic +" with "+
            (string)challenger->query_name() +
            "\" to accept the challenge.\n" );
      return;
   }
   type = (string)HANDLER->query_philosophy_type( topic );
   bonus = (int)target->query_skill_bonus( type +".points" );
/* Query the challenger last as it'll be (s)he who is awarded a level. */
   diff = (int)target->query_skill_bonus( type +".points" ) / 3;

   switch ( (int)TASKER->perform_task(challenger, type+".points", 2 * diff,
                                      TM_COMMAND) ) {
      case AWARD :
        tell_object( challenger, "You feel "+
                     (string)HANDLER->query_philosophy_needed( topic ) +
                     " surge for a moment.\n" );
      case SUCCEED :
         tell_object( target, "You find yourself accepting "+
               (string)challenger->the_short() +"'s challenge to debate "+
               topic +".\n" );
         tell_room( environment( target ), (string)target->the_short() +
               " accepts "+ (string)challenger->the_short() +
               "'s challenge to debate "+ topic +".\n",
               ({ target, challenger }) );
         tell_object( challenger, (string)target->the_short() +
               " accepts your challenge to debate "+ topic +".\n" );
         debaters = delete( debaters, i, 3 );
         this_player()->add_effect( EFFECT, target );
         target->add_effect( EFFECT, this_player() );
         return;
      default :
         if ( userp( target ) )
            tell_object( target, "Use \"debate "+ topic +" with "+
                  (string)challenger->query_name() +
                  "\" to accept the challenge.\n" );
   }
} /* answer_challenge() */

mixed *query_debaters() { return debaters; }

mixed *query_patterns() {
   return ({ "<word'topic'> with <indirect:living'person'>",
         (: cmd( $1, $2, $3, $4, $5 ) :) });
} /* query_patterns() */
