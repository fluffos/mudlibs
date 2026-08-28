//      /bin/user/_skills.c
//      from the Nightmare mudlib
//      lists a player's skills
//      created by Descartes of Borg 25 april 1993

#include <std.h>

inherit DAEMON;

int cmd_skills(string str) {
    string tmp;
    string *attack, *weapon, *decep, *mag;
    int i, x, skill_size;

   if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in an immaterial state.\n");
        return 0;
   }
    if(str) return 0;
    attack = ({ "melee", "attack", "defense", "double wielding" });
    weapon = ({ "knife", "blade", "blunt", "two handed", "projectile" });
    decep = ({ "locks", "stealth", "murder", "stealing", "bargaining" });
    mag = ({ "faith", "healing", "conjuring", "magic attack", "magic defense"});
    write("You have the following learned attributes:");
    write(arrange_string("Combat", 22)+arrange_string("Weapons", 17)+
      arrange_string("Deception", 17)+"Magic");
    write("--------------------------------------------------------------------------");
    for(i=0; i<5; i++) {
        message("Ninfo", (i<4 ? arrange_string(attack[i],16)+": " :
          arrange_string(" ", 16)+"  "), this_player());
        message("Ninfo", arrange_string(i>3 ? " " : 
          ""+(int)this_player()->query_base_skill(attack[i]), 4),
          this_player());
        message("Ninfo", arrange_string(weapon[i], 11)+": ", this_player());
        message("Ninfo", arrange_string(""+this_player()->query_base_skill(weapon[i]), 4), this_player());
        message("Ninfo", arrange_string(decep[i], 11)+": ", this_player());
        message("Ninfo",
          arrange_string(""+this_player()->query_base_skill(decep[i]),4),
          this_player());
        message("Ninfo", arrange_string(mag[i], 15)+": ", this_player());
        message("Ninfo",
          arrange_string(""+this_player()->query_base_skill(mag[i]),4)+"\n",
          this_player());
    }
    return 1;
}

void help() {
    write("Syntax: <skills>\n\n"
      "This command lists out numeric representations of your level\n"
      "of expertise in the fields of study in this reality.\n"
    );
}
