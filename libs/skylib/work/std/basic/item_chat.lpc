/**
 * This class handles atmospheric chat messages.
 */

#include <room.h>

int off, inhibit;
mixed *chats, *saved_chats;

void item_chat( mixed *args );
void check_chat();
mixed *query_chats() { return chats; }
mixed *query_saved_chats() { return saved_chats; }

/** @ignore yes */
void init() {
   /* do we have any chats? */
   if ( chats )
      check_chat();
} /* init() */

/**
 * This method adds atmospheric chat messages to the object.
 * The array which is passed into the object has three
 * elements, the first element is the minimum time between chats, the second
 * parameter is the maximum time bewteen chats and the third parameter
 * is the list of actual chats.
 * <p>
 * Item chats are strings which are printed at (semi) random
 * intervals to living objects holding or in the same room as
 * someone holding the object. Currently they will not be
 * heard outside containers. They are used to add
 * atmosphere to an Item. A chat will be picked at random
 * from the array of chats with a frequency controlled by the
 * times min and max. ie. one will be picked every n seconds
 * where is varies between min and max seconds. Please
 * don't make the values for min and max too small or the
 * messages just become annoying!
 * <p>
 * Currently, there's a maximum on the min/max values, every
 * value higher than 320 seconds is treated as that.
 * <p>
 * The chats can contain one of $a_short$, $the_short$ and
 * $poss_short$ which will be replaced with the
 * corresponding value.
 * <p>
 * To call a function defined on the item in place of a chat message
 * use "#function_name" in place of a chat string.
 * <p>
 * To use item chats, the object needs to inherit
 * "/std/basic/item_chat" and if the object defines an init()
 * function, that function should also call ::init()
 * <p>
 * To make the chatting object save the values, it's necessary
 * to define a couple of supporting functions in the item:
 * <pre>
 * mapping query_dynamic_auto_load() {
 *   mapping tmp;
 *
 *   tmp = ([ "::" : object::query_dynamic_auto_load(),
 *            "chat" : item_chat::query_dynamic_auto_load(), ]);
 *   return tmp;
 * } \/\* query_dynamic_auto_load() *\/
 *
 * void init_dynamic_arg(mapping map) {
 *   if (map["::"])
 *     object::init_dynamic_arg(map["::"]);
 *   if (map["chat"])
 *     item_chat::init_dynamic_arg(map["chat"]);
 * } /\* init_dynamic_arg() *\/
 *
 * </pre>
 * Use object in the previous if the object is inheriting /std/object, if not,
 * then use whatever it's inheriting from instead.
 * @example item_chat( ({ 120, 240,
 *            ({ "A revolting smell drifts from $the_short$.",
 *              "Something rustles in $the_short$." }) }) );
 */
void item_chat( mixed *args ) {
   int i;

   if ( !args )
      return;
   if ( !sizeof( args[ 2 ] ) )
      return;
   off = 0;
   inhibit = 0;
   saved_chats = args + ({ });
   chats = saved_chats + ({ 0 });
   chats[ 2 ] = saved_chats[ 2 ] + ({ });
   i = sizeof( chats[ 2 ] );
   while( i-- )
      chats[ 2 ][ i ] =  replace( chats[ 2 ][ i ], ({
         "$a_short$", TO->a_short(),
         "$the_short$", TO->the_short(),
         "$poss_short$", TO->poss_short() }) );
} /* item_chat() */

/**
 * Checks to see if the object is interactive.
 * @return 1 if it is interactive
 * @see efun::interactive()
 */
int check_interactive( object thing ) { return interactive( thing ); }

/**
 * This starts the object chatting.  This is done automaticly when entering
 * the presence of an interactive object
 * @see item_chat()
 * @see chat_off()
 */
void chat_on() {
   off = 0;
   check_chat();
} /* chat_on() */

/**
 * This stops the object chatting.  This is done automaticly when leaving
 * the prescence of all interactive objects.
 * @see chat_on()
 * @see item_chat()
 */
void chat_off() {
   off = 1;
} /* chat_off() */

/**
 * This method does the actual chat, it prints a message
 * and figures that stuff out.
 * @see item_chat()
 * @see chat_on()
 * @see chat_off()
 */
void make_chat() {
   int saying;
   string stuff;
   object env, *targets, target;

   inhibit = 0;
   if ( !environment( TO ) ) {
      off = 1;
      return; /* I'm in limbo, no need to nag anything */
   }
   saying = random( sizeof( chats[ 2 ] ) );
   if ( saying == chats[ 3 ] )
      saying = ( saying + 1 ) % sizeof( chats[ 2 ] );
   chats[ 3 ] = saying;
   stuff = chats[ 2 ][ saying ];
   env = environment( TO );
   if ( !environment( env ) ) {
      /* I'm in a room, or in a person in limbo or in a thing in limbo */
      if ( !(sizeof(targets = filter_array( ({ env }) + all_inventory( env ),
                            "check_interactive", TO ) ) ) ) {
         off = 1; /* nobody want to listen to me *sob* */
         return;
      } else {
         if ( stuff[ 0 ] == '#' )
            call_other( TO, stuff[ 1 .. ] );
         else
            foreach( target in targets )
               tell_object( target, chats[ 2 ][ saying ] +"\n" );
      }
   } else { /* I'm in a person in a room or in a sack in a person or room */
      if ( !(sizeof( targets = filter_array( all_inventory( environment( env ) ),
                          "check_interactive", TO ) ) ) ) {
         off = 1; /* nobody want to listen to me *sob* */
         return;
      } else {
         if ( stuff[ 0 ] == '#' )
            call_other( TO, stuff[ 1 .. ] );
         else
            foreach( target in targets )
               tell_object( target, chats[ 2 ][ saying ] +"\n" );
      }
   }
   ROOM_HANDLER->add_chatter( TO, chats[ 0 ] +
                             random( chats[ 1 ] - chats[ 0 ] + 1 ) );
} /* make_chat() */

/**
 * This method makes sure that we are chatting if we should be.
 * @see chat_on()
 * @see item_chat()
 * @see make_chat()
 */
void check_chat() {
   if ( inhibit || off || !pointerp( chats ) )
      return;
   inhibit = 1;
   ROOM_HANDLER->add_chatter( TO,
         ( chats[ 0 ] + random( chats[ 1 ] - chats[ 0 ] + 1 ) ) / 2 );
} /* check_chat() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
   mapping tmp;

   tmp = ([ "off" : off,
            "chats" : saved_chats,
          ]);
   return tmp;
} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {
   if ( !map )
      return;
   if ( map[ "chats" ] )
      saved_chats = map[ "chats" ];
   item_chat( saved_chats );
   if ( !map[ "off" ] )
      chat_on();
} /* init_dynamic_arg() */
