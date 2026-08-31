#include <std.h>
#include "/wizards/seeker/labyrinth/defs.h"
inherit DAEMON;
inherit LABRYS;

mixed *rooms;

int random_contents() { return random(2) + random(2) + random(2) +
random(2); }

mapping make_new_room() {
    mapping results;
    int i,j;
    results = ([
    "exits" : ({ }),
    "obj" : ({ }),
    "mons" : ({ }),
    "items" : ({ }),
    "room" : (random(8))
  ]);
i = !(random(11)<4);
if(i) { i = random_contents(); }
j = random(10);
while(i--) {
    while(member_array(j,results["mons"])+1) {
        j = random(10);
    }
    results["mons"] += ({ j });
}
i = !(random(11)<4);
if(i) { i = random_contents(); }
j = random(10);
while(i--) {
    while(member_array(j,results["obj"])+1) {
        j = random(10);
    }
    results["obj"] += ({ j });
}
i = random_contents();
j = random(15);
while(i--) {
    while(member_array(j,results["items"])+1) {
        j = random(15);
    }
    results["items"] += ({ j });
}
return results;
}

string get_direction(int x,int y,int z) {
    switch(x) {
    case -1: {
            switch(y) {
            case -1: { return "southwest"; }
            case 0: { return "south"; }
            case 1: { return "southeast"; }
            default: { error("No such direction.\n"); }
            }
        }
    case 0: {
            switch(y) {
            case -1: { return "west"; }
            case 0: {
                    switch(z) {
                    case -1: { return "down"; }
                    case 1: { return "up"; }
                    default: { error("No such direction.\n"); }
                    }
                }
            case 1: { return "east"; }
            default: { error("No such direction.\n"); }
            }
        }
    case 1: {
            switch(y) {
            case -1: { return "northwest"; }
            case 0: { return "north"; }
            case 1: { return "northeast"; }
            default: { error("No such direction.\n"); }
            }
        }
    default: { error("No such direction.\n"); }
    }
}

void create_labyrinth(int x,int y,int z) {
    // Create a labyrinth with x,y,z as starting point.
    int i,j,k,a,b,c,r,s,t,l,m,n;
    string str;
    mixed *active_rooms, other;
    active_rooms = ({ ({ x,y,z }) });
    rooms = ({ });
    write("Setting up labyrinth array...");
    for(i=0;i<DIMENSION;i++) {
        rooms += ({ ({ }) });
        for(j=0;j<DIMENSION;j++) {
            rooms[i] += ({ ({ }) });
            for(k=0;k<DIMENSION;k++) {
                rooms[i][j] += ({ 0 });
            }
        }
    }
    rooms[z][y][x] = make_new_room();
    write("Generating labyrinth...");
    while(sizeof(active_rooms)) {
        i = random(sizeof(active_rooms));
        j = sizeof(EXIT_ARR);
        while(j--) {
            r = active_rooms[i][0];
            s = active_rooms[i][1];
            t = active_rooms[i][2];
            l = DMODS[EXIT_ARR[j]][0];
            m = DMODS[EXIT_ARR[j]][1];
            n = DMODS[EXIT_ARR[j]][2];
            a = r + l;
            b = s + m;
            c = t + n;
            // don't go outside the labyrinth
            if((a<0)||(a>=DIMENSION)) { continue; }
            if((b<0)||(b>=DIMENSION)) { continue; }
            if((c<0)||(c>=DIMENSION)) { continue; }
            // don't make an exit if the room is already there
            if(rooms[c][b][a]) { continue; }
            if(l&&m) {
                if(other = rooms[c][b][r]) {

if(member_array(get_direction(-l,m,n),other["exits"])+1) {
                        // don't make a diagonal exit that crosses another
                        continue;
                    }
                }
            }
            rooms[t][s][r]["exits"] += ({ EXIT_ARR[j] });
            rooms[c][b][a] = make_new_room();
            rooms[c][b][a]["exits"] += ({ get_direction(-l,-m,-n) });
            active_rooms += ({ ({ a, b, c }) });
        }
        active_rooms -= ({ active_rooms[i] });
    }
    // clear the data file
    write_file(DATA,"",1);
    write("Preparing data file...");
    // extend the data file to the necessary length
    i = DIMENSION * DIMENSION * DIMENSION;
    while(i--) {
        write_file(DATA,"aaaaaaaa");
    }
    write("Approximate memory used: "+memory_info(this_object())+"
bytes\n"+
      "Compressing labyrinth...");
    for(i=0;i<DIMENSION;i++) {
        for(j=0;j<DIMENSION;j++) {
            for(k=0;k<DIMENSION;k++) {
                a = 8 * (k + (j*DIMENSION) + (i*DIMENSION*DIMENSION));
                write("i = "+i+" j = "+j+" k="+k );
                if (!rooms[i][j][k]) write("null"); else write("not null");
                 str = storage()->compress(rooms[i][j][k]);
   /*             if(!write_bytes(DATA,a,str)) {
                    error("Unable to write to file: room "+k+","+j+","+i+
                      " beginning at byte "+a+"\nString to be written:"
                      +str+" (length "+strlen(str)+")\n");
                }
   */
            }
        }
    }
    write("Done.");
}

