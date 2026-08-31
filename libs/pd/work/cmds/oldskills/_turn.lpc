//      _turn.c
//      Monk and cleric ability.
//      written 141092 by Descartes of Borg

#include <std.h>
int spell();
inherit DAEMON;

int check_alignment(object tp, string clas);
int turn_all(object tp);

int cmd_turn(string str) {
    string whom;
    object *inv;
    object tp, ob;
    int which, skip, i, faith, wisdom;

   if (!spell()) {
      notify_fail("What?\n");
      return 0;
   }
    this_player()->set_magic_round();
    if(!str) {
        notify_fail("Turn what?\n");
        return 0;
    }
    tp = this_player();
    if((string)tp->query_subclass() != "cleric") {
        notify_fail("You appear puzzled.\n");
        return 0;
    }
    if(environment(tp)->query_property("no magic")) {
        notify_fail("Something is blocking your concentration.\n");
        return 0;
    }
    if(tp->query_casting()) return 1;
    if(!check_alignment(tp, (string)tp->query_class())) {
        notify_fail("You have betrayed the source of your powers!\n");
        return 0;
    }
    ob = present(str, environment(tp));
    if(!ob) {
        if(str == "all") return turn_all(tp);
        inv = all_inventory(environment(tp));
        sscanf(str, "%s %d", whom, which);
        for(i=0, skip =0; i<sizeof(inv) && !ob; i++) {
            if(inv[i]->id(whom)) {
                skip ++;
                if(skip == which) ob = inv[i];
            }
        }
        if(!ob) {
            notify_fail("Turn what?\n");
            return 0;
        }
    }
    faith = (int)tp->query_skill("belief");
    wisdom = (int)ob->query_stats("wisdom")*3/4;
    faith -= wisdom;
    if(faith < 2) faith = 2;
    faith = random(faith);
    if((int)tp->query_mp() < faith) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if((string)ob->query("race") != "undead" && (string)ob->query("race") != "lich" && (string)ob->query("race") != "vampire") {
        notify_fail(ob->query_cap_name()+" is not undead!\n");
        return 0;
    }
    tp->add_mp(-faith);
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    say(tp->query_cap_name()+" mutters a prayer to turn the undead.\n", tp);
    if(faith > 65) {
        write("The undead being turns to dust.\n");
        say(ob->query_cap_name()+" turns to dust in response to "+tp->query_cap_name()+"'s prayer.\n", tp);
        ob->remove();
        tp->add_alignment(15);
        tp->add_skill_points("belief", 100);
    }
    else {
        tp->set_casting(faith);
        write("The undead writhes in response to your holy prayer.\n");
        say(ob->query_cap_name()+" writhes in response to "+tp->query_cap_name()+"'s prayer.\n", tp);
        tp->add_skill_points("faith", faith);
    }
    return 1;
}

int check_alignment(object tp, string clas) {
    if(clas == "monk") {
        if((int)tp->query_alignment() < 200) return 0;
        else return 1;
    }
   if((int)tp->query_alignment() < 0) return 0;
    return 1;
}

int turn_all(object tp) {
    return 1;
}

void help() {
    write("Syntax: <turn [living]>\n"+
          "         or <turn all>\n"+
        "\nAllows you turn a single undead monster or all undead monsters\n"+
        "in a room.  There is a small chance each time that the monster\n"+
        "will turn to dust.\n");
}
int spell() {
   object j;
   j = this_player();
   if (!j) return 0;
   if (j->query_subclass() != "cleric") return 0;
   if (j->query_skill("belief") < 10) return 0;
   if (j->query_level() < 2) return 0;
   return 1;
}
