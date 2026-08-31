// a dungeonware.net production
// 29-Dec-00 by stormbringer for PD

#include <std.h>
#include <daemons.h>
#include <rest.h>

inherit DAEMON;

int spell();

int cmd_gammon(string str)
{
    object ob;
    int mstr, ostr;
    string gen;

    if (!spell())
        return notify_fail("You do have the illusion for that.\n");
    if (environment(this_player())->query_property("no attack"))
        return notify_fail("Greater powers prevent your malice.\n");
    if (!str || str=="")
        return notify_fail("Gammon what?\n");
    if (this_player()->query_mp() < 50)
        return notify_fail("There is not enough magic for this.\n");
    if (this_player()->query_current_attacker())
        return notify_fail("You cannot find the concentration for this.\n");
    ob = present(str, environment(this_player()));
    if (!ob) 
        return notify_fail("You do not see that anywhere.\n");
    if (!ob->is_living())
        return notify_fail("Illusion only affects living things.\n");

    if (this_player()->query_disable())
        return notify_fail("You are in the middle of something else.");
    
    mstr=this_player()->query_skill("illusion")*3/2+(random(this_player()->query_skill("magic attack")/2));
    if (this_player()->query_gender()=="male") gen = "him"; else gen = "her";
    ostr = ob->query_stats("intelligence")*2/3;

    mstr -= ostr;
    if (mstr < 10)
    {
        write("You fail to gammon "+ob->query_cap_name()+".");
        this_player()->kill_ob(ob);
        return 1;
    }
    write("%^ORANGE%^You concentrate on "+ob->query_cap_name()+" and decieve "+gen+" into falling!");
    say("%^ORANGE%^"+this_player()->query_cap_name() + " concentrates on "+ob->query_cap_name()+" as "+ob->query_cap_name()+" falls down!");
    tell_object(ob, "%^ORANGE%^"+this_player()->query_cap_name()+" conentrates on you. You feel unbalanced and fall to the ground!");    
    this_player()->set_disable();
    this_player()->add_mp(-(mstr/10));
    ob->set_rest_type( LAY );
    ob->set_paralyzed(random(3), "You are confused.");
    ob->damage((mstr/3) + this_player()->query_level());
    this_player()->kill_ob(ob);
    return 1;
}

int spell()
{
    if (this_player()->query_level() < 20 ) return 0;
    if (this_player()->query_subclass()!="illusionist") return 0;
    return 1;
}

void help()
{
    write("Syntax: <gammon [target]>\n\n"
      "Illusionists decievs the target into falling down "
      "and causing damage to itself.");
}
