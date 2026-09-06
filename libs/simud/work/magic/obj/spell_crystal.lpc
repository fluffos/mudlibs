#include <item.h>
#include <desc.h>
#include <object.h>
#include <magic.h>
#include <saveload.h>

ICON( '*', 11, LAYER_ITEMS )
ALT_NAME( ({ "crystal", "spell crystal" }) )
WEIGHT( 2600 )
BULK( 1000 )
GETTABLE( 1 )
DROPPABLE( 1 )

int mana_type;
int mana_quantity;
int mana_capacity;

void set_mana_type(int x);

/*
void create() {
	::create();
	// hopefully, this should prevent crystals from being blanked any more
	if( mana_type )
		set_mana_type( mana_type );
}
*/

string query_mana_color(int x) {
   switch ( x ) {
      case C_FIRE_MANA: return "blood red";
      case C_ICE_MANA: return "greenish blue";
      case C_EARTH_MANA: return "blue green";
      case C_SPIRIT_MANA: return "pale yellow";
      case C_DARK_MANA: return "charcoal black";
      case C_WATER_MANA: return "pure white";
      case C_LIGHTNING_MANA: return "royal purple";
      case C_WIND_MANA: return "bright yellow";
      case C_ORDER_MANA: return "dull brown";
      case C_CHAOS_MANA: return "pulsing orange";
   }

   return "broken";
}

//Added to allow for alt names to include mana type//
string query_mana_type_name(int x) {
   switch ( x ) {
      case C_FIRE_MANA: return "fire";
      case C_ICE_MANA: return "ice";
      case C_EARTH_MANA: return "earth";
      case C_SPIRIT_MANA: return "spirit";
      case C_DARK_MANA: return "dark";
      case C_WATER_MANA: return "water";
      case C_LIGHTNING_MANA: return "lightning";
      case C_WIND_MANA: return "wind";
      case C_ORDER_MANA: return "order";
      case C_CHAOS_MANA: return "chaos";
   }

   return "broken";
}

string query_mana_tild_color(int x) {
   switch ( x ) {
      case C_FIRE_MANA: return "~[010";
      case C_ICE_MANA: return "~[060";
      case C_EARTH_MANA: return "~[020";
      case C_SPIRIT_MANA: return "~[110";
      case C_DARK_MANA: return "~[080";
      case C_WATER_MANA: return "~[150";
      case C_LIGHTNING_MANA: return "~[050";
      case C_WIND_MANA: return "~[110";
      case C_ORDER_MANA: return "~[030";
      case C_CHAOS_MANA: return "~[030";
   }

   return "~CWRN";
}

string query_taste() {
	return capitalize(query_mana_color( mana_type ));
}

string query_distant() {
	return "a "+query_mana_color( mana_type )+" spell crystal";
}


string query_name() {
	return query_mana_color( mana_type )+" crystal";
}

string query_specific() {
	return "the "+query_mana_color( mana_type )+" spell crystal";
}

string query_plural() {
	return query_mana_color( mana_type )+" spell crystals";
}

string *query_alt_plural() {
	string color = query_mana_color( mana_type );
        string mana_name = query_mana_type_name( mana_type );
	return( ({ color+" crystals", mana_name+" crystals",
                   color+" spell crystals", mana_name+" spell crystals",
                  "crystals", "spell crystals" }) );
}

string *query_alt_name() {
	string color = query_mana_color( mana_type );
        string mana_name = query_mana_type_name( mana_type );
	return( ({ color+" crystal", mana_name+" crystal",
                   color+" spell crystal", mana_name+" spell crystal",
                  "crystal", "spell crystal" }) );
}

void set_mana_type(int x) {
   mana_type = x;
}
/*
   set_distant( "a "+color+" spell crystal" );
   set_alt_name( ({"crystal","spell crystal"}) );
   set_name(color+" crystal");
   set_specific( "the "+color+" spell crystal" );
   set_plural( color+" spell crystals" );
   set_alt_plural( ({ color+" crystals", color+" spell crystals", "crystals", "spell crystals" }) );
}
*/
int query_mana_type() { return mana_type; }

