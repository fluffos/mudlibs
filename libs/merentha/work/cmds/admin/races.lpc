// Petrarch
// Merentha Lib 1.0
// <races>

#include <daemons.h>

int command() {
string *races=RACE_D->query_races(),
       *player_races=({"human","giant","gnome","elf","fairy","dwarf"});
string str;
int i=sizeof(races);
str="Race     str con dex int wis cha  hp  mp  sp\n";
while(i--) {
  this_player()->set_race(races[i]);
  str+=(member_array(races[i],player_races)==-1?"%^RESET%^":"%^BOLD%^")+
       arrange_string(this_player()->query_race(),9)+
       arrange_string(""+this_player()->query_stat("strength"),4)+
       arrange_string(""+this_player()->query_stat("constitution"),4)+
       arrange_string(""+this_player()->query_stat("dexterity"),4)+
       arrange_string(""+this_player()->query_stat("intelligence"),4)+
       arrange_string(""+this_player()->query_stat("wisdom"),4)+
       arrange_string(""+this_player()->query_stat("charisma"),4)+
       arrange_string(""+this_player()->query_max_hp(),4)+
       arrange_string(""+this_player()->query_max_mp(),4)+
       arrange_string(""+this_player()->query_max_sp(),4)+
       "\n";
  }
  message("command", str, this_player());
  return 1;
}
  

