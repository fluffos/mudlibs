/* give.c

 Ico2 @ LPUniversity
 28-OCTOBER-05
 Standard command
 
QC Review: Tacitus on 29-OCT-05

Last edited on May 5th, 2006 by Tacitus

*/

int main(string arg)
{
     string targetname;
     string obname;
     object ob;
     object target;
     
     if(!arg) return(notify_fail("SYNTAX: give <object> <user>\n"));

     if(sscanf(arg, "%s %s", obname, targetname) != 2)
          return(notify_fail("SYNTAX: give <object> <user>\n"));

     if(targetname[0..2] == "to ") targetname = targetname[3..(strlen(targetname)-1)];

     ob = present(lower_case(obname), this_player());

     if(!ob) return(notify_fail("Error [give]: You do not appear to have that object.\n"));
     if(ob->query("prevent_give")) return(notify_fail("Error [give]: You can not give that object away.\n"));

     target = present(targetname, environment(this_player()));

     if(!target) return(notify_fail("Error [give]: User '" + targetname + "' not found.\n"));
     if(!living(target)) return(notify_fail("Error [give]: You can not give objects to other non-living objects.\n"));

     ob->move(target);
     
     write("You give " + ob->query_short() + " to " + capitalize(target->query_name()) + ".\n");
     tell_object(target, capitalize(this_player()->query_name()) + " gives you a '" + ob->query("short") + "'.\n");
     say(capitalize(this_player()->query_name()) + " gives a '" + ob->query("short") + "' to " + capitalize(target->query_name()) + ".\n", ({this_player(), target}));
     
     return 1;
}

string help()
{
     return(HIW + " SYNTAX: " + NOR + "give <object> <user>\n\n"
     "This command will allow you to give an object that is currently\n"
     "in your inventory to another user in your current environment.\n"
     "Note: This command will also understand give <object> to <user>.\n\n" +
     HIW + "See also: " + NOR + "get, drop\n");     
}
     
