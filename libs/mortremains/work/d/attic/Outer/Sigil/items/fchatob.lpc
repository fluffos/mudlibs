/* 
** A chat experiment
** Cyanide/Nightmask May 7 1997
 Original concept
**   Satch@Enchanted Rock
**   Tigerfolly@Enchanted Rock   (Don't ask for dates)
**   Nightmask@Enchanted Rock  (got to work)
**   Cyanide@AtFoD      (Made object driven took from char file)
*/

#include <mudlib.h>
#define TPN this_player()->query("cap_name")

inherit OBJECT;

string onoff = "on";
string faction;

void create() {
  set("short", "an unaligned faction chat obj");
  set("long", "A pin of your faction.\n");
  set("id", ({ "pin", "#CHAT_OB#"}) );
  set("prevent_clean", 1);
  set("prevent_drop", 1);
  set ("prevent_get", 1);
  set ("prevent_insert", 1);
}

void init() {
  add_action ("chat_func", "fchat");
  faction = TP->query("faction/Faction");
  this_object()->set("short", faction+"'s pin");
  this_object()->set("id", ({ "pin", "#"+faction+"_CHAT_OB#"}));
}

int chat_func(string str) {
  string tunes;
  int i;
  object ob;
  object *people = users();
  
  if (!str) {
    switch (onoff) {
     case "on" : tunes = "out of";
                 onoff = "off";
                  break;
     case "off" : tunes = "in to";
                 onoff = "on";
                  break;
    }
    write("You tune "+tunes+" the "+faction+"'s chat.\n");
    return 1;
  }

  if (onoff == "off" ) {
    write ("You're tuned out, dumbass!\n");
    return 1;
  }

  for (i=0;i<sizeof(people);i++) {
    ob = present("#"+faction+"_CHAT_OB#", people[i]);
    if (ob) {
     if ((ob->query_on()) == 1) {
        tell_object(people[i], wrap(
          "{-"+faction+"chat-} "+TPN+" says: "+str+"\n"));
      }
    }
  }
  return 1;
}

int query_on() {
  if (onoff == "on") return 1;
    else return 0;
}
 int query_auto_load() {return 1;}
