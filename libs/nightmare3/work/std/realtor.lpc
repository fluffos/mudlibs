 
#include <std.h>
#include <money.h>
 
inherit MONSTER;
 
mapping __disc, endroits;
string money_type;
int __discriminate();
void set_bad_class(mapping mp);
void set_bad_race(mapping mp);
void set_bad_guild(mapping mp);
void set_rooms(mapping mp);
void set_money_type(string str);
 
 
void init(){
   ::init();
   add_action("__move","move");
   add_action("__list","list");
}
 
void create(){
   ::create();
   __disc=([]);
   __disc["class"]=([]);
   __disc["race"]=([]);
   __disc["guild"]=([]);
   endroits=([]);     
}
 
 
int __list(){
    string *file, *cost, *info;
    int count,penalty;
 
    if(!penalty=__discriminate()) return 1;
    
    if(!sizeof(file=keys(endroits))){
       force_me("speak I have no sites for you at the moment.");
       return 1;
    }
 
    message("other_action",query_cap_name()+" shows you a list of properties "
                         "and prices.\n"+
            "Location\t\t\tPrice (in "+money_type+")",this_player());
    info=values(endroits);
    for(count=0;count<sizeof(info);count++)
        message("info",count+". "+info[count][1]+"\t\t\t"
                 +penalty/100*info[count][2],this_player());
    message("info", "\nTo move to a locale, type <move #>",
            this_player());   
  
    return 1;
}    
 
int __move(string str) {
   int x,count,penalty,cost;
   string *file;
 
   if(!penalty=__discriminate()) return 1;
 
   if(!str) {
      force_me("speak To which location do you wish to move?");
      return 1;
   }
 
   if(sscanf(str,"%d",x)!=1) {
      force_me("speak Move to what number location?");
      return 1;
   }
   
   count=sizeof(file=keys(endroits));
   
   if(x<=count || x>=0) {
    if(this_player()->query_money(money_type)<
                                cost=penalty/100*endroits[file[x]][2]){
       force_me("speak You do not have enough money to move to "+
                       endroits[file[x]][1]);
       return 1;
    }
    this_player()->add_money(money_type, -cost);
    force_me("speak Your home is now "+endroits[file[x]][1]+".");
    this_player()->setenv("start",file[x]);
    this_player()->save_player(this_player()->query_name()); 
    return 1;
   }
 
   force_me("speak Move where?");
   return 1;
}   
   
 
 
int __discriminate() {
   int cost;
   string race, str_class, guild;
 
   if(member_array(race=(string)this_player()->query_race(),
                   keys(__disc["race"])) != -1) {
      if(!__disc["race"][race]) {
        force_me("speak We do not want any "+pluralize(race)+" in our fine "
                "town!");
        return 0;
      }
      else cost=__disc["race"][race];
   }
   if(member_array(str_class=(string)this_player()->query_class(),
                   keys(__disc["class"])) !=-1) {
      if(!__disc["class"][str_class]) {
         force_me("speak No "+pluralize(str_class)+" shall spoil our streets.");
         return 0;
      }
      else {
         if(cost<__disc["class"][str_class])
            cost=__disc["class"][str_class];
      }
   }
   if(member_array(guild=(string)this_player()->query_guild(),
                   keys(__disc["guild"])) !=-1) {
      if(!__disc["guild"][guild]) {
         force_me("speak No "+pluralize(guild)+" shall inhabit these environs.");
         return 0;
      }
      else {
         if(cost<__disc["guild"][guild])
            cost=__disc["gulid"][guild];
      }
   }
   if(cost) return cost;
   return 100;
}
 
 
void set_bad_class(mapping mp) {__disc["class"]=mp;}
 
void set_bad_race(mapping mp) {__disc["race"]=mp;}
 
void set_bad_guild(mapping mp) {__disc["guild"]=mp;}
 
void set_rooms(mapping mp) {endroits=mp;}         
 
void set_money_type(string str) {money_type=str;}
 
string race() {return __disc["race"];}
string str_class() {return __disc["class"];}
string guild() {return __disc["guild"];}
