// Scan : an ability for Sharpshooters, level 5
// It allows the player to get a general idea of their
// Targets armour class.
// Brought to you by Nightmask.
// Revamped by Chronos to make it a bit more usefull..
// And to fix the spelling.  :)

#include <mudlib.h>
#include "checkob.h"

inherit DAEMON;

#define SS "/d/class/warrior/Sharpshooter/"

int cmd_scan(string str) {
    int ac;
    object targ;

    if (!checkob(TP)) return 1;

  if (TP->query_level() <2) {
     write("Your eyelink is not yet equipped to do that.\n");
     return 1;
   }

    if (!str) {
        write("You must designate a target to be scanned.\n");
        return 1;
    }

    targ = present(str, environment(this_player()));

    if (!targ) {
        write("You see nothing like that through your eyelink.\n");
        return 1;
    }
    ac = targ->query("armor_class");
    write("You scan "+targ->query("short")+".\n") ;
      if (targ->query("magical_defense"))
   write("You detect magical defenses of some sort on this creature.\n") ;
    switch((int)targ->query("weap_resist")) {
        case 1 :  
          write("You will require a magically enhanced weapon to damage it.\n");
          break;
        case 2 : 
           write("You will require a fairly powerful magical weapon to damage it.\n"); 
           break;
        case 3 : 
           write("You will require a powerful magical weapon to damage it.\n") ;
            break ;
        case 4: 
            write("You will require a very powerful magical weapon to damage it.\n") ;
            break ;
        case 5..10: 
            write("You will require a most powerful magical weapon to damage it.\n") ;
            break ;
      default: break;
   }
    switch(ac){
    case -9..-10 : 
       write("You cannot detect any apparent weaknesses.\n");
     break;
    case -7..-8: 
      write("You detect only minor flaws in their defenses.\n");
     break;
    case -6..-5 : 
      write("You detect very few flaws in their defenses.\n");
     break;
    case -3..-4 : 
      write("You detect a few flaws in their defenses.\n");
     break;
    case -1..-2 : 
      write("You detect some flaws in their defenses.\n");
     break;
    case 0: 
      write("You detect a couple flaws in their defenses.\n");
     break;
    case 1 : 
      write("Well defended, but you could exploit some flaws to score hits.\n");
     break;
    case  2: 
      write("Fairly well defended, but you should be able to score good hits.\n");
     break;
    case 3: 
      write("Moderately protected, but you should be able to score good hits regardless.\n");
     break;
    case 4  : 
      write("This creature has some measure of protection, but should not be a"+
            "hard mark.\n");
     break;
    case 5  : 
      write("You will have little difficulty hitting this creature.\n");
     break;
    case 6  : 
      write("You will have no problem hitting this creature.\n");
     break;
    case 7  : 
      write("You should have little difficulty hitting this creature.\n");
     break;
    case 8  : 
      write("It would be a difficult mark to miss.\n");
     break;
    case 9  : 
      write("You could hit it with your eyes closed.\n");
     break;
    case 10  : 
      write("This creature is as easy to hit as it gets.\n");
     break;
    default : write("You will have an extremely hard time hitting this..\n");
      break;
    }

    return 1;
}
