// a dungeonware.net production based on stun.
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_stuntouch(string str)
{
 object ob;
 int mstr, ostr;
 string gen;
 if (!abil())
    return notify_fail("What?\n");
 if (!str || str=="")
   return notify_fail("Hit whom?\n");
 if (this_player()->query_sp() < 50)
   return notify_fail("You do not have enough physical energy to use denmak.\n");
 ob = present(str, environment(this_player()));
 if (!ob) 
   return notify_fail("You do not see that anywhere.\n");
 if (!ob->is_living())
   return notify_fail("Stuntouch only affects living things.\n");
 if(environment(this_player())->query_property("no attack")) {
   notify_fail("You cannot do that here.\n");
     return 0;
 }
 if(this_player()->query_ghost())
   return notify_fail("You are a ghost.\n");
 if (this_player()->query_current_attacker())
        return notify_fail("You cannot find an opening.\n");
 if (this_player()->query_busy())
   return notify_fail("You are already in the middle of something else.");
 mstr=BALANCE_D->get_damage( this_player(), ob, 2, ({ "melee" }),
                                   ({ "strength" }) );
 mstr = mstr - mstr/6;
 if (this_player()->query_gender()=="male") gen = "him"; else gen = "her";
 if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
 }
 if (mstr < 0)
   {
    write("You fail to touch "+ob->query_cap_name()+".");
    this_player()->kill_ob(ob);
    return 1;
   }
 write("%^BOLD%^You touch "+ob->query_cap_name()+"'s forehead causing great pain to "+gen+".");
 say("%^BOLD%^"+this_player()->query_cap_name() + " touches "+ob->query_cap_name()+"'s forehead causing great pain to "+gen+".");
    if(ob->query_paralyzed()) {
        write("Your hand locks up with pain as your stuntouch backfires!");
        this_player()->set_paralyzed(random(2)+1,"You are still in terrible pain.");
        return 1; 
    }
 this_player()->set_disable();
 this_player()->add_sp(-(mstr/7));
 ob->set_paralyzed(random(2)+2, "You are still in terrible pain.");
 ob->damage(mstr);
 return 1;
}
int abil()
{
 if (this_player()->query_level() < 14 ) return 0;
 if (this_player()->query_subclass()!="monk") return 0;
 return 1;
}
void help()
{
 write("Syntax: <stuntouch [opponent]>\n\n"
       "Stuntouch is a martial arts move designed to incapacitate your opponent "
       "by touching a nerve and delivering great pain in the head. "
       "This move will incapacitate your opponent for a limited amount of time. ");
}
