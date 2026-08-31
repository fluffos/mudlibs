#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_crushingblow(string str) {
    object *weapons, *knives;
    object victim;
    int *wc;
    string *type, tt, tk;
    int i, j, tmp;
    if (!abil()) {
        write("What?\n");
        return 1;
    }
    if(!str) {
        notify_fail("Crush whom?\n");
        return 0;
    }
    if (this_player()->query_rest_type()) {
        write("You can't do that while not on your feet.");
        return 1;
    }
    if(this_player()->query_ghost()) {
        notify_fail("Are you planning on killing them, too?\n");
        return 0;
    }
    if(this_player()->query_busy()) return notify_fail("You are busy.\n");
    if(environment(this_player())->query_property("no attack")) {
        notify_fail("Some mystical force prevents you from that.\n");
        return 0;
    }
    if(this_player()->query_sp() < 5) {
        notify_fail("You are to tired to be crushing anything.\n");
        return 0;
    }
    if(!(victim = present(lower_case(str),environment(this_player())))) {
        notify_fail("You don't see the target here.\n");
        return 0;
    }
    if(victim == this_player()) {
        notify_fail("Crush yourself?\n");
        return 0;
    }
    if(victim->query_ghost()) {
        notify_fail("Crush whom?\n");
        return 0;
    }
    if(!living(victim)){
        notify_fail("You would look silly trying to crush that.\n");
        return 0;
    }
    if(environment(victim)->query_property("no attack"))
     {
      write("Greater powers prevent your malice.");
      return 1;
     }
    this_player()->set_disabled();
    if(member_array(victim, (object *)this_player()->query_hunted()) != -1 ||
      member_array(victim, (object *)this_player()->query_attackers())!=-1) {
        notify_fail("You have lost the element of surprise!\n");
        return 0;
    }
    if(this_player()->query_current_attacker()) {
        notify_fail("You are already in combat with something else!\n");
        return 0;}
    if(victim->is_player() && !interactive(victim)) return 0;
    this_player()->set_paralyzed(1,"You are concentrating on crushing some part of "+victim->query_cap_name()+".");
    if(!this_player()->kill_ob(victim)) {
        write(victim->query_cap_name()+" can't be attacked by you yet.");
        return 1;
    }
    if (random(victim->query_stats("dexterity")) > (this_player()->query_stats("dexterity")+5) ) {
        write("%^ORANGE%^Your crushing blow misses!%^RESET%^");
        say(this_player()->query_cap_name()+" misses an attempt to crush "+(string)victim->query_cap_name(), victim);
        tell_object(victim, "%^ORANGE%^"+this_player()->query_cap_name()+" misses an attempt to crush you!");
        if(!this_player()->kill_ob(victim, 0)) return 1;
        return 1;
    }
    tt = victim->return_target_limb();
    write("%^ORANGE%^You slam your fist into "+(string)victim->query_cap_name()+"'s "+tt+".%^RESET%^");
    say("%^ORANGE%^"+this_player()->query_cap_name()+" slams "+this_player()->query_title_gender()+" fist into "+victim->query_cap_name()+"'s "+tt+".%^RESET%^", victim);
    tell_object(victim, "%^ORANGE%^"+this_player()->query_cap_name()+" slams "+this_player()->query_title_gender()+" fist into your "+tt+".%^RESET%^");
    /****( Damage: )***********************************************/
    j =  BALANCE_D->get_damage( this_player(), victim, 2, ({ "attack", "melee", "melee" }),
                                   ({ "strength", "strength", "dexterity" }) );
    j += j*2/3;
    /**************************************************************/
    this_player()->add_skill_points("melee", j/20);
    victim->do_damage(tt, j);
    victim->check_on_limb(tt);
 //    this_player()->add_alignment(-25);
    this_player()->add_sp(-j/7);
    return 1;
}
void help() {
    write("Syntax: crushingblow <enemy>\n\n"
      "Concentrating their chi, a monk seeks to crush a random area of the targets body. "
      "This move can only be used to initiate combat.\n"
    );
}
int abil() {
    object tp;
    tp = this_player();
    if (tp->query_subclass() != "monk") return 0;
    if (tp->query_level() < 18) return 0;
    return 1;
}
