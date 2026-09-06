#include <object.h>
#include <saveload.h>
#include <condition.h>
#include <apparel.h>
#include <item.h>

ICON( '[', 0x8B, LAYER_ITEMS )

mapping query_aspects() {
  return ([ C_CLOTHING ]);
}

int on_drop( object player ) {
   if( !::on_drop(player) ) return 0;
   if( query_held() ) {
      set_held( 0 );
      player->msg_local( "~CACT~Name ~verbtake off ~poss " + query_name() + " and ~verbdrop it.~CDEF" );
      return MOVE_SILENCE_FLAG | MOVE_OK_FLAG;
   }
   else return MOVE_OK_FLAG;
}

int on_give( object giver, object receiver ) {
   if( !::on_give(giver, receiver) ) return 0;
   if( query_held() ) {
      set_held( 0 );
      giver->msg_local( "~CACT~Name ~verbtake off ~poss " + query_name() + " and ~verbgive it to " + receiver->query_specific() + ".~CDEF" );
      return MOVE_SILENCE_FLAG | MOVE_OK_FLAG;
   }
   else return MOVE_OK_FLAG;
}
