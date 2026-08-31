//     _choke.c
//     A new fighter attack
//     Added 26 April 2000 by -(Inferno)-
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_choke(string str) {
    int attack;
    int oi;
    string gen;
    object ob;
    if (!abil())
        return 0;
    if(!str)
        ob = (object)this_player()->query_current_attacker();
    else {
        ob = present(str, environment(this_player()));
        if(!ob) ob = parse_objects(environment(this_player()), str);
    }
    if(!ob || !living(ob)) {
        notify_fail("You do not see that here.\n");
        return 0;
    }
    if(ob == this_player())
        return notify_fail("Why on earth would you do that??\n");
    if(this_player()->query_ghost()) {
        notify_fail("You have no body!\n");
        return 0;
    }
    if (this_player()->query_disable())
    {
        write("You are still off balance.");
        return 1;
    }
    if(this_player()->query_casting()) return 1;
    if(environment(this_player())->query_property("no attack")) {
        notify_fail("Greater powers prevent your malice.\n");
        return 0;
    }
    if((int)this_player()->query_sp() < 60) {
        notify_fail("You are too tired.\n");

        return 0;
    }
    if (this_player()->query_stats("strength") <
      random(ob->query_stats("dexterity"))) {
        write(ob->query_cap_name()+" dodges your choke!");
        tell_room(environment(this_player()), this_player()->query_cap_name()+
          " misses an attempt to choke "+ob->query_cap_name(), ({ this_player() }));
        if(!this_player()->kill_ob(ob)) {
          //  write(ob->query_cap_name()+" can't be attacked by you yet.");
            return 1;
        }
        this_player()->set_disable();
        return 1;
    }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
        return 1;
    }
    // by putting "stfu" as the only skill, it will query only stats
    attack = BALANCE_D->get_damage( this_player(), ob, 4, ({ "stfu" }),
                                   ({ "strength" }), ({ "strength" }) );
    attack = attack;
    if ((string)ob->query_gender() == "male") gen = "him";
    else
        gen = "her";
    if (attack < 1) {
        write("You try to choke "+ob->query_cap_name()+" but cannot lift "
          +ob->query_title_gender()+"!");
        tell_room(environment(this_player()), this_player()->query_cap_name()+
          " trys to choke "+ob->query_cap_name()+", but cannot lift "+gen+"!", ({ this_player() }));
        this_player()->set_disable();
        return 1;
    }
    oi = random(this_player()->query_level()/15);
    if(oi > 4) oi = 4;
    if(oi == 0) {
        write("You try to choke "+ob->query_cap_name()+", but "+nominative(ob)+" wiggles out of your grasp!");
        say(this_player()->query_cap_name()+" tries to choke "+ob->query_cap_name()+", but fails!", ob);
        message("info", this_player()->query_cap_name()+" tries to choke you, but you wiggle out of "+possessive(this_player())+" grasp!", ob);
        return 1;
    }
    while (oi) {
        ob->damage(attack/3 + random(attack)/4 );
        this_player()->add_sp(-attack/6);
        this_player()->add_skill_points("attack", attack/20);
        write("You hold "+ob->query_cap_name()+" in the air and let "+gen+" choke.");
        tell_room(environment(this_player()), this_player()->query_cap_name()+" holds "+ob->query_cap_name()+
          " in the air, and lets "+gen+" choke.", ({ this_player() }));
        oi--;
    }
    this_player()->set_disable();
    return 1;
}
void help() {
    write("Syntax: <choke [(living)]>\n\n"
      "A fighter command to grab their opponent \n"
      "and choke them. This is a risky but powerful attack.");
}
int abil() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_level() < 29) return 0;
    if (tp->query_stats("strength") < 30) return 0;
    return 1;
}
