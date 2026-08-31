/*******************************************************
 * Sky System - Created by Whit 12-04                  *
 * Uses advanced swapping.  Need to run tests on CPU   *
 * usages.                                             *
 *******************************************************/


mapping data, swap, ships;

#include <std.h>
#define TRUE 1
#define FALSE 0
/*
 * FIXED_ROOMS
 *  This is for rooms in the sky that should not be swapped out and are hard-coded rooms 
 *  and not clones of sky_room.c
 * FIXED_ROOMS ([ "({ x, y, z})":"filename" ])
 *
 */
#define FIXED_ROOMS ([ "({ 32, 23, 1 })":"/d/warwick/air" ])
#include <std.h>
#include <daemons.h>
#include <sky.h>

int *get_graphcoord_from_mudcoord(int *coord) {
    int x2,y2,x1,y1, *i, x3,y3;
    x2 = coord[0]; y2 = coord[1];
    i = this_object()->query_zero();
    x1 = i[0]; y1 = i[1];
    x3 = x2-x1;
    y3 = y1 - y2;
    return ({x3, y3});
}

int *get_mudcoord_from_graphcoord(int *coord) {
    int x2,y2, x1, y1, *i, x3, y3;
    x2 = coord[0]; y2 = coord[1];
    i = this_object()->query_zero();
    x1 = i[0]; y1 = i[1];

    x3 = x2 - x1;
    y3 = y1 - y2;
    return ({ x3 , y3 });
}

int *query_coord_from_letter(string str) {
    int a, y;
    a = MAX_OCEAN_Y;
    while(a--)     {
	if (strsrch(ocean_map[a], str)!=-1) 	{
	    y = a;
	    a = sizeof(ocean_map[a]);
	    while(a--)
		if (ocean_map[y][a..a]==str)
		    return ({a,y,0});
	}
    }
    if (str != "S")
      return query_coord_from_letter("S");
}

string query_symbol(string name) {
   string *k;
   int i;
   i=sizeof(k=keys(ROOMS));
   while(i--) {
     if(lower_case(ROOMS[k[i]]["name"])==lower_case(name)) return k[i];
   }
   return 0;
}

int *query_zero() { return ZERO; }

int valid_xy(int *coord) {
    int x=coord[0], y=coord[1];

    if (ocean_map[y][x..x]=="#") return FALSE;
    return TRUE;
}

string get_line(int *c, int size) {
   string out="";
   int i;
   for(i=0; i<size; i++) {
     out += this_object()->get_xy( ({ c[0]-i, (c[1]) }) );
   }
   return out;
}

string get_xy(int *coord) {
    int x=coord[0], y=coord[1];
    int tempx, tempy;
    tempx=copy(x);
    tempy=copy(y);
    if(tempx <= 1) tempx=MAX_OCEAN_X-1;
    if(tempx > MAX_OCEAN_X-1) tempx=1;
    if(tempy <= 1) tempy=MAX_OCEAN_Y-1;
    if(tempy > MAX_OCEAN_Y-1) tempy=1;
    return ocean_map[tempy][tempx..tempx];
}

object get_room(int *c) {
   object o;
   if(!swap[identify(c)]) {
     o=new(SKY_ROOM); 
     o->set_coords(copy(c));
     swap[identify(c)]=o;
   } else {
     o=swap[identify(c)];
   }
   return o;
}

mapping swaps() { return swap; }

void cleanup_s() {
   int i;
   string *k;
   i=sizeof(k=keys(data));
   if(i>30) i=30;
   while(i--) {
     if(!find_player(k[i]) || base_name(environment(find_player(k[i]))) != SKY_ROOM) 
       map_delete(data, k[i]);
   }
   i=sizeof(k=keys(swap));
   if(i>30) i=30;
   while(i--) {
     if(!swap[k[i]]) { map_delete(swap, k[i]); continue; }
     if(!sizeof(all_inventory(swap[k[i]]))) { swap[k[i]]->swap_out(); map_delete(swap, k[i]); }
   }
   call_out("cleanup_s", 60);
}

void create() {
   int i;
   i=sizeof(FIXED_ROOMS);
   swap=([]);
   while(i--) {
     swap[keys(FIXED_ROOMS)[i]]=find_object_or_load(FIXED_ROOMS[keys(FIXED_ROOMS)[i]]);
   }
   data=([]);
   ships=([]);
   call_out("cleanup_s", 60);
   call_out("load_ships", 2);
}

void load_ships() {
   int i;
   string *s;
   s = keys(SHIPS);
   i=sizeof(s);
   while(i--) {
     ships[s[i]]=([]);
     ships[s[i]]["object"]=new("/std/room/airship");
     ships[s[i]]["object"]->set_location(query_coord_from_letter( SHIPS[s[i]]["letter"] ));
     ships[s[i]]["object"]->set_location_name(SHIPS[s[i]]["airport"]);
     ships[s[i]]["object"]->set_name(SHIPS[i]);
   }
}

object query_ship(string ship) {
   if(!ships[ship]) return 0;
   return ships[ship]["object"];
}

int *query_ship_location(string ship) {
   if(!ships[ship]) return 0;
   if(!ships[ship]["object"]) return 0;
   return ships[ship]["object"]->query_location();
}

mapping ships() { return ships; }
