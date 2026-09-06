#include <const/cityconst.h>

void add_citizen( string city_name, string person );

// Cities may be registered before they're built, in which case they will be of type UNBUILT
mapping cities;
mapping rooms;

void create() {
   restore_object("/daemon/citydata");
   if (!mappingp(cities))
      cities = ([ ]);
   if (!mappingp(rooms))
      rooms = ([ ]);
}

void reset() {
   save_object("/daemon/citydata");
}

string destructor( object src ) {
   save_object("/daemon/citydata");
   return 0;
}

mapping query_cities() {
   return cities;
}

mapping query_rooms() {
   return rooms;
}

string worldtrim( string str ) {
   return ((str[0..5] == "world;")?str[5..]:str);
}

int city_exists( string city_name ) {
   return member(cities, city_name);
}

void add_city( string city_name, string mayor ) {
   city_name = lower_case(city_name);

   if (city_exists(city_name))
      return;

   cities[city_name] = ([ "rooms": ([ ]), "mayor": mayor, "type": UNBUILT ]);
}

void remove_city( string city_name ) {
   if (!city_exists(city_name))
      return;

   foreach(string room : rooms)
      if ( rooms[room] == city_name )
         rooms -= ([ room ]);
   cities -= ([ city_name ]);
}

int query_city_type( string city_name ) {
   if (city_exists(city_name))
      return cities[city_name]["type"];
   else
      return -1;
}

void set_city_type( string city_name, int type ) {
   if (!city_exists(city_name))
      return;

   cities[city_name]["type"] = type;
}

void add_room( string city_name, string room ) {
   if (!city_exists(city_name))
      return;
   room = worldtrim( room );

   cities[city_name]["rooms"] += ([ room ]);
   rooms[room] = city_name;
}

void remove_room( string city_name, string room ) {
   if (!city_exists(city_name))
     return;
   room = worldtrim( room );

   cities[city_name]["rooms"] -= ([ room ]);
   rooms-= ([ room ]);
}

string get_city_by_room( string room ) {
   room = worldtrim( room );

   if (member(rooms, room))
      return rooms[room];

   return 0;
}

string query_mayor( string city_name ) {
   if (city_exists(city_name))
      return cities[city_name]["mayor"];
   else
      return 0;
}

void set_mayor( string city_name, string mayor ) {
   if (!city_exists(city_name))
      return;

   cities[city_name]["mayor"] = mayor;
   add_citizen( city_name, mayor );
}

mapping query_citizens( string city_name ) {
   if( !city_exists(city_name) )
      return 0;
   if( !mappingp(cities[city_name]["citizens"]) )
      cities[city_name]["citizens"] = ([ ]);
   return cities[city_name]["citizens"];
}

void set_citizens( string city_name, mapping x ) {
   cities[city_name]["citizens"] = x;
}

int query_is_citizen( string city_name, string person ) {
   return member( query_citizens(city_name), person );
}

void add_citizen( string city_name, string person ) {
   // The query forces the mapping to exist.
   query_citizens(city_name);
   cities[city_name]["citizens"] += ([ person ]);
}

void remove_citizen( string city_name, string person ) {
   // The query forces the mapping to exist.
   query_citizens(city_name);
   cities[city_name]["citizens"] -= ([ person ]);
}

int query_annex_problem( string city_name, object room ) {
   // 1. Specify valid input information.
   if( !city_name || !room )
      return -99;
   if( get_city_by_room(get_location(room)) == city_name )
      return -6;
   // 2. Make sure the city is valid.
   if( !city_exists(city_name) )
      return -5;
   // 3. If you can't build there, you can't annex it.
   if( !room->query_can_build() )
     return -1;
   // 4. The buildings must belong exclusively to citizens
   // of the city.
   object ob;
   int building_count = 0;
   int adjacent_room_found = 0;
   foreach( ob : all_inventory(room) ) {
      if( ob->query_is_building() ) {
         if( ob->queury_owner() && !query_is_citizen(city_name, ob->query_owner()) )
            return -2;
         if( ob->query_owner() )
            building_count++;
      }
      if( ob->query_is_exit() ) {
         string other = ob->query_link();
         if( environment(room) ) {
            object room_ob = find_room( other, environment(room) );
            if( room_ob ) {
               string room_loc = get_location( room_ob );
               if( get_city_by_room(room_loc) == city_name )
                  adjacent_room_found = 1;
            }
         }
      }
   }
   // 5. There must be at least 2 owned buildings in the room.
   if( building_count < 2 )
      return -3;

   // 6. There must be an adjacent room belonging to the city.
   if( !adjacent_room_found )
      return -4;

   // 7. You can annex it.
   return 0;
}