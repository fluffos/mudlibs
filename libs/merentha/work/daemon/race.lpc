// Petrarch
// Merentha Lib 1.0
// race daemon

// race daemon keeps track of stats and limbs for races

#include <std.h>

inherit DAEMON;

mapping __Limbs=([]), __Stats=([]);

void load_races() {
    string *files=get_dir("/cfg/races/"), *lines;
    string file, race, tmp;
    int i=sizeof(files), j;
    while(i--) {
        if(file_size(file="/cfg/races/"+files[i]) > 0) {
            file=read_file(file);
            j=sizeof(lines=explode(file, "\n"));
            while(j--) {
                if (sscanf(lines[j], "race:%s", tmp)) {
                    race=tmp;
                    continue;
                }
                if (sscanf(lines[j], "stats:%s", tmp)) { __Stats[race]=tmp; continue; }
                if (sscanf(lines[j], "limbs:%s", tmp)) { __Limbs[race]=tmp; continue; }
            }
        }
    }
}

string *query_limbs(string race) {
    if(!race || !__Limbs[race]) return 0;
    return explode(__Limbs[race], ";");
}

mapping query_stats(string race) {
    mixed val;
    string *stats;
    if(!val=__Stats[race]) return 0;
    stats=explode(val, ";");
    return (["strength":to_int(stats[0]),"constitution":to_int(stats[1]),"dexterity":to_int(stats[2]),"wisdom":to_int(stats[3]),"intelligence":to_int(stats[4]),"charisma":to_int(stats[5]),"luck":to_int(stats[6]),"eyes":to_int(stats[7]),"size":to_int(stats[8]),"mass":to_int(stats[9])]);
}

string *query_races() {
  return keys(__Stats);
}

int valid_race(string str) {
  return (1+member_array(str, keys(__Stats)));
}

void create() {
    load_races();
}
