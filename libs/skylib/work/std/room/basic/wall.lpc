/**
 * This is a wall object.  It is added to rooms when you use the set_wall()
 * function to add a climable wall exit to a room.  If you wish to have
 * players climb somewhere this is the preferred method to use.
 *
 * @author Deutha
 * @see climb
 * @see /std/room.c
 * @see /std/rooftop.c
 */
string *belows;
mixed *bottom, *moves;
object room;

void create() {
   belows = ({ });
   bottom = 0;
   moves = ({ });
} /* create() */

void setup_shadow( object thing ) {
   shadow( thing, 1 );
   room = thing;
} /* setup_shadow() */

void destruct_shadow( object thing ) {
   if ( thing == TO )
      destruct( TO );
   else
      thing->destruct_shadow( thing );
} /* destruct_shadow() */

string *query_belows() { return copy( belows ); }
mixed *query_bottom() { return copy( bottom ); }
mixed *query_moves() { return copy( moves ); }

int query_at_bottom() { return !bottom; }

mixed *query_move( string word ) {
   int i;
   i = member_array( word, moves );
   if ( i == -1 )
      return 0;
   return moves[ i + 1 .. i + 3 ];
} /* query_move() */

void calc_co_ord() {
   int i, delta, *co_ord;
   string word, other;
   room->calc_co_ord();
   if ( co_ord )
      return;
   foreach ( word in ({ "down", "up" }) ) {
      i = member_array( word, moves );
      if ( i == -1 )
         continue;
      other = moves[ i + 2 ];
      if ( !find_object( other ) )
         continue;
      co_ord = copy( (int *)other->query_co_ord() );
      if ( !co_ord )
         continue;
      delta = (int)room->query_room_size() + (int)other->query_room_size();
      if ( word == "down" )
         co_ord[ 2 ] += delta;
      else
         co_ord[ 2 ] -= delta;
      room->set_co_ord( co_ord );
      return;
   }
} /* calc_co_ord() */

void set_wall( mixed *args ) {
   int i, j;
   mixed arg;
   for ( i = sizeof( args ) - 2; i > -1; i -= 2 ) {
      arg = args[ i + 1 ];
      switch ( args[ i ] ) {
         case "bottom" :
            bottom = arg;
            room->add_property( "here", "falling past you" );
            break;
         case "below" :
            belows += arg;
            break;
         case "move" :
            j = member_array( arg[ 0 ], moves );
            if ( j == -1 )
               moves += arg;
            else
               moves[ j + 1 .. j + 3 ] = arg[ 1 .. 3 ];
            break;
      }
   }
} /* set_wall() */

void event_enter( object thing, string mess, object from ) {
   room->event_enter( thing, mess, from );
   if ( !living( thing ) && bottom )
      call_out( "fall_down", 0, thing );
} /* event_enter() */

void fall_down( object thing ) {
   int damage;
   string word;
   if ( !thing )
      return;
   if ( environment( thing ) != room )
      return;
   damage = (int)room->query_room_size();
   if ( sizeof( belows ) )
      foreach ( word in belows ) {
         tell_room( find_object( word ), (string)thing->a_short() +
               " $V$0=falls,fall$V$ past you and $V$0=is,are$V$ gone.\n" );
         damage += 2 * (int)word->query_room_size();
      }
   if ( stringp( bottom ) ) {
      if ( living( thing ) )
         thing->move_with_look( bottom,
               "$N fall$s from above with a loud thump.",
               "$N drop$s downwards out of sight." );
      else
         thing->move( bottom,
               "$N fall$s from above with a loud thump.",
               "$N drop$s downwards out of sight." );
      return;
   }
   word = bottom[ 0 ];
   damage += (int)word->query_room_size();
   if ( stringp( bottom[ 1 ] ) )
      if ( living( thing ) )
         thing->move_with_look( word, call_other( word, bottom[ 1 ], thing,
               room ), "$N drop$s downwards out of sight." );
      else
         thing->move( word, call_other( word, bottom[ 1 ], thing, room ),
               "$N drop$s downwards out of sight." );
   else
      if ( living( thing ) ) {
         thing->move_with_look( word,
               "$N fall$s from above with a loud crunch.",
               "$N drop$s downwards out of sight." );
         damage *= bottom[ 1 ] * (int)thing->query_complete_weight();
         damage /= 10000;
         damage -= (int)thing->query_ac( "blunt", damage );
         if ( damage > 0 )
            if ( (int)thing->adjust_hp( -damage ) < 0 )
               thing->attack_by( room );
            else
               tell_object( thing, "Ouch, that hurt!\n" );
      } else
         thing->move( word,
               "$N fall$s from above with a loud thump.",
               "$N drop$s downwards out of sight." );
} /* fall_down() */
