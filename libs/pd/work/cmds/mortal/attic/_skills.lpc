//      /bin/user/_skills.c
//      from the Nightmare mudlib
//      lists a player's skills
//      created by Descartes of Borg 25 april 1993

#include <std.h>
#include <daemons.h>

inherit DAEMON;
#define MAGB "%^MAGENTA%^%^BOLD%^"

string gtk(string skill)
{
  int a, po;
  string tmp;

  if (!skill || skill=="") return "";
  a =(int)SKILLS_D->training_formula(this_player()->query_class(),
    this_player()->query_base_skill(skill),skill);
 po = this_player()->query_skill_points(skill);
 if (a) a = percent(po, a);
 if (!a) a = 0;
 if (a > 99) a = 99;
 
 if (this_player()->query_base_skill(skill)==
(this_player()->query_max_skill(skill)*this_player()->query_level())/20) 
   {
    if (a==99) tmp = "(MAX)";
     else
    tmp = "("+a+"%)";
   } else
 tmp = "("+a+"%)"; 

 return tmp;
}
int cmd_skills(string str) {
    string tmp;
    string *attack, *weapon, *decep, *mag;
    int i, x, skill_size, a, po;

   if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in an immaterial state.\n");
        return 0;
   }
    if(str) return 0;
 
    attack = ({ "attack", "melee", "defense", "double wielding", "riding" });
    weapon = ({ "knife", "blade", "blunt", "two handed", "projectile" });
    decep = ({ "locks", "stealth", "murder", "stealing", "bargaining" });
    mag = ({ "faith", "healing", "conjuring", "magic attack", "magic defense","conjuring"});
message("no_wrap","%^BOLD%^%^BLUE%^   "+arrange_string("Combat",29)+arrange_string("Weapons",24)+
      "Magic%^RESET%^\n",this_player());

message("no_wrap","--------------------------------------------------------------------------\n",this_player());
    for(i=0; i<5; i++) {
     tmp="       ";
     if (attack[i]=="riding")
     if (this_player()->query_race()=="centaur" ||
         this_player()->query_race()=="satyr") attack[i]="charging";
     tmp = sprintf("%-7s", gtk(attack[i]));
   message("no_wrap", "%^MAGENTA%^"+arrange_string(attack[i],16)+": "+"%^RESET%^", this_player());
        message("no_wrap", arrange_string(""+(int)this_player()->query_skill(attack[i]), 4)+tmp,
          this_player());
    tmp = sprintf("%-7s", gtk(weapon[i]));
        message("no_wrap","%^MAGENTA%^"+arrange_string(weapon[i], 11)+": %^RESET%^", this_player());

message("no_wrap",arrange_string(""+this_player()->query_skill(weapon[i]), 4)+tmp,
this_player());
        message("no_wrap", "%^MAGENTA%^"+arrange_string(mag[i], 14)+":%^RESET%^ ",
 this_player());
        tmp = sprintf("%-6s", gtk(mag[i]));

        message("no_wrap",
arrange_string(""+this_player()->query_skill(mag[i]),4)+tmp+"\n",
          this_player());
    }
 write("%^BOLD%^%^BLUE%^Deception%^RESET%^");
 write("--------------------");
 for (i=0;i<5;i++)
{

 message("no_wrap", "%^MAGENTA%^"+arrange_string(decep[i],11)+":%^RESET%^ ", this_player());

tmp =arrange_string(""+this_player()->query_skill(decep[i]),4)+
   sprintf("%-6s", gtk(decep[i]))+"\n"; 

message("no_wrap", tmp, this_player());
}
    return 1;
}

void help() {
    write("Syntax: <skills>\n\n"
      "This command lists out numeric representations of your level\n"
      "of expertise in the fields of study in this reality.\n"
    );
}
