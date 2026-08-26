/* File:  /cmds/std/_lore.c
  lore command
06 Nov 97  Cyanide made it so that it lores whatever your attacking
           if there is no argument.
(04-06-98) Chronos made it handle the no argument situation better.
(04-18-98) Chronos made it prettier, and neater.  Removed a couple vars.
*/

#include <config.h>
#include <mudlib.h>
#include <daemons.h>
#include <races.h>

inherit DAEMON;

int cmd_lore (string str) {
  int skilled, i, playlvl, oblvl ;
  string race, loretype;
  object ob;
  mapping resist;
  if (!str) str="NONE";
  if (str=="NONE") ob=TP->query_current_attacker();
  else  ob = present(str, environment(this_player())); 

  if (!ob) {
    if (str != "NONE") {
      write("There's nothing by that name to lore.\n") ;
      return 1;
    } else {
      write("Lore what?\n") ;
      return 1;
    }
  }
  if (!(ob->query ("short"))) return 1;
/* Chronos removed this in lieu of the visible() function.
  invis = ob->query ("invisible");
  if (invis>1) return 1;
*/
  if (!visible(ob, TP)) {               // Can't see it.  Deny it's there.
      write("There's nothing by that name to lore.\n") ;
      return 1;
  }

//good it's visible, now lets see what it is...
  race = ob->query("race");
  if (member_array(race,(string *)DEMONS)!=-1) loretype = "Demon Lore";
  if (member_array(race,(string *)ANIMALS)!=-1) loretype = "Animal Lore";
  if (member_array(race,(string *)UNDEAD)!=-1) loretype = "Undead Lore";
  if (member_array(race,(string *)MONSTERS)!=-1) loretype = "Monster Lore";
if (member_array(race, (string *)CONSTRUCTS)!=-1) loretype = "Spellcraft";
  if (!race) loretype = "Animal Lore"; // Default lore.
  
  skilled = this_player()->query_skill(loretype);
  if (!skilled){
    write("It seems to you that you've never heard about that.\n");
    return 1;
  } else {
    playlvl = this_player()->query_level();
    oblvl = ob->query_level() - playlvl;
    switch (oblvl) {
      case -1000..-20 : write ("It seems to be beneath your notice.\n");break;
      case -19..-10 : write ("You could probably tear it a new asshole.\n");break;
      case -9..-4 : write ("Unless it's packing some serious power, you got it.\n");break;
      case -3..2 : write ("It's about your size.\n");break;
      case 3..5 : write ("It will probably put up a good fight.\n");break;
      case 6..9 : write ("It looks kinda mean.\n");break;
      case 10..15 : write ("It looks like it can do you a world of hurt.\n");break;
      case 16..19 : write ("It looks like a mack mutha' fucka'.\n");break;
      case 20..30 : write ("Looks like it can kick ass and take names.\n");break;
      case 31..1000 : write ("Do you really want to die?\n");break;
    }
    if ((int)TP->query("stat/intelligence")>9) {
      oblvl = ob->query("armor_class");
      switch(oblvl) {
        case -1000..-20 : write("It looks impossible to damage.\n"); break ;
        case -19..-7 : write ("It looks you'll have an extremely hard time damaging it.\n");break;
        case -6..-1 : write ("It looks very hard to hit.\n");break;
        case 0..3 : write ("It looks hard to hit.\n");break;
        case 4..6 : write ("It doesn't look too tough to damage.\n");break;
        case 7..100 : write ("It looks a bit soft and sluggish.\n");break;
        default: write("You have no idea how hard it is to hit.\n");
        break ;
      }
    }
    if (this_player()->query("stat/intelligence")>13){
      oblvl = ob->query("weap_resist");
      switch(oblvl) {
        case -1000..0 : break;
        case 1 : write("It look's like your going to need an enchanted weapon to hurt it.\n");break;
        case 2..3 : write("It look's like you'll need strong magic to hurt it.\n");break;
        case 4..5 : write("It look's like you'll need mighty magic to hurt it.\n");break;
        case 6..100 : write("It will take a weapon of the Gods to damage it.\n");break;
        default: break ;
      }
    }
    if (this_player()->query("stat/intelligence")>15){
      resist = ob->query("resist_type");
      for (i=0;i<(sizeof(resist)); i++){
        if (values(resist)[i] < 0)      loretype = "native";
        if (values(resist)[i] == 0)     loretype = "immune";
        if (values(resist)[i] > 1)      loretype = "highly resistant";
        if (values(resist)[i] > 49)     loretype = "resistant";
        if (values(resist)[i] > 100)    loretype = "suceptible";
        race = (keys(resist)[i]);
        write("It seems "+loretype+" to "+race+".\n");
      }
    }      
    return 1;
  }
  return 1;
}

string help() {
  return @ENDHELP
Usage: lore <monster>

This command will call upon your knowledge of various creatures
to try and gather some information about a monster.  You need to have
an appropriate lore skill in order to ascertain any knowledge about
the creature you are trying to lore.

With no argument, this command will assume you mean your current attacker.
ENDHELP
  ;
}
