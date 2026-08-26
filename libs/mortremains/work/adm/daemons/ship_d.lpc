// ship_d.c - The Shipping Daemon.
// (05-09-00) Written from scratch by Chronos, while listening to
//            Jungle Boogie, by K0ol and the Gang.  Get Down, Get Down!
// This program controls all of the ships in the world, making them
// arrive/depart in various rooms (ports) throughout the world.
// It handles a query-able database to allow ship schedules to be reported
// various objects.
// Functions:
// start_ships() -> called from create(), makes sure all the ships are
//                  loaded.
// schedule_info() -> Returns a string with all of the ships in the daemon,
//                    where they are, and where they are going next.
// query_current_port -> Returns the short description of the current
//                       room that a ship is in.
// query_next_port -> Returns the short description of the next port that
//                    a ship is scheduled to move to.
// get_shipdata_pos -> Returns the int referring to the element of the array
//                     that holds all the ship movement data.

#include <mudlib.h>
#include <ships.h>

inherit DAEMON;

void start_ships();
// void move_ship(object ship, string filename) ;
string schedule_info() ;
string query_current_port(string filename);
string query_next_port(string filename);
int get_shipdata_pos(string filename) ;
string *query_port_data(string filename) ;
int *query_port_time(string filename) ;

// "hidden" ->  Only set when you don't want a ship to appear in the 
//              scheduling information database.  ie - Pirates probably
//              announce their coming and going..   ;)
mapping * ship_data = ({
  ([ "name" :"USS Saipan",
      "filename": "/d/Ocean/ships/saipan",
     "port_list" : ({ "/d/Prime/Norva/rooms/pier1-1",
                              "/d/Prime/Norva/rooms/pier3-2",
                             "/d/Prime/Norva/rooms/pier2-1",
                              "/d/Prime/Norva/rooms/pier1-2",
   "/d/Prime/Norva/rooms/pier4-2" }) ,
     "port_time" : ({ 12,22,7,10,4 }) ,
     "hidden"   : 0 ,
  ]) ,
  ([ "name" : "Pirate Ship",
     "filename": "/d/Ocean/ships/pirate",
     "port_list" : ({ "/u/c/chronos/area2/rooms/pier1-2",
                      "/u/c/chronos/area2/rooms/pier2-1",
                      "/u/c/chronos/area2/rooms/pier3-2",
                      "/u/c/chronos/area2/rooms/pier4-2" }),
     "port_time" : ({ 12,13,5,10 }) ,
      "hidden" : 1 ,  // Arr We don't wanna be seen ye scurvy dogs!
  ]) ,
                 }) ;

void create() {
  seteuid(getuid()) ;
  start_ships() ;
}

// Accepts either the filename of the ship, or the Ship's name.
string query_current_port(string filename) {
  object ship;
  int i;
  if (!filename) return "Unknown." ;
  ship = find_object_or_load(filename) ;
  if (!ship) {
    i = get_shipdata_pos(filename) ;
    if (i) ship = find_object_or_load(ship_data[i]["filename"]) ;
  }
  if (!ship) return "Unknown." ;
  ship = environment(ship) ;
  if (!ship) return "Unknown." ;
  return ship->query("short") ;
}

string *query_port_data(string filename) {
  int i;
  string *work ;
  i = get_shipdata_pos(filename) ;
  if (i==-1) return ({ }) ;
  work = ship_data[i]["port_list"] ;
  return work;
}

int *query_port_time(string filename) {
  int i;
  i = get_shipdata_pos(filename) ;
  if (i!=-1) return ship_data[i]["port_time"] ;
  else return 0 ;
}

string query_next_port(string filename) {
  int x,i;
  string where, final;
  string *portlist;
  object ship;
  final = "Unknown.";
  ship = find_object_or_load(filename) ;
  x = get_shipdata_pos(filename) ;
  if (!ship && x != -1)
    ship = find_object_or_load(ship_data[x]["filename"]) ;
  if (ship) {
    ship->init() ;
    i = ship->query_port() ;
    portlist=ship_data[x]["port_list"];
    where = portlist[i] ;
    for(i=0;i<sizeof(portlist);i++) {
      if (where==portlist[i]) {
        if (sizeof(portlist)==i) final=portlist[0] ;
        else final = portlist[i+1];
        break ;
      }
    }
    final = find_object_or_load(final)->query("short") ;
  }
  return final ;
}

string schedule_info() {
   string data;
  int i ;
   data = "" ;
   for(i=0;i<sizeof(ship_data);i++) {
     if (ship_data[i]["hidden"]) continue ;
     data += sprintf("%-20s %-25s %-25s\n",
           ship_data[i]["name"],
        query_current_port(ship_data[i]["filename"]),
        query_next_port(ship_data[i]["filename"]),
    );
   }
   return data;
}

int get_shipdata_pos(string filename) {
  int x, i ;
  x=-1;
  for(i=0;i<sizeof(ship_data);i++) {
    if (filename == ship_data[i]["filename"]) {
      x = i ;
      break;
    }
  }
  if (filename=="/std/ship_ob") return 0 ;
  return x;
}

void start_ships() {
  int i;
  object ship ;
  for(i=0;i<sizeof(ship_data);i++) {
    ship = find_object_or_load(ship_data[i]["filename"]) ;
    ship->move(find_object_or_load(ship->query("home_port"))) ;
    ship->init() ;
  }
  return ;
}
