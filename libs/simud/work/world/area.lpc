#include <inven.h>
#include <desc.h>
#include <tiledmap.h>
#include <object.h>
#include <const/plantconst.h>
#include <const/climate.h>

/** This file defines the area object, which is used for organizing
 * the world into meaningful regions. Area objects may contain either
 * other area objects, or rooms. The outermost area objects are themselves
 * contained by the world object, making the MUD a complete hierarchy.
 *
 * Areas behave as "tiled maps" which means that they allow you to
 * define a grid on which your rooms are arranged; this is useful
 * for many things, primarily building the room maps or shapes.
 *
 * Areas have gone through quite a few design iterations, during
 * which time we constantly change our mind as to what we're using
 * them for. In general, they are a method for hierarchically organizing
 * rooms.
 */

/// An internal cache of room objects, stored as a mapping. Update the object to refresh it.
nosave mapping room_map;

NAME( "_blank_area" )
SHORT( "A blank area" )
LONG( "This is an area object probably undefined." )
LOOK( "You're in an area object. Type 'wi env' to see its contents" )
TYPE( "area" )

/// Current weather in this area.
string weather;
/// Climate for this area.
string climate;

/** Initializes the area object; the default area is 'blank'.
 * Note that init_exits is called in the create() function to
 * set up the exits object properly (this is necessary for
 * inheriting that object.
 */
void create() {
   ::create();
   call_out( "growth_tick", random(GROWTH_DELAY * 60) );
   call_out( "weather_tick", random(WEATHER_DELAY * 60) );
}

/** This is used by find_room. If an object implements get_room_ob(), it
 * can use something faster than present() for identifying its contents.
 * The goal is to use a hash table for room lookup rather than looping through
 * the inventory, which grants a big speedup on large areas.
 */
object get_room_ob( string name ) {
   if( !room_map ) {
      object ob;
      room_map = ([ ]);
      foreach( ob : all_inventory(this_object()) )
         room_map[ob->query_name()] = ob;
   }
   return room_map[name];
}

void reset_room_map() {
   room_map = 0;
}

void growth_tick() {
   object ob;
   int x = 0;

   remove_call_out( "growth_tick" );
   call_out( "growth_tick", GROWTH_DELAY * 60 );

   foreach( ob: filter(all_inventory(), (: $1->query_is_room() :)) )
      call_out( "room_growth", 2 + 5 * x++, ob );
}

void room_growth( object room ) {
   object *plants;
   object ob;

   if( !room ) return;
   plants = filter( all_inventory(room), (: $1->query_is_plant() :) );

   debug("Growing room " + room->query_name() + " at " + get_location(room), "gp-plant");

   foreach( ob: plants ) {
      ob->crowding_check();
   }
   foreach( ob: plants ) {
      ob->on_grow();
   }
}

/** As a side effect, this delays the weather tick a bit.
 * This is to avoid certain oscillating problems if adjacent
 * areas are trying to shift conditions in different directions;
 * effectively, the first to shift wins.
 */
void set_weather( string x ) {
   remove_call_out( "weather_tick" );
   call_out( "weather_tick", WEATHER_DELAY * 60 );
   weather = x;
}

string query_weather() {
   return weather;
}

/** Sets the climate to \a x and the weather to "clear", which is a required
 * weather type in all climates (though you can define clear however you
 * want).
 */
void set_climate( string x ) {
   climate = x;
   weather = "clear";
}

string query_climate() {
   return climate;
}

void weather_tick() {
   remove_call_out( "weather_tick" );
   call_out( "weather_tick", random(WEATHER_DELAY * 60) + WEATHER_DELAY * 60 );

   "/daemon/climate"->weather_tick(this_object());
}

string query_weather_desc() {
   return "/daemon/climate"->query_weather_desc(query_climate(), query_weather());
}

/// \return True. A simple way of identifying if this is an area.
int query_is_area() {
   return 1;
}
