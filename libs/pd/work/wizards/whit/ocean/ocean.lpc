/*
 Ocean Daemon by Seeker 06/02/2000
 Parts redone by Whit 11/24/2009
*/

#undef NO_COMBAT
object *get_present_ships(int *coord);
object ship_present(string from, string to);
object find_player_ship(string p);

#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include "ocean.h"
#include "ocean_map.h"

int *query_zero() {
    return ZERO; 
}

int *get_graphcoord_from_mudcoord(int *coord) {
    int x2,y2,x1,y1, *i, x3,y3;

    x2 = coord[0];
    y2 = coord[1];

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
    while(a--) {
        if (strsrch(ocean_map[a], str)!=-1) {
            y = a;
            a = sizeof(ocean_map[a]);
            while(a--) {
                if (ocean_map[y][a..a]==str) {
                    return ({a,y});
                }
            }
        }
    }

    return ({});

}

int valid_xy(int x, int y) {

    if(x <= 1) x=MAX_OCEAN_X-1;
    if(x > MAX_OCEAN_X-1) x=1;
    if(y <= 1) y=MAX_OCEAN_Y-1;
    if(y > MAX_OCEAN_Y-1) y=1;

    if (x>=MAX_OCEAN_X || y>=MAX_OCEAN_Y || x<=0 || y<=0) {
        return STRONG_CURRENTS;
    }

    if (ocean_map[y][x..x]=="*") return STRONG_CURRENTS;
    if (ocean_map[y][x..x]=="+") return LAND;
    if (ocean_map[y][x..x]=="#") return ICE;

    return OK_TO_MOVE;

}

string get_xy(int x, int y) {
    int tempx, tempy;

    tempx=copy(x);
    tempy=copy(y);

    if(tempx <= 1) tempx=MAX_OCEAN_X-1;
    if(tempx > MAX_OCEAN_X-1) tempx=1;
    if(tempy <= 1) tempy=MAX_OCEAN_Y-1;
    if(tempy > MAX_OCEAN_Y-1) tempy=1;

    return ocean_map[tempy][tempx..tempx];

}

string get_beach(string a) {
    return beach[a];
}

string get_dock(string a) {
    return docks[a];
}

object *get_present_ships(int *coord) {
    object *o, *out;
    int x,y,i;

    o=children(SHIP);
    out=({});
    x=coord[0]; y=coord[1];
    i=sizeof(o);
    while(i--) {
        if(x==o[i]->query_xy()[0] && y==o[i]->query_xy()[1]) out += ({ o[i] });
    }

    return out;

}

object find_player_ship(string p) {
    object *o, out;
    int i;

    o=children(SHIP);
    i=sizeof(o);
    while(i--) {
        if(o[i]->query_owner()==p) out=o[i];
    }

    return out;

}

object ship_present(int *c, string to) {
    object *o, toship;
    int x,x2,y,y2;
    toship=find_player_ship(to);
    if(!toship) return 0;
    x=c[0];
    y=c[1];
    x2=toship->query_xy()[0];
    y2=toship->query_xy()[1];
    if(x==x2 && y==y2) {
        return toship;
    }
}

void notify_ships(string owner, string dir) {
    object o, *ships;

    o=find_player_ship(owner);
    ships=get_present_ships(o->query_xy());
    ships-=({o});
    if(dir == "in")
	message("", "%^BOLD%^%^BLUE%^"+capitalize(owner)+"'s ship sails around near here.%^RESET%^\n", ships); else
	message("", "%^BOLD%^%^BLUE%^"+capitalize(owner)+"'s ship sails to the "+dir+".%^RESET%^\n", ships);
}

void emote() {
    object *all, *a, *b;
    string *msg;
    int i;

    all=children(SHIP);
    i=sizeof(all);
    b=({}); a=({});
    while(i--) {
        if(get_xy(all[i]->query_xy()[0], all[i]->query_xy()[1]) == "%" || get_xy(all[i]->query_xy()[0], all[i]->query_xy()[1]) == "@") {
    	    b += ({all[i]});
        } else{
            a += ({all[i]});
        }
    }

    if(!query_night()) {
        msg=DAY_EMOTE;
    } else {
        msg=NIGHT_EMOTE;
    }

    i=random(sizeof(msg));
    message("ship-emote", "%^BOLD%^"+msg[i]+"%^RESET%^", a);
    msg=STORM_EMOTE;
    i=random(sizeof(msg));
    message("ship-emote", "%^BOLD%^%^BLUE%^"+msg[i]+"%^RESET%^", b);   
    call_out("emote", EMOTE_TIME);

}
/*
void load_all_ships() {
    int i, *coord;
    string *files, *t;
    object o;

#ifndef STATIC_SHIPS
    return;
#endif

    coord=query_coord_from_letter("A");
    i=sizeof(files=get_dir(DIR_SHIPS));
    while(i--) {
        o=find_player_ship(files[i][0..sizeof(files[i])-3]);
        if(o) continue;
        o=new(SHIP);
        o->set_owner(files[i][0..sizeof(files[i])-3]);
        o->load(files[i][0..sizeof(files[i])-3]);
        if(o->query_sunk()) {
            o->set_xy(o->query_sunk()[0], o->query_sunk()[1]); 
        } else {
            o->set_xy(coord[0], coord[1]);
            o->set_docked("/d/nopk/tirun/loadb");
        }
    }
//  Load Static Ships
    i=sizeof(t=keys(STATIC_SHIPS));
    while(i--) {
        o=new(SHIP);
        o->set_owner(STATIC_SHIPS[t[i]]["owner"]);
        o->set_xy(STATIC_SHIPS[t[i]]["coords"][0], STATIC_SHIPS[t[i]]["coords"][1]);
        o->set_is_static_ship(1);
        o->set_start_room(STATIC_SHIPS[t[i]]["room"]);
        o->set_ocean_short(STATIC_SHIPS[t[i]]["short"]);
    }
}
*/

void load_static_ships() {
    int i;
    string *t;
    object o;

#ifndef STATIC_SHIPS
    return;
#endif

    i=sizeof(t=keys(STATIC_SHIPS));
    while(i--) {
        o=new(SHIP);
        o->set_owner(STATIC_SHIPS[t[i]]["owner"]);
        o->set_xy(STATIC_SHIPS[t[i]]["coords"][0], STATIC_SHIPS[t[i]]["coords"][1]);
        o->set_is_static_ship(1);
        o->set_start_room(STATIC_SHIPS[t[i]]["room"]);
        o->set_ocean_short(STATIC_SHIPS[t[i]]["short"]);
    }

}

int ship_combat_on() {
#ifndef NO_COMBAT
    return 1;
#else
    return 0;
#endif
}

void create() {
    call_out("emote", 20);
    load_static_ships();
}

