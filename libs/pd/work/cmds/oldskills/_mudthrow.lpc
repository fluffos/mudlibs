// a dungeonware.net production based on denmak.
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_mudthrow(string str)
{
 object ob;
 int mstr, ostr, para, dam, time;
 string gen;
 if (!abil())
    return notify_fail("What?\n");
 if (!str || str=="")
   return notify_fail("Hit whom?\n");
 if (this_player()->query_sp() < 50)
   return notify_fail("You are to tired.\n");
 ob = present(str, environment(this_player()));
 if (!ob) 
   return notify_fail("You do not see that anywhere.\n");
 if (!ob->is_living())
   return notify_fail("Mudthrow only affects living things.\n");
   if(this_player()->query_current_attacker()) {
     write("You are already in combat with something else!\n");
     return 1;
 }
 if (ob==this_player()) {
       write("Something must be wrong with you.");
       return 1;
 }
 if (this_player()->query_disable())
   return notify_fail("You are in the middle of something else.");
 mstr=this_player()->query_skill("nature");
 ostr = ob->query_stats("dexterity")*3/2;
 if (this_player()->query_gender()=="male") gen = "him"; else gen = "her";
 if (!present("mud", this_player()))
  return notify_fail("You need mud to do this task.\n");
 present("mud", this_player())->remove();
 mstr -= ostr;
    dam = (mstr);
    if (dam < 10) para = 0; else
    if (dam < 55) para = 2; else
    if (dam < 110) para = 3; else
    if (dam < 165) para = 4; else
    if (dam < 220) para = 5; else
    if (dam >= 220) para = 6;
    time = 3+random(para);
    if (para = 0){
      write("You fail to hit "+ob->query_cap_name()+" with your mud.");
      return 1;
    }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
 write("%^BOLD%^You fling mud into "+ob->query_cap_name()+"'s eyes blinding "+gen+".");
 say("%^BOLD%^"+this_player()->query_cap_name() + " flings mud into "+ob->query_cap_name()+"'s eyes blinding "+gen+".");
 this_player()->set_disable();
 this_player()->add_sp(-mstr/6);
 ob->set_paralyzed(time, "You are still trying to get the mud out of your eyes.");
 return 1;
}
int abil()
{
 if (this_player()->query_level() < 15 ) return 0;
 if (this_player()->query_subclass()!="ranger") return 0;
 return 1;
}
void help()
{
 write("Syntax: <mudthrow [opponent]>\n\n"
       "Mudthrow allows a ranger to throw mud into his opponents "
       "eyes, rendering them helpless for a short time.");
}
