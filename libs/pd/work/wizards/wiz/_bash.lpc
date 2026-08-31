#include <std.h>
#include <rest.h>
inherit DAEMON;
int abil();
 
int cmd_bash(string str) {
    object *weapons, *wep;
    object victim;
    int *wc;
    string *type;
    int i, j, tmp;

   if (!abil()) {
      write("What?\n");
      return 1;
   }
    if(!str) {
       notify_fail("Bash whom?\n");
       return 0;
    }
    if(this_player()->query_ghost()) {
       notify_fail("Are you planning on killing them again?\n");
       return 0;
    }
    if(this_player()->query_disable()) return 1;
    if(environment(this_player())->query_property("no attack")) {
        notify_fail("Greater powers prevent your malice.\n");
        return 0;
    }

    if (this_player()->query_skill("murder") < 5)
       return notify_fail("You are not deadly enough to do this.\n");

    if(!(victim = present(lower_case(str),environment(this_player())))){
        notify_fail("You don't see the target here.\n");
        return 0;
    }
    if(victim == this_player()) {
        notify_fail("And when you're done with that, you could pick your own pockets!\n");
        return 0;
    }
    if(victim->query_ghost()) {
        notify_fail("Boo! Like the ghost you are, you scare the bejesus out of them.\n");
        return 0;
    }
   if(!living(victim)){
        notify_fail("You teach it good!\n");
        return 0;
    }

    wc = ({});
    type = ({});
    wep = ({});
    weapons = (object *)this_player()->query_wielded();
    for(i=0, tmp = sizeof(weapons); i<tmp; i++) {
        if(member_array("blunt", weapons[i]->query_type()) == -1) continue;
        type += weapons[i]->query_type();
        wc += ({ (int)weapons[i]->query_wc() });
        wep += ({ weapons[i] });
    }
    if(!sizeof(wep)) {
        write("You must be wielding a blunt weapon to bash someone.");
        return 1;
    }
    this_player()->set_disable();
        if(member_array(victim, (object *)this_player()->query_hunted()) != -1 ||
      member_array(victim, (object *)this_player()->query_attackers())!=-1) {
        notify_fail("You have lost the element of surprise!\n");
        return 0;
    }
   if(this_player()->query_current_attacker()) {
        notify_fail("You are already in combat with something else!\n");
         return 0;}
    if(victim->is_player() && !interactive(victim)) return 0;
     if (victim->query_stats("dexterity")*2/3 >
         this_player()->query_stats("dexterity")) {
        write("%^BLUE%^You fail in your attempt at bashing "+victim->query_cap_name()+"!%^RESET%^");
        say(this_player()->query_cap_name()+" misses an attempt at bashing "+(string)victim->query_cap_name(), victim);
        tell_object(victim, "%^BLUE%^"+this_player()->query_cap_name()+
                    "misses bashing you!");
        if(!this_player()->kill_ob(victim, 0)) return 1;
        return 1;
    }
    write("%^BLUE%^You bash "+victim->query_cap_name()+" on the back of "
       "the head! "+victim->query_cap_name()+" falls to the gruond!");
    say("%^BLUE%^"+this_player()->query_cap_name()+" bashes "
        +victim->query_cap_name()+" on the back of the head! "+victim->query_cap_name()+"
        falls to the ground!%^RESET%^", victim);
    tell_object(victim, "%^BLUE%^"+
        this_player()->query_cap_name()+
        " bashes you on the back of the head! You fall to the ground!");
/****( Damage: )***********************************************/
    j += this_player()->query_skill("murder")/5;
    j += this_player()->query_stats("strength")/5;
    j += this_player()->query_stats("dexterity")/5;
    j -= random(victim->query_skill("defense"));
    j -= victim->query_stats("dexterity")/3;
    j -= victim->query_stats("strength")/2;
/**************************************************************/
    this_player()->add_skill_points("murder", 15);
    for(i=0, tmp = sizeof(wep); i<tmp; i++) {
        wep[i]->set_wc(
          ((int)wep[i]->query_wc() + (int)this_player()->query_skill("murder"))/10
        );
    }
    if(!this_player()->kill_ob(victim, 0)) return 1;
    victim->do_damage(victim->return_target_limb(), j);
    if (wizardp(this_player()))
     write("[*] "+(int)j+"\n");
   this_player()->add_alignment(-10);
    this_player()->add_sp(-(j/5));
   victim->set_paralyzed(1, "You are trying to regain your senses.");
   victim->set_rest_type( LAY );
   return 1;
}
 
void help() {
    write("Syntax: bash <enemy>\n
This command can be used by thugs with a blunt weapon to knock someone over the head.
");
}

int abil() {
   object tp;
   tp = this_player();
   if (tp->query_level() < 3) return 0;
   if (this_player()->query_subclass() != "thug") return 0;
   if (tp->query_skill("murder") >= 5) return 1;
}