void set_mana_capacity(int x) { mana_capacity = x; }
int query_mana_capacity() {
   if( !mana_capacity )
      mana_capacity = 1000;
   return mana_capacity;
}

void set_mana_quantity(int x) {
   mana_quantity = x;
   if( mana_quantity < 0 )
      mana_quantity = 0;
   if( mana_quantity > mana_capacity )
      mana_quantity = mana_capacity;
}
int query_mana_quantity() { return mana_quantity; }
void add_mana(int x) {
   set_mana_quantity( mana_quantity + x );
}

int query_fill_percent() {
   return min(100, 100 * query_mana_quantity() / query_mana_capacity());
}

string query_fill_string() {
   int x = query_fill_percent();
   if( x == 100 )
      return "completely full";
   else if ( x > 90 )
      return "almost full";
   else if ( x > 75 )
      return "very full";
   else if ( x > 50 )
      return "about half full";
   else if ( x > 25 )
      return "less than half full";
   else if ( x > 5 )
      return "barely charged at all";
   else
      return "almost empty";
}

string query_look() {
   string buf = "It is a glowing " + query_mana_tild_color(mana_type) + query_mana_color(mana_type) + "~CDEF quartz crystal that has been magically altered in order to serve as a repository for ~CBRT"+MAGIC_DAEMON->query_mana_string(mana_type)+"~CDEF mana.\n";
   if( query_fill_percent() == 100 )
      buf += "It is completely charged.";
   else
      buf += "It is "+query_fill_string()+". You could ~CCOMuse~CDEF it if you wanted to charge it with some more mana.";
   return buf;
}

mapping query_aspects() {
   // agreed, this is a silly hack, but it lets us distinguish crystal types
   // for crafting.
   return ([ (query_fill_percent() == 100?C_CRYSTAL:C_QUARTZ), mana_type ]);
}

int on_use() {
   int need = query_mana_capacity() - query_mana_quantity();
   int have = this_player()->query_mana();
   int real_need;

   if( environment() != this_player() ) {
      msg("You have to be holding a crystal to impart mana to it.");
      return 0;
   }
   string plane = MAGIC_DAEMON->query_mana_string(mana_type);
   if( plane == "unknown" ) {
      msg("That spell crystal is broken. Please try using ~CCOMfixcrystal~CDEF to repair it, or contact a wizard for a replacement.");
      return 0;
   }
   if( !need ) {
      if( !mana_quantity ) {
         msg("~CWRNThat crystal was barely created! Give it a chance to settle down a bit.~CDEF");
		 return 0;
      }
      msg("~CWRNThe crystal is already full! Using it any more could be dangerous.~CDEF");
      return 0;
   }
   if( !have ) {
      msg("You don't have any mana to charge the crystal with.");
      return 0;
   }
   real_need = MAGIC_DAEMON->query_cost(plane, need);
   if ( have >= real_need ) {
      MAGIC_DAEMON->draw_mana(this_player(),plane,need);
      add_mana(need);
	  this_player()->practice_skill_conditional("magic.mana."+plane, 50, need / 10);
	  debug("practicing "+plane+" for "+need / 10,"magic");
   } else {
      MAGIC_DAEMON->draw_mana(this_player(),plane,have);
      this_player()->set_mana(0);
      add_mana(have);
	  this_player()->practice_skill_conditional("magic.mana."+plane, 50, have / 10);
	  debug("practicing "+plane+" for "+have / 10,"magic");
   }
   this_player()->practice_skill_conditional("magic.technique.channeling", 75, 1);
   set_actor(this_player());
   set_target(this_object());
   this_player()->msg_local("~CACT~Name ~verbfocus ~poss magical energies into ~targ.");
   msg("~CBRT~Targ is now "+query_fill_string()+".~CDEF");
   return 1;
}
