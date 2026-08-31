#include <daemons.h>

inherit DAEMON;

int list_generic();

int cmd_skeditor()
{
 write("\n\n\n\n");
 write("--------------------[ Skill Editor ]-------------------------");
 list_generic();
 message("no_wrap", "skeditor>", this_player());
 input_to("prompt");
 return 1;
}

int list_generic()
{
string *skills;
mapping tmp;
int a, i;
a = sizeof(skills = SKILLS_D->query_skills());

write(" ----- Generic Skills( for every class/subclass ) -----");
 for(i=0; i < a; i++)
  {
   tmp = SKILLS_D->query_skill(skills[i]);
   if (tmp["c_elig"]=="all" && tmp["sc_elig"] == "all")
     write(" - ("+(i+1)+") [ "+capitalize(skills[i])+" ] :");
  }
}
int list_class(string cl)
{
string *skills;
mapping tmp;
int a, i;
a = sizeof(skills = SKILLS_D->query_skills());

write(" ----- Skills for class "+cl+" -----");
 for(i=0; i < a; i++)
  {
   tmp = SKILLS_D->query_skill(skills[i]);
   if (tmp["c_elig"]==cl)
     write(" - ("+(i+1)+") [ "+capitalize(skills[i])+" ] :");
  }
}
int list_subclass(string cl)
{
string *skills;
mapping tmp;
int a, i;
a = sizeof(skills = SKILLS_D->query_skills());

write(" ----- Skills for subclass "+cl+" -----");
 for(i=0; i < a; i++)
  {
   tmp = SKILLS_D->query_skill(skills[i]);
   if(arrayp(tmp["sc_elig"])) 
     if(member_array(cl, tmp["sc_elig"]) != -1)
       write(" - ("+(i+1)+") [ "+capitalize(skills[i])+" ] :"); 
     else if(tmp["sc_elig"] == cl || (tmp["sc_elig"] == "all") || tmp["c_elig"] == "all")
       write(" - ("+(i+1)+") [ "+capitalize(skills[i])+" ] :");
  }
}

int edit_skill(string sk)
{
 string which;
 mapping skill;
 if (sscanf(sk, "edit %s", which)!=1)
   { 
    write("Which skill do you plan on editing?");
    return 1;
   }
 if (!skill = SKILLS_D->query_skill(which))
   {
    write("No such skill: "+which+".");
    return 1;
   }
 write("------[ Editing skill: "+capitalize(which)+" ]------");
 write("1.    For which classes      : "+implode(skill["c_elig"],", "));
 write("2.    For which subclasses   : "+implode(skill["sc_elig"],", "));
 write("3.    Start out skill level  : "+skill["startout"]);
 write("4.    Skill max increment    : "+skill["max"]);
 write("5.    Start out skill points : "+skill["points"]);
 return 1;
}
int prompt(string str)
{
string cmd, arg;
 if (sscanf(str, "%s %s", cmd, arg)!=2) cmd = str;
 switch(cmd)
  {
   case "list" : 
     if(sscanf(arg, "class %s", arg)==1) list_class(arg); else
     if(sscanf(arg, "subclass %s", arg)==1) list_subclass(arg); else
     write("List error.");
     break;
   case "edit" : edit_skill(str); break;
   case "quit" : return 1;
  }
 message("no_wrap", "\nskeditor>", this_player());
 input_to("prompt");
}
