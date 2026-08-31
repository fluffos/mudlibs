#include <std.h>
inherit DAEMON;
int abil();
int cmd_backstar(string str) {
    object *weapons, *knives;
    object victim;
    int *wc;
    string *type;
    int i, tmp;
    if (!abil()) {
        write("What?\n");
        return 1;
    }
    if(!str) {
        notify_fail("Backstab whom?\n");
        return 0;
    }
    if (this_player()->query_class() != "rogue") {
        write("Only rogues may backstab.");
        return 1;
    }
    if (this_player()->query_rest_type()) {
        write("You can't do that while not on your feet.");
        return 1;
    }
    if(this_player()->query_ghost()) {
        notify_fail("Are you planning on killing them, too?\n");
        return 0;
    }
    if(this_player()->query_disable()) return 1;
    if(environment(this_player())->query_property("no attack")) {
        notify_fail("Some mystical force prevents you from that.\n");
        return 0;
    }
    if(this_player()->query_sp() < 5) {
        notify_fail("You are to tired to be backstabing.\n");
        return 0;
    }
    if((int)this_player()->query_skill("murder") < 5 ||
      !(string)this_player()->query_class()) {
        notify_fail("Don't you wish you were fast enough for that?\n");
        return 0;
    }
    if(!(victim = present(lower_case(str),environment(this_player())))) {
        notify_fail("You don't see the target here.\n");
        return 0;
    }
    if(victim == this_player()) {
        notify_fail("Backstab yourself?\n");
        return 0;
    }
    if(victim->query_ghost()) {
        notify_fail("Backstab whom?\n");
        return 0;
    }
    if(!living(victim)){
        notify_fail("You would look silly backstabbing that.\n");
        return 0;
    }
    wc = ({});
    type = ({});
    knives = ({});
    weapons = (object *)this_player()->query_wielded();
    for(i=0, tmp = sizeof(weapons); i<tmp; i++) {
        if((string)weapons[i]->query_type() != "knife") continue;
        type += ({(string)weapons[i]->query_type() });
        wc += ({ (int)weapons[i]->query_wc() });
        knives += ({ weapons[i] });
    }
    if(!sizeof(knives)) {
        write("You are not equipped for backstabbing.");
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
    if(!this_player()->kill_ob(victim)) {
        write(victim->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    if (victim->query_skill("perception")*3/2 > this_player()->query_skill("stealth"))
        tell_object(victim, "%^ORANGE%^"+this_player()->query_cap_name()+" attempts to sneak behind you unnoticed!");
    this_player()->set_paralyzed(1,"You are concentrating on backstabbing.");
    this_player()->set_magic_round(1);
    call_out("do_dmg", 1, victim, this_player());
    return 1;
}
void do_dmg(object victim) {
    int i, tmp, *wc;
    object *weapons, *knives;
    string tt, tk, *type;
    int j;
    if (environment(this_player()) != environment(victim)){
        write("Your target is not here.");
      tell_room(environment(this_player()), this_player()->query_cap_name()+" grumbles.", ({ this_player() }));
        return 1;
    } 
    if (!victim){
        write("Your target is not here.");
        tell_room(environment(this_player()), this_player()->query_cap_name()+" grumbles.", ({ this_player() }));
        return 1;
    }
    if (random(victim->query_stats("dexterity")) >
      this_player()->query_stats("dexterity") + 5) {
        write("%^ORANGE%^Your backstab misses!%^RESET%^");
        say(this_player()->query_cap_name()+" misses an attempt to backstab "+(string)victim->query_cap_name(), victim);
        tell_object(victim, "%^ORANGE%^"+this_player()->query_cap_name()+" misses an attempt to backstab you!");
        if(!this_player()->kill_ob(victim, 0)) return 1;
        return 1;
    }
    wc = ({});
    type = ({});
    knives = ({});
    weapons = (object *)this_player()->query_wielded();
    for(i=0, tmp = sizeof(weapons); i<tmp; i++) {
        if((string)weapons[i]->query_type() != "knife") continue;
        type += ({(string)weapons[i]->query_type() });
        wc += ({ (int)weapons[i]->query_wc() });
        knives += ({ weapons[i] });
    }
    tt = victim->return_target_limb();
    write("%^ORANGE%^You backstab "+victim->query_cap_name()+"!");
    tk = knives[sizeof(knives)-1]->query_orig();
    if (!tk) tk = "knife";
    write("%^BOLD%^%^ORANGE%^Your "+tk+" sinks deep into "+(string)victim->query_cap_name() + "'s "+tt+".%^RESET%^");
    say("%^ORANGE%^"+this_player()->query_cap_name() +"'s attempt to backstab "+victim->query_cap_name() + " hits home!%^RESET%^", victim);
    tell_object(victim, "%^BOLD%^%^ORANGE%^"+this_player()->query_cap_name()+"'s knife sinks deep into your back!");
    /****( Damage: )***********************************************/
    j =  (int)this_player()->query_skill("murder")*3/5;
    j += (int)this_player()->query_skill("agility")*3/5;
    j += (int)this_player()->query_stats("strength")*3/5;
    j += (int)this_player()->query_stats("dexterity")*3/5;
    j -= ((int)victim->query_stats("constitution"))/3;
    j -= ((int)victim->query_skill("defense"))/2;
    j -= ((int)victim->query_stats("dexterity"))/3;
    j *= 2;
    j += random((int)this_player()->query_level())/4;
    /**************************************************************/
    this_player()->add_skill_points("murder", j/50);
    victim->do_damage(tt, j*2);
    victim->check_on_limb(tt);
    if (wizardp(this_player()))
        this_player()->add_alignment(-25);
    this_player()->add_sp(-j/7);
    return 1;
}
void help() {
    write("Syntax: backstab <enemy>\n\n"
      "This command is used to initiate combat with the\n"
      "monster or player you specify.\n"
    );
}
int abil() {
    object tp;
    tp = this_player();
    if (tp->query_class() != "rogue") return 0;
    if (tp->query_subclass() == "scout") return 0;
    if (tp->query_skill("agility") < 5) return 0;
    return 1;
}
