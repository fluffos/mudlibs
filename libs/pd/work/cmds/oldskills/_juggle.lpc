// juggle, an ability for jesters
// lets them juggle light equipment and throw it at
//   something to start combat
// syntax: juggle blah, blah, blah, and blah
// Kaknal 4-20-02
#include <std.h>
inherit DAEMON;
#define JUGGLE "/cmds/std/juggle"
int abil();
int cmd_juggle(string str) {
  object tp=this_player();
  object what, *jugg;
  int i, strong, dex, ent, weight;
  string s1, s2, *stuff;
  
  if (!abil()) {
    message("info","What?",tp);
    return 1;
  }
  if (tp->query_current_attacker()) {
    message("info","You are too busy fighting.",tp);
    return 1;
  }
  if (tp->query_disable())
    return 1;
  if (present("jester_juggling_obj",tp)) {
    message("info","You are already juggling!",tp);
    return 1;
  }
  if (!str) {
    message("info","Juggle what?",tp);
    return 1;
  }
  
  if (tp->query_sp() < 15) {
    message("info","You are too tired to juggle.",tp);
    return 1;
  }
  // get a list of the things to juggle
  // we make it so a comma is the item delimiter and remove
  //   any spaces around the commas so we get "blah 2,thing,bleh"
  s1= replace_string(str, " and ", ",");
  s1= replace_string(s1, ", ", ",");
  s1= replace_string(s1, " ,", ",");
  // now turn it into an array so we can loop through it
  stuff=explode(s1, ",");
  
  for (i=0, jugg=({ }); i<sizeof(stuff); i++) {
    // if we have blank entries, get rid of them
    if (stuff[i] == "" || stuff[i] == " ") {
      stuff-= ({ stuff[i] });
      i--;
      continue;
    }
    // if it's here, put its object in the array and
    //   remove it from the list
    if (what=present(stuff[i],tp)) {
      jugg+= ({ what });
      stuff-= ({ stuff[i] });
      i--;
    }
  }
  // this only happens if they do something like
  //   juggle , and , and ,  
  if (!sizeof(jugg)) {
    message("info","Juggle what?",tp);
    return 1;
  }
  
  // if there's anything left in the list, the player doesn't
  //   have anything with that id(), so we error out
  if (sizeof(stuff)) {
    for (i=0; i<sizeof(stuff); i++) {
      if (i == sizeof(stuff)-1 && i > 0)
        s2+= " or "+stuff[i];
      else if (i == 0)
        s2= stuff[i];
      else
        s2+= ", "+stuff[i];
    }
    message("info","You are not carrying "+s2+".",tp);
    return 1;
  }
  if (sizeof(jugg) < 2) {
    message("info","You must juggle at least two things.",tp);
    return 1;
  }
  // you can juggle an additional item every 9 levels,
  //   up to 5 max (level 49)
  if (sizeof(jugg) > 5 ||
      sizeof(jugg) > ((tp->query_level()-13)/9)+2) {
    message("info","You are not skilled enough to juggle "
      "that many things at once!",tp);
    return 1;
  }
  
  dex= tp->query_stats("dexterity");
  strong= tp->query_stats("strength");
  // plenty of ent, but no ent-wives
  ent= tp->query_skill("entertainment");
  
  // check everything to make sure it's jugglable
  for (i=0, weight=0; i<sizeof(jugg); i++) {
    // if it has no short desc it's not meant to be seen,
    //   just act like we don't know what the player's talking about
    if (!jugg[i]->query_short()) {
      message("info","Juggle what?",tp);
      return 1;
    }
    else if (jugg[i]->query_worn()) {
      message("info","You can't juggle a worn item.",tp);
      return 1;
    }
    else if (jugg[i]->query_wielded()) {
      message("info","You can't juggle a wielded item.",tp);
      return 1;
    }
    else if (jugg[i]->query_weight() > 25+(strong/5)+(dex/5)+(ent/15)) {
      message("info",capitalize(jugg[i]->query_short())+
        " is too heavy for you to juggle.",tp);
      return 1;
    }
    else if (jugg[i]->query_weight() < 4) {
      message("info",capitalize(jugg[i]->query_short())+
        " is too light to juggle properly.",tp);
      return 1;
    }
    weight+= jugg[i]->query_weight();
  }
  if (weight > (strong/4)+(dex/4)+(ent/2)) {
    message("info","You are not skilled enough to juggle that much weight.",tp);
    return 1;
  }
  // we're recycling this variable
  //   recycle, reduce, reuse, and close the loop!..err..
  what= new(JUGGLE);
  what->set_juggling(tp,jugg);
  what->move(tp);
  message("juggle","You start to juggle.",tp);
  tp->add_sp(-(2+random(5)));
  tp->add_skill_points("entertainment",8+sizeof(jugg));
  return 1;
}
int abil() {
  object tp=this_player();
  
  // 6 entertainment per level, max ent at 13 is 78
  if (tp &&
      tp->query_level() >= 13 &&
      tp->query_subclass() == "jester" &&
      tp->query_skill("entertainment") >= 75)
    return 1;
  
  return 0;
  
}
void help() {
  object tp=this_player();
  message("help","\n  <juggle item1 and item2>"
                 "\n  <juggle item1, item2, item3>"
                 "\n\n  <toss [item|all] at living>"
                 "\n\n  <stop juggling>"
                 "\n\nA jester command, this lets you juggle items from "
                 "your inventory for the amusement of all those around.\n"
                 "You can also begin combat by <toss>ing things at a foe.",
                 tp);
}
