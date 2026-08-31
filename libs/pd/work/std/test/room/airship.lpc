/*******************************************************
 * Sky System - Created by Whit 12-04                  *
 * Airships - Allows regular players the ability       *
 * to fly.                                             *
 *******************************************************/

#include <teststd.h>
inherit ROOM;
#include <sky.h>
#include <daemons.h>
#define fail(x) { write(""+x); return 1; }

int *original, *location, *dest;
int ct;

void create() {
   ::create();
   set_short("Flying in the Sky");
   set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1 ]) );
}

void set_destination(int *c) {
   string sym;
   dest=c;
   set_heart_beat(1);
   sym=SKY_D->get_xy(c);
   message("", "The ship "+query_name()+" will fly to "+this_object()->query_destination_name()+" and will leave soon.", 
     (mixed)ROOMS[sym]["airport"]);
}

int in_transit() { return query_heart_beat(); }

int *query_destination() { return dest; }
string query_destination_name() { return ROOMS[SKY_D->get_xy(dest)]["name"]; }

void set_location(int *c) { 
   location=c; 
   if(!sizeof(original)) { 
     original=copy(c); 
     add_exit(ROOMS[SKY_D->get_xy(c)]["airport"], "ladder");
   } 
}
int *query_location() { return location; }
string query_location_name() { if(!ROOMS[SKY_D->get_xy(location)]) return ""; return ROOMS[SKY_D->get_xy(location)]["name"]; }
int *query_original() { return original; }

void init() {
   ::init();
   add_action("fly", "fly");
}

int fly(string s) {
   string *k, sym;
   int i;

   if(!s || s=="") fail("Syntax: <fly [location]> or <fly list>");
   if(s=="list") {
     i=sizeof(k=keys(ROOMS));
     write("You my fly to the following places: \n"
           "-------------------------------------------------");
     while(i--) {
       if(ROOMS[k[i]]["airport"]) write(ROOMS[k[i]]["name"]);
      }
     return 1;
   }
   if(dest) fail("The ship is already in flight.");
   sym=SKY_D->query_symbol(s);
   if(!sym || !ROOMS[sym]["airport"]) fail("You cannot fly there!");
   write("The ship begins to fly into the sky.");
   set_destination(SKY_D->query_coord_from_letter(sym));
   return 1;
}

void heart_beat() {
   string sym;
   int moved;
   ct++;
//message("", "dest="+identify(dest)+" location="+identify(location), this_object());
   remove_exit("ladder");
   if(ct > 0) {
     if(dest[0] != location[0]) {
       if(dest[0] > location[0]) location[0]++; else
                                 location[0]--;
       moved=1;
     } else
     if(dest[1] != location[1]) {
       if(dest[1] > location[1]) location[1]++; else
                                 location[1]--;
       moved=1;
     }
     if(moved && even(ct)) message("", "The ship rocks a little as it continues its journey.", 
       this_object());
     if(dest[0] == location[0] && dest[1] == location[1] && !moved) {
       if(location[0] == original[0] && location[1] == original[1]) {
         set_heart_beat(0);
         sym=SKY_D->get_xy(original);
         message("", "The ship "+query_name()+" has returned.",
           (mixed)ROOMS[sym]["airport"]);
         message("", "The ship has returned to "+query_destination_name()+".", this_object());
         ct=0;
         dest=0;
         add_exit(ROOMS[sym]["airport"], "ladder");
         return;
       }
       sym=SKY_D->get_xy(original);
       message("", "The ship "+query_name()+" has landed and will return to "+
         ROOMS[SKY_D->get_xy(original)]["name"]+" soon.",
         (mixed)ROOMS[SKY_D->get_xy(location)]["airport"]	);
       message("", "The ship lands in "+query_destination_name()+" and lets you off.", this_object());
       call_out("return_ship", 5, SKY_D->query_coord_from_letter(sym));
       message("", ROOMS[SKY_D->get_xy(location)]["airport"], this_object());
       all_inventory(this_object())->move_player(ROOMS[SKY_D->get_xy(location)]["airport"]);
       set_heart_beat(0);
       return;
     }
   }
}

void return_ship(int *c) {
   string sym=SKY_D->get_xy(c);
   dest=c;
   message("", "The ship "+query_name()+" is returning to "+
     this_object()->query_destination_name()+".",
     (mixed)ROOMS[sym]["airport"]);
   message("", "The ship begins its flight back to "+query_destination_name()+".", this_object());
  
   set_destination(c);
}

string query_long() {
   string out="";
   out += "This is a massive airship.  It is used to traverse throughout the realms.\n\n";
   if(!in_transit() && query_location_name()) out += "The ship is docked at "+query_location_name(); else
   out += "The ship is in flight.";
   return out;
}

