/*******************************************************
 * Sky System - Created by Whit 12-04                  *
 * Airport - Where players board airships for          *
 * travel                                              *
 *******************************************************/

#include <std.h>
inherit ROOM;
#include <sky.h>
#include <daemons.h>
string symbol;

void set_letter(string a) { symbol=a; }
string query_letter() { return symbol; }
void init() {
   ::init();
   add_action("read", "read");
   add_action("board", "board");
}

void create() { set_letter("S"); }

int read(string s) {
   string *k, *out=({});
   mapping ships;
   object ship;
   int i;
   k=keys(ROOMS);
   for(i=0; i<sizeof(k); i++) {
     if(ROOMS[k[i]]["airport"]) out += ({ ROOMS[k[i]]["name"] });
   }
   out -= ({ ROOMS[symbol]["name"] });
   if(!s || s != "sign") return notify_fail("Read what?\n");
   write("The sign reads: \n"
   "----------------------------------------------\n"
   "The following is a list of current flights: \n");
   ships = SKY_D->ships();
   i=sizeof(k=keys(ships));
   while(i--) {
     ship=ships[k[i]]["object"];
     if(ship->in_transit() && ARRAYTOOL_D->same_array(ship->query_destination(), ship->query_original()))
       write("   "+k[i]+": Returning to "+ship->query_destination_name()); else
     if(ship->in_transit()) 
       write("   "+k[i]+": In transit to "+ship->query_destination_name()); else
     if(ship->query_location_name() != ROOMS[query_letter()]["name"]) 
       write("   "+k[i]+": Docked at "+ship->query_location_name()); else
     write("   "+k[i]+": Ready for transport.");
   }
   write("You may fly to these locations by typing <board [aircraft]>");
   return 1;
}

int board(string str) {
   mapping s;
   object o;
   if(!str || str=="") return notify_fail("Board what?\n");
   s=SKY_D->ships();
   if(!s[str]) return notify_fail("No such ship.\n");
   o=s[str]["object"];
   if(o->query_location_name() != ROOMS[query_letter()]["name"]) return
     notify_fail("That ship is not here!\n");
   write("You board the "+o->query_name());
   this_player()->move_player(o, "onto the "+o->query_name());
   return 1;
}

