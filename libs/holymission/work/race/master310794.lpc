/*
 * This is the race master.
 *
 * This object is NOT designed for cloning or inheriting.
 * Use it by calling the functions listed below.
 * You can assume that the object is loaded in room/init_file,
 * so don't load it yourself but refer to the funtions in a style like:
 *
 * value = "race/master"->query_function_value(params);
 *
 * These are the functions defined in the race/master:
 * ===================================================
 *
 * query_size           ... returns the size of a race 
 * query_basic_stat     ... returns the basic stat of a race
 * query_max_stat       ... returns the maximal stat of a race
 * query_language       ... returns the language of a race
 * query_soul           ... returns the filename of the soul
 * query_room           ... returns the filename of the room
 * query_start_room     ... returns the start room of each race
 * race_list            ... returns a list of all races
 *
 */
/* 120593: Ethereal Cashimor: added the query_plural(str) function */
/* 300794: Whisky added gnomes and giants */

#define NUMBER_OF_RACES sizeof(race_info) 
#define NAME_OF_SIZE    "obj/armour"->query_size_name
#include "includes.h"

string race_info;
string race_defines;

short() { return "The Race Master"; }

long() { 
  write(short()+"\n"+
        "This room contains all information about races.\n"+
        "No obvious exits.\n");
}

init() { 
  add_action("dump","dump"); 
}

dump(str) {
  int i,j;

  if(!str) {
    write("Name\t\tSize\tStr\tDex\tCon\tInt\tWis\tChr\n");
    for(i=0;i<sizeof(race_info);i++) {
      write(race_info[i][0]+"     \t"+NAME_OF_SIZE(race_info[i][1])+"");
      for(j=0;j<NUMBER_OF_STATS;j++) 
        write("\t"+race_info[i][2][j]+"("+race_info[i][3][j]+")"); 
      write("\n");
    }
    return 1;
  }
  if(!query_basic_stat(str,1)) {    
    say("No such race!\n");
    return 1;
  }
  while(j<NUMBER_OF_RACES && race_info[j][0]!=str) j++; 
  say("Race: "+race_info[j][0]+"\n");

  write(race_info[j][0]+"\t"+NAME_OF_SIZE(race_info[j][1])+"\n");
  for(i=0;i<NUMBER_OF_STATS;i++)
    write(query_basic_stat(str,i)+"("+query_max_stat(str,i)+")\t");
  write("\n");  
  write("Language : "+query_language(str)+"\n");
  
  return 1;
} /* dump */

reset(arg) {

  if (arg) return;	/* Allocate not needed anymore */
  set_light(1); 	/* Oh well :-) */
  race_info = ({

    /* Name      siz   start-stats        max-stats        */ 

 ({ "human",   3, ({4,3,4,3,3,3,}) , ({33,30,33,30,30,30,}), ({"westron",}) }),
 ({ "elf",     3, ({1,4,2,6,4,5,}) , ({20,33,25,38,33,36,}), ({"sindarin",}) }),
 ({ "half-elf",3, ({2,4,3,4,4,3,}) , ({25,33,30,33,33,30,}), ({"sindarin","westron",}) }),
 ({ "hobbit",  2, ({1,7,1,3,4,4,}) , ({20,40,25,30,33,33,}), ({"kuduk",}),}),
 ({ "gnome",   2, ({1,7,1,7,2,3,}) , ({20,40,20,40,35,30,}), ({"gnomish",}),}),
 ({ "dwarf",   2, ({5,3,5,2,3,2,}) , ({36,30,36,25,30,25,}), ({"khuzdul",}),}),
 ({ "orc",     3, ({6,4,6,1,2,1,}) , ({38,33,38,20,25,20,}), ({"orcish",}),}),
 ({ "troll",   4, ({7,4,6,1,1,1,}) , ({40,33,38,20,20,20,}), ({"trollish",}),}),
 ({ "giant",   4, ({7,4,6,1,1,1,}) , ({45,25,40,15,20,35,}), ({"giantish",}),}),

  });

} /* reset */

race_list() {
  int i;
  
  for(i=0;i<sizeof(race_info);i++) 
    write(race_info[i][0]+"       \t"+NAME_OF_SIZE(race_info[i][1])+"\n");
}

query_basic_stat(race,stat) {
  if(query_number(race)!=-1)
    return race_info[query_number(race)][2][stat]; 
}

query_max_stat(race,stat) {
  if(query_number(race)!=-1)
    return race_info[query_number(race)][3][stat];
}

query_size(race) {
  if(query_number(race)!=-1)
    return race_info[query_number(race)][1];
}

query_language(race) {
  if(query_number(race)!=-1)
    return race_info[query_number(race)][4][0];
}

query_soul() { return SOUL; }

query_room() { return ROOM; }

query_start_room(race) {
  return "room/church";
}

query_number(race) {  
  int j;

  while(j<NUMBER_OF_RACES && race_info[j][0]!=race) { j++; }

  if(j==NUMBER_OF_RACES) return -1;
  return j;
}

query_plural(str) {
  switch(str) {
    case "elf": return("elves");
    case "half-elf": return("half-elves"); 
    case "dwarf": return("dwarves");
    default: return(str+"s");
  }
}

query_adverb(race) {
  string s;

  switch(race) {
    case "human": s="human"; break;
    case "elf": s="elven"; break;
    case "half-elf": s="half-elven"; break;
    case "hobbit": s="hobbit"; break;
    case "dwarf": s="dwarven"; break;
    case "orc": s="orcish"; break;
    case "troll": s="trollish"; break;
    default: s=race;
  }
  return s;
}

