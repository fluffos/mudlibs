inherit "/battle/weapon";

NAME( "sharov" )
ALT_NAME( ({ "sword", "broadsword" }) )
LOOK( "A wide-bladed sword pounded from blue steel. It is deceptively light for its size. It lacks a hilt and the handle is wrapped in worn black leather. The name 'Sharov' is engraved repeatedly over the entire surface of the blade." )
DISTANT( "Sharov" )
SPECIFIC( "Sharov" )
PLURAL( "sharoven" )
ALT_PLURAL( ({ "swords", "weapons", "broadswords" }) )
TYPE( "weapon" )
WEAPON_TYPE( "sword" )
TASTE( "It tastes like blueberry icecream." )

WEIGHT( 1000 )   // A bit over 2lbs, average swords are 3lbs
BULK( 250 )      // Twice the volume that this mass of steel should occupy
VALUE( 1000000 ) // An abstractly large value

GETTABLE( 1 )
DROPPABLE( 1 )

nosave int charged = 0;
#define COOLDOWN	600		// 10 minutes

void create() {
   ::create();
   set_wc( (["ice":7, "edged":10]) );
   set_requirement( (["str":15, "dex":18]) );
   set_unbreakable( 1 );
}

void cooldown() {
   remove_call_out( "cooldown" );
   if( this_object()->query_held() ) {
      msg_object(environment(),"~[090Sharov pulses strongly in your hand, ready to be used again.~CDEF");
      charged = 1;
   }
}

int on_hold() {
   call_out( "cooldown", COOLDOWN );
   return 0;
}

int on_use() {
   if( !this_object()->query_held() ) {
      msg("You must be wielding Sharov in order to use him.");
	  return 0;
   }
   if( !charged ) {
      msg("Sharov is not yet fully recharged.");
      return 0;
   }
   if( !environment()->query_in_combat() ) {
      msg("You may only use Sharov while in combat.");
	  return 0;
   }
   charged = 0;
   call_out( "cooldown", COOLDOWN );
   environment()->add_readiness( 1000 );
   set_actor( environment() );
   set_target( this_object() );
   environment()->msg_local("~CTIT~Name ~verbtighten ~poss grip on ~targ as a wave of light washes over ~pron.~CDEF");
   return 1;
}

mapping query_aspects() {
   return ([ C_WEAPON, C_SWORD, C_BLADE, C_POMMEL, C_HILT, C_GUARD, C_METAL, C_STEEL ]);
}
