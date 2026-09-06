#include <const/climate.h>

/** Defines climates.
 *
 * All climates must have a "clear" weather pattern; this is the base weather
 * for new areas, so you do need it.
 *
 * A climate consists of a group of weather 'nodes', connected by transitions.
 * This should be really easy for anyone with a rudimentary understanding of
 * graph theory. Transitions are unidirectional, which allows you to have
 * lengthy scripted weather patterns if you wish.
 *
 * To create your own weather patterns, take a peek at the create() function.
 */

// Array lookup positions
#define WP_DESC  0
#define WP_TYPE  1
#define WP_TRANS 2

/// A big ugly mapping with all the climate info. You should probably leave it alone.
mapping climates = ([ ]);

/// Accessor for climates mapping
mapping query_climates() {
   return climates;
}

/// Setter for climates mapping
void set_climates( mapping m ) {
   if( mappingp(m) ) climates = m;
}

/// Get the mapping for a single climate.
mapping query_climate( string type ) {
   return climates[type];
}

/// Set the mapping for a single climate.
void set_climate( string type, mapping m ) {
   climates[type] = m;
}

/// Return the information on a single weather pattern in a single climate.
mapping query_weather( string c, string w ) {
   return climates[c][w];
}

/// Set the weather information on a single weather pattern in a single climate.
void set_weather( string c, string w, mapping val ) {
   climates[c][w] = val;
}

/// \return True if weather1 and weather2 have a transition between them (in either direction).
int query_adjacent( string climate, string weather1, string weather2 ) {
   mapping iclim = climates[climate];

   if( member(iclim[weather1][WP_TRANS], weather2) ||
      member(iclim[weather2][WP_TRANS], weather1) )
      return 1;

   return 0;
}

/** This function builds a weather pattern structure based on the parameters.
 * Basically, use it as a constructor for weather patterns. This will allow
 * you to add new fields later if you like without breaking all the old code.
 */
mixed *weather_pattern( string desc, int type ) {
   return ({ desc, type, ([ ]) });
}

/** A setter function that adds a new weather type. See create().
 */
void weather( string climate, string name, mixed pattern ) {
   if( !climates[climate] ) climates[climate] = ([ name: pattern ]);
   else climates[climate] += ([ name: pattern ]);
}

/** A setter function to add a transition. See create().
 */
void transition( string climate, string src, string dest, string message ) {
   if( !mappingp(climates[climate]) )
      raise_error( "Can't add transition to climate " + climate + ", it's undefined." );
   if( !pointerp(climates[climate][src]) )
      raise_error( "Can't add transition to weather type " + climate + ":" + src + ", it's undefined." );

   climates[climate][src][WP_TRANS][dest] = message;
}

/** \return A mapping of transitions away from a given weather pattern.
 */
mapping query_transitions( string climate, string weather ) {
   if( !mappingp(climates[climate]) || !pointerp(climates[climate][weather]) )
      raise_error("query_transitions(): Weather type " + climate + ":" + weather + " not defined.");
   return climates[climate][weather][WP_TRANS];
}

/** This function sets up all weather patterns for all the climates in the game and
 * is necessarily long. If desired, the various climates could be split up into
 * other files.
 *
 * There are two basic functions here: weather() to add a new weather type to a
 * particular climate, and transition() to add the transitions that connect
 * weather patterns together. To make a climate, simply stitch these building
 * blocks together. Take a look at include/const/climate.h for a list of available flags.
 */
void create() {
   weather( "continental", "clear",
      weather_pattern(
        "The sky is clear and cloudless, with the ?(ISNIGHT:stars):(sun) shining brightly. The air is still and quiet.",
        W_CLEAR | W_ALLYEAR | W_MILD)
   );
   transition( "continental", "clear", "breeze",
      "The wind starts to pick up a little." );

   weather( "continental", "breeze",
      weather_pattern(
        "The sky is clear and cloudless, and a gentle breeze is blowing.",
        W_CLEAR | W_ALLYEAR | W_MILD | W_WIND)
   );
   transition( "continental", "breeze", "clear",
      "The gentle breeze dies down, and the air is still." );
   transition( "continental", "breeze", "cloudy breeze",
      "Patches of clouds have appeared, ?(ISNIGHT:warming):(cooling) the air slightly." );

   weather( "continental", "cloudy breeze",
      weather_pattern(
        "The sky is spattered with splotches of clouds, and a gentle breeze is blowing.",
        W_CLOUDY | W_ALLYEAR | W_MILD | W_WIND)
   );
   transition( "continental", "cloudy breeze", "breeze",
      "The clouds are gradually clearing, and you can see the ?(ISNIGHT:stars):(sun) shining through more clearly." );
   transition( "continental", "cloudy breeze", "cloudy",
      "The gentle breeze fades." );

   weather( "continental", "cloudy",
      weather_pattern(
        "The sky is spattered with splotches of clouds. The air is still.",
        W_CLOUDY | W_ALLYEAR | W_MILD)
   );
   transition( "continental", "cloudy", "cloudy breeze",
      "A soft breeze starts to blow." );

   weather( "continental", "cloudy windy",
      weather_pattern(
        "The wind blows roughly, and the sky is cloudy.",
        W_CLOUDY | W_ALLYEAR | W_MILD | W_WIND)
   );
   transition( "continental", "cloudy windy", "cloudy breeze",
      "The wind fades to a gentler breeze." );
}

/// \return The weather flags associated with a particular weather type.
int query_flags( string clim, string weath ) {
   return climates[clim][weath][WP_TYPE];
}

/** An internally used function to pick a valid transition between two weather types.
 * This is where seasons are implemented.
 */
string choose_transition( string climate, mapping trans, int season ) {
   string *season_trans;

   // First off, try to eliminate transitions that aren't allowed
   // in the current season.
   season_trans = filter( m_indices(trans), (: query_flags(climate, $1) | season :) );
   // Wasn't able to find a transition without breaking season rules.
   if( !sizeof(season_trans) )
      season_trans = m_indices(trans);

   return season_trans[random(sizeof(season_trans))];
}

/** Shift weather on object \a ob, which is generally an area.
 */
void weather_tick( object ob ) {
   mapping transitions;
   string climate, weather, new_weather;
   int curr_season;
   object iplayer;

   climate = ob->query_climate();
   weather = ob->query_weather();

   if( !climate || !weather ) return;

//   debug("weather tick!", "weather");

   transitions = query_transitions( climate, weather );
   curr_season = "/daemon/time"->query_season();

//   debug("transitions are " + as_string(transitions), "weather");
//   debug("curr_season is " + curr_season, "weather");

   // Pick a node to transition to.
   new_weather = choose_transition( climate, transitions, curr_season );
//   debug("new_weather is " + new_weather, "weather");

   ob->set_weather( new_weather );
   // Make neighboring areas match up.... (not done yet)
   foreach( iplayer : users() ) {
      if( environment(iplayer) && environment(environment(iplayer)) == ob &&
         !iplayer->query_env_var("Tnoweather") )
         msg_object( iplayer, "~CSC4" + transitions[new_weather] + "~CDEF" );
   }
}

/// \return The text description associated with a type of weather.
string query_weather_desc( string climate, string weather ) {
   if( !climate || !weather ) return 0;
   return climates[climate][weather][WP_DESC];
}
