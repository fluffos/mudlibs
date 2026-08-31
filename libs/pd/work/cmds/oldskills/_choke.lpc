//     _choke.c
//     A new fighter attack
//     Added 26 April 2000 by -(Inferno)-
#include <std.h>
inherit DAEMON;
int abil();
int cmd_choke(string str) {
    int attack;
    int oi;
    string gen;
    object ob;
    if (this_player()->query_class() != "fighter") {
        write("Don't you wish you were that strong?");
        return 1;
    }
    if (!abil()) {
        notify_fail("What?\n");
        return 0;
    }
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
            write(ob->query_cap_name()+" can't be attacked by you yet.");
            return 1;
        }
        this_player()->set_disable();
        return 1;
    }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
        return 1;
    }
    attack = this_player()->query_stats("strength");
    attack += this_player()->query_skill("attack")/3;
    attack -= ob->query_stats("constitution")/4;
    attack -= ob->query_skill("defense")/4;
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
    oi++;
    while (1) {
        ob->add_hp(- (random(attack) * 2) - (oi * (oi*3 +  oi)));
        this_player()->add_sp(-attack/7);
        this_player()->add_skill_points("attack", 25);
        write("You hold "+ob->query_cap_name()+" in the air and let "+gen+" choke.");
        tell_room(environment(this_player()), this_player()->query_cap_name()+" holds "+ob->query_cap_name()+
          " in the air, and lets "+gen+" choke.", ({ this_player() }));
        oi++;
        if (oi > this_player()->query_strength()/7) break;
        if (random(this_player()->query_stats("strength") - 
            (oi*(oi + oi))) <
          random(ob->query_stats("strength") + ob->query_level()/4))
            break;
    }
    this_player()->set_disable();
    return 1;
}
void help() {
    write("Syntax: <choke [(living)]>\n\n"
      "A fighter command to grab their opponent \n"
      "and choke them. This is a low level attack.");
}
int abil() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_class() != "fighter") return 0;
    if (tp->query_level() < 14) return 0;
    if (tp->query_stats("strength") < 20) return 0;
    return 1;
}
