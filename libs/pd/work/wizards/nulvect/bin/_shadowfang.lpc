//     /bin/user/_bite.c
//     A dragon physical attack
//     Nightshade

/*

Shadowfang is a copy of the code credited to the above, 
modified by Venenum. It is a high level attack for 
Black Dragons.

*/

#include <std.h> 
#include <daemons.h>
inherit DAEMON;
int abil(); 

int cmd_shadowfang (string str) {

    int attack, total;
    object ob;
    if (!abil())
        return 0;
    if(this_player()->query_ghost()) {
        notify_fail("You cannot do that as a ghost.\n");
        return 0;
    }
    if(str)
    {
        if (present(str, environment(this_player())))
        {
            ob = present(str,environment(this_player()));
        }
        else
        {
            notify_fail("That is not here.\n");
        }
    }
    else
    {
        ob = (object)this_player()->query_current_attacker();
    }
    if(!ob || !living(ob)) {
        notify_fail("That is not here.\n");
        return 0;
    }

    if (this_player()->query_disable())
    {
        write("You are off balance.");
        return 1;
    }


    if(this_player()->query_casting()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
        return 1;
    }

    if(environment(this_player())->query_property("no attack")) {
        notify_fail("You cannot do that here.\n");
        return 0;
    }
    if((int)this_player()->query_sp() < 60) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    if((int)this_player()->query_mp() < 80) {
        notify_fail("You don't have enough mana.\n");
        return 0;
    }

    this_player()->set_disable();
    attack = BALANCE_D->get_damage( this_player(), ob, 4, ({ "attack", "magic attack" }), ({ "strength", "intelligence" }) );
    tell_object(this_player(), "%^BOLD%^%^BLACK%^Dark %^WHITE%^shadows%^BLACK%^ form about your maw.%^RESET%^");
    message("info","%^BOLD%^%^BLACK%^Dark %^WHITE%^shadows%^BLACK%^ form about "+this_player()->query_cap_name()+
                   "'s maw.%^RESET%^",environment(this_player()), this_player());

    if (attack < 1)
    {
        message("info","%^BOLD%^%^BLACK%^The shadows evaporate harmlessly.%^RESET%^",environment(this_player()));
        return 1;
    }

    write("%^BOLD%^%^BLACK%^You sink your %^WHITE%^teeth%^BLACK%^ into %^RED%^"+ob->query_cap_name()+"%^BLACK%^.");

    message("info","%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" sinks "+this_player()->query_possessive()+
                   " %^WHITE%^teeth%^BLACK%^ into %^RED%^"+ob->query_cap_name()+"%^RESET%^.",
                   environment(this_player()), ({ ob, this_player() }) );

    tell_object(ob,"%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" sinks "+this_player()->query_possessive()+
                   " %^WHITE%^incisors%^BLACK%^ into %^RED%^you%^RESET%^.");

    total = (attack * 4) / 3;

    this_player()->add_skill_points("attack", total/20);
    this_player()->add_skill_points("magic attack", total/20);

    this_player()->add_sp(-total/9);
    this_player()->add_mp(-total/5);

    if (!(this_player()->query_stat_bonus("strength"))) {
      this_player()->add_stat_bonus("strength", this_player()->query_level()/2, this_player()->query_level());
      write("%^BOLD%^%^BLACK%^You feel stronger.%^RESET%^");
    }
    if (!(ob->query_stat_bonus("strength"))) {
      ob->add_stat_bonus("strength", -1*this_player()->query_level()/2, this_player()->query_level());
      message("info","%^BOLD%^%^BLACK%^"+ob->query_cap_name()+" looks weaker.%^RESET%^",
                     environment(this_player()), ob);
      tell_object(ob,"%^BOLD%^%^BLACK%^You feel weaker.%^RESET%^");
    }

    ob->damage(attack);
    this_player()->add_alignment(-10);

    return 1;

}



void help() {

    write("Syntax: <shadowfang>\n\n"
      "This powerful attack is possessed by the Black Dragons and combines the best of both their incredible magical powers 
    and their raw physical strength, allowing them to deal massive damage with a melee attack which also has the effect of 
    draining the strength of the dragon's unfortunate victim.");

}



int abil() {

    if (this_player()->query_subclass() != "black") return 0;
    if (this_player()->query_level() < 40) return 0;

    return 1;

}

