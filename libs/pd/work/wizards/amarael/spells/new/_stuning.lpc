// seeker
// 5:43 PM 9/4/00 balanced dungeonware.net

#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_stuning(string str) {
    object ob;
    int mstr, ostr, para, time;
    string gen;
    if (!abil())
        return notify_fail("What?\n");
    if (environment(this_player())->query_property("no attack"))
        return notify_fail("Greater powers prevent your malice.\n");
    if (!str || str== "")
        return notify_fail("Stun whom?\n");
    if (this_player()->query_sp() < 50)
        return notify_fail("You do not have enough physical energy to stun.\n");
    if (this_player()->query_current_attacker())
        return notify_fail("You cannot find an opening.\n");
    ob = present(str, environment(this_player()));
    if(!ob) 
      return notify_fail("You do not see that anywhere.\n");
    if(!ob->is_living())
      return notify_fail("Stun only affects living things.\n");
    if(ob == this_player())
      return notify_fail("Why would you want to do a thing like that?\n");
    if (ob->query_property("no stun"))
      return notify_fail("That is immune to your stun.\n");
    if (this_player()->query_disable())
        return notify_fail("You are already in the middle of something else.");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    mstr=this_player()->query_stats("strength")*3/2+(random(this_player()->query_level()));
    ostr = ob->query_stats("constitution")/2+(random(ob->query_level()/3));
    mstr -= ostr;
    if (mstr < 10) para = 1; else
    if (mstr < 50) para = 2; else
    if (mstr < 100) para = 3; else
    if (mstr < 200) para = 4; else
    if (mstr >= 200) para = 5;
    time = 2+random(para);
    if(para = 0) {
      write("You fail to stun "+ob->query_cap_name()+".");
      return 1;
      }
    if(ob->query_gender()=="male") gen = "him"; else gen = "her";
    write("%^ORANGE%^You send a punch to "+ob->query_cap_name()+"'s stomach knocking the wind out of "+gen+".%^RESET%^");
    say("%^ORANGE%^"+this_player()->query_cap_name() + " sends a punch to "+ob->query_cap_name()+"'s stomach knocking the wind out of "+gen+".%^RESET%^");
    this_player()->set_disable();
    this_player()->add_sp(-mstr/7);
    ob->damage(mstr/15);
    if(ob->is_player()) {
      if(random(time) > 2) ob->set_paralyzed(time, "You are still trying to catch your breath.");
      }
    else
      ob->set_paralyzed(time, "You are still trying to catch your breath.");
    return 1;
}
int abil()
{
    if (this_player()->query_level() < 14 ) return 0;
    if (this_player()->query_class()!="fighter") return 0;
    return 1;
}
void help()
{
    write("Syntax: <stun [opponent]>\n\n"
      "You punch your opponent in the stomach causing the wind to "
      "be knocked out of him and will be stunned for a certain amount "
      "of rounds depending on your strength. You can only do this to "
      "start combat.");
}
