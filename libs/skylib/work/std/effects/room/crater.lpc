/* 
* @main
* A nice little effect so that witches who plummet out of the sky
* when their brooms break in midflight will leave a crater in the
* ground where they fall.  
*
* add_effect is called in the crash site; the name of the victim
* is passed to the effect.  The arg of the effect is an array of
* strings, each of which is the name of someone who's landed in
* that particular crash site.
*
* @classification room.crater.broom
* @see help::effects
*/

#include <effect.h>

/** @ignore */
string query_classification() { return "room.crater.broom"; }

/** @ignore */
mixed beginning( object room, string name ) {
  
  room->add_item( ({ name + " shaped crater", "crater" }),
      "There is a large crater in the ground, as if " + 
      capitalize( name ) + " happened here recently, from a "
      "very great height indeed." );

  room->add_extra_look( this_object() );

  return ({ name });

} /* beginning() */

/** @ignore */
mixed merge_effect( object room, mixed old_names, string name ) {

  room->add_item( ({ name + " shaped crater", "crater" }),
      "There is a large crater in the ground, as if " + 
      capitalize( name ) + " happened here recently, "
      "from a very great height indeed." );

  return old_names += ({ name });

} /* merge_effect() */


/** @ignore */
void end( object room, mixed names ) {
  string name;
   
  /* remove the items that were added for each crash */
  foreach( name in names )  {
    room->remove_item( name + " shaped crater" );
  }

  room->remove_extra_look( this_object() );

} /* end() */

/** @ignore */
int query_indefinite() { return 1; }  /* don't end effect */

string extra_look( object room ) {
   int     *enums;          /* Effect numbers */
   int     iterator, size;
   string  *shapes;         /* Who made the crater */
   string  crater;          /* The description to return */

   /* Find out the effect number we have */
   enums = room->effects_matching( query_classification() );

   /* Make sure we have something to show them... */
   if( !sizeof( enums ) )
     return "";

   /* Check the args.  We should only have one effect, since we
    * take care of merging */
   shapes = room->arg_of( enums[0] );
   if( !sizeof( shapes ) )
     return "";

   if( sizeof( shapes ) == 1 )
     crater = "There is " + add_a( capitalize( shapes[0] ) ) + 
         " shaped crater in the ground.\n";
              
   else {
     crater = "There are " + capitalize( shapes[0] );
     iterator = 0; size = sizeof( shapes );

     while( ++iterator < size ) {
       if( iterator != size - 1 )
         crater += ", ";
       else
         crater += " and ";
       crater += capitalize( shapes[iterator] );
     }
     crater += " shaped craters in the ground.\n";
   }

   return crater;
} /* extra_look() */
