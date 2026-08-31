//      a conjurer spell for conjuring elementals
//      a dungeonware.net collaberation with
//      -(Inferno)-

#include <std.h>
int spell();
inherit DAEMON;

int cmd_conjure(string str) {
    object tp, ob;
    int con, wis, sum;

   if (!spell()) {
      notify_fail("What?\n");
      return 0;
   }
    if(!str) {
        notify_fail("Syntax: conjure <elemental>\n");
        return 0;
    }
    if(this_player()->query_ghost()) return 0;
    tp = this_player();
    lower_case(str);
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("Something prevents you from using your powers.\n");
        return 0;
    }
    if((int)this_player()->query_mp() < 45) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    con = (int)this_player()->query_skill("conjuring");
    if(con < 50) {
        notify_fail("Your skills are to weak to conjure an elemental.\n");
        return 0;
    }
    if (present("elemental mob", environment(this_player())))
      return notify_fail("Your mind cannot control more than one elemental at a time.\n");

    wis = (int)this_player()->query_stats("wisdom");
// -----------------------------------------------------------------
//                     Elementals below this line
// -----------------------------------------------------------------

    if (str == "air" && tp->query_mp() >= 35 && con >= 50) {
        sum = 35;
        if (random(sum) > random(con)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        write("%^ORANGE%^POP!%^RESET%^ An air elemental appears!");
        new("/d/standard/elemental/mob/air")->move(environment(tp));
    } else
/*    if (str == "imp" && tp->query_mp() >= 50 && con >= 50) {
        sum = 50;
        if (random(sum) > random(con)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        new("/d/standard/abyss/mob/imp")->move(environment(tp));
    } else
    if (str == "messenger" && tp->query_mp() >= 60 && con >= 55) {
        sum = 60;
        if (random(sum) > random(con)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        new("/d/standard/abyss/mob/messenger")->move(environment(tp));
    } else
   if (str == "hellcat" && tp->query_mp() >= 67 && con >= 65) {
        sum = 67;
        if (random(sum) > random(con)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        new("/d/standard/abyss/mob/hellcat")->move(environment(tp));
    } else 
    if (str == "carrier" && tp->query_mp() >= 60 && con >= 60) {
        sum = 60;
        if (random(sum) > random(con)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        new("/d/standard/abyss/mob/carrier")->move(environment(tp));
    } else
    if (str == "incubus" && tp->query_mp() >= 75 && con >= 70) {
        sum = 75;
        if (random(sum) > random(con)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        new("/d/standard/abyss/mob/incubus")->move(environment(tp));
    } else 
    if (str == "sucubus" && tp->query_mp() >= 75 && con >= 70) {
        sum = 75;
        if (random(sum) > random(con)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        new("/d/standard/abyss/mob/sucubus")->move(environment(tp));
    } else 
    if (str == "assassin" && tp->query_mp() >= 90 && con >= 80) {
        sum = 90;
        if (random(sum) > random(con)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        new("/d/standard/abyss/mob/assassin")->move(environment(tp));
    }  else
    if (str == "cacofiend" && tp->query_mp() >= 140 && con >= 110) {
        sum = 140;
        if (random(sum) > random(con)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        new("/d/standard/abyss/mob/cacofiend")->move(environment(tp));
    } else */
        {
        write("Syntax: <summon [demon_name]>\n");
        return 1;
    }

// ---------------------------------------------------------------
//                    Demons above this line
// ---------------------------------------------------------------
    ob = present(str, environment(tp));
    write("You conjure an elemental from another plane!");
    say(this_player()->query_cap_name()+" conjures an elemental from another plane!", ob);
    ob->set_owner(tp);
    this_player()->add_mp(-sum*3);
    this_player()->add_skill_points("conjuring", random(sum));
    return 1;
}

void help() {
    write("Syntax: <conjure [elemental_name]>\n\n");
    write("This spell allows a conjurer to conjure an elemental from "
          "other planes of existance. The name of the elemental must "
          "be known. If the mage is strong enough, the conjured "
          "elemental will be under the complete control of the caster. "
          "<command [elemental] to reveal powers> will tell you what "
          "available powers the elemental has. (eg. <command "
          "air elemental to reveal powers>).");
}

int spell() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_subclass() != "conjurer") return 0;
   if (o->query_skill("conjuring") < 50) return 0;
   if (o->query_level() < 10) return 0;
   return 1;
}

