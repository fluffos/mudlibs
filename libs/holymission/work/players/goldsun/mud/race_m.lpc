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
#include "/spells/spell.h"

string race_info;
string resistances_info;
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
    write("\n           ");
    for (j=1; j<MAX_NO_OF_SAVE; j++ )
       write(sprintf("%3s ",SAVE_VS_STRING[j][0..2]) );
    write( "\n" );
    for ( i = 0; i < sizeof(resistances_info); i++ ) {
       write(sprintf("%-10s ",race_info[i][0]) );
       for (j=1; j<MAX_NO_OF_SAVE; j++ )
          write(sprintf("%3d ",resistances_info[i][j]) );
       write( "\n" );
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

 ({ "human",   3, ({4,3,4,3,3,3,}) , ({30,30,30,30,30,30,}), ({"westron",}) }),
 ({ "elf",     3, ({1,4,2,6,4,5,}) , ({25,33,25,36,35,40,}), ({"sindarin",}) }),
 ({ "half-elf",3, ({2,4,3,4,4,3,}) , ({27,32,28,33,32,35,}), ({"sindarin","westron",}) }),
 ({ "hobbit",  2, ({1,7,1,3,4,4,}) , ({24,38,23,31,27,33,}), ({"kuduk",}),}),
 ({ "gnome",   2, ({1,7,1,7,2,3,}) , ({22,40,20,40,32,38,}), ({"gnomish",}),}),
 ({ "dwarf",   2, ({5,3,5,2,3,2,}) , ({37,26,32,26,40,28,}), ({"khuzdul",}),}),
 ({ "orc",     3, ({6,4,6,1,2,1,}) , ({35,29,34,22,20,20,}), ({"orcish",}),}),
 ({ "troll",   4, ({7,4,6,1,1,1,}) , ({37,24,38,20,21,18,}), ({"trollish",}),}),
 ({ "giant",   4, ({7,4,6,1,1,1,}) , ({40,20,40,18,24,26,}), ({"giantish",}),}),

  });

  resistances_info = ({

 // ? Fi El Co Ac En Dr To Pe Po Br De Ma Mi Il Su

 ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }),       // human
 ({0, 0, 0, 0,-8, 0, 0, 0, 0,-7, 0, 0, 0,10, 5, 0, }),       // elf
 ({0, 0, 0, 0,-4, 0, 0, 0, 0,-3, 0, 0, 0, 5, 2, 0, }),       // half-elf
 ({0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 5, 0, 0,-4,-8, 0, }),       // hobbit
 ({0,-4,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 4, 0, }),       // gnome
 ({0, 0, 0, 0, 0,-6, 0, 0, 0,15, 0, 0,-9, 0, 0, 0, }),       // dwarf
 ({0, 2, 0, 0, 5, 0, 0, 0, 0, 3, 0, 0, 0,-8,-2, 0, }),       // orc
 ({0,-15,0, 6, 0, 3, 3, 0, 0, 0, 0, 0, 1, 0, 0, 2, }),       // troll
 ({0, 6, 0, 6, 0, 0, 0, 0, 0, 0,-2, 0,-3,-4,-5, 2, }),       // giant

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

query_resistance_modifier( race, mod )
{
   if ( query_number(race)!=-1 )
      return( resistances_info[query_number(race)][mod] );
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

