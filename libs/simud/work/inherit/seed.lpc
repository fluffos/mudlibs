#include <const.h>

/** This component allows you to make an object into
 * a seed. The seed component defines a variable, plant_type,
 * which tells you what the seed turns into when it grows.
 * It also defines a default on_plant event, which is what
 * gets called when the seed is planted, and simply creates
 * a new plant.
 */

/// The file name of the plant template (i.e. /econ/plants/...)
string plant_type;

/// The amount of stored energy this seed gets to start off with.
int seed_strength;

/// Get plant_type
string query_plant_type() {
   return plant_type;
}

/// Get seed_strength
int query_seed_strength() {
   return seed_strength;
}

/// Set plant_type to \a x.
void set_plant_type( string x ) {
   plant_type = x;
}

/// Set seed_strength to \a x.
void set_seed_strength( int x ) {
   seed_strength = x;
}

int on_plant( int pos ) {
   object plant;

   if( !plant_type || !environment() )
      return 0;

   plant = clone_object( plant_type );
   plant->move(environment());
   plant->set_coord( pos );
   plant->set_size( 0 );
   plant->set_energy( query_seed_strength() );
   return 1;
}

string seed_info() {
   return "plant_type\nseed_strength";
}
