#include <battle.h>
#include <item.h>
#include <inven.h>
#include <condition.h>
#include <object.h>
#include <apparel.h>
#include <armour.h>
#include <const.h>
#include <const/raceconst.h>
#include <armour.h>

mapping aspect_data = ([]);

mapping query_aspects() {
   //debug( "Armour's query_aspect called" );
   return aspect_data;
}

void add_aspect( int m_data ) {
   aspect_data += ([ m_data ]);
}

void add_aspects( mapping m_data ) {
   //debug( "ADD aspects called" );
   aspect_data += m_data;
   //msg( as_lpc(aspect_data) );
}

void set_aspects( mapping m_data ) {
   //debug( "SET_ASPECTS Called" );
   aspect_data = m_data;
}

void remove_aspects( mapping m_data ) {
   aspect_data -= m_data;
}

int query_use_bonuses() {
   return !!query_worn();
}
