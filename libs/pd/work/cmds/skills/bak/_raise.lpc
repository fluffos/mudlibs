//      a necro spell for raising the dead based on _summon.c
//      a dungeonware.net production
#include <std.h>
int spell();
inherit DAEMON;
string type() { return "other"; }
int cmd_raise(string str) {
    string list;
    object tp, ob, mon;
    int nec, wis, sum;
    if (!spell()) {
        return 0;
    }
    if(!str) {
        return 0;
    }
    if(this_player()->query_ghost()) return 0;
    tp = this_player();
    lower_case(str);
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("Something prevents you from using your powers.\n");
        return 0;
    }
    if (this_player()->query_arena()==1)
        return notify_fail("The gods frown upon this in the arena.\n");
    if((int)this_player()->query_mp() < 45) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    nec = (int)this_player()->query_skill("necromancy");
    if(nec < 50) {
        notify_fail("Your mind is too weak to control the undead.\n");
        return 0;
    }
    wis = (int)this_player()->query_stats("wisdom");
    // -----------------------------------------------------------------
    //                     Undead below this line
    // -----------------------------------------------------------------
    if (str == "list") {
        list = "%^RESET%^%^BOLD%^  Known Undead\n%^BLUE%^+=+=+=+=+=+=+=+=%^RESET%^\n";
        if(nec >= 35)
            list += "  Skeleton\n";
        if(nec >= 70)
            list += "  Zombie\n";
        if(nec >= 110)
            list += "  Wight\n";
        if(nec >= 150)
            list += "  Spectre\n";
        if(nec >= 200)
            list += "  Nightstalker\n";
        write(list);
        return 1;
    } else
    if (str == "skeleton" && tp->query_mp() >= 35 && nec >= 35) {
        sum = 22;
        if (present("skeleton undead", environment(this_player())))
            return notify_fail("Your mind cannot control more than one skeleton at a time.\n");
        if (find_living("skeleton "+this_player()->query_name())) 
            return notify_fail("Your mind cannot control more than one skeleton at a time.\n");
        if (random(sum) > random(nec)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        write("%^BOLD%^A skeleton claws it's way from the ground!%^RESET%^");
        mon = new("/d/nopk/standard/undead/mob/skeleton");
        mon->set_name("skeleton "+this_player()->query_name());
        mon->move(environment(tp));
    } else
    if (str == "zombie" && tp->query_mp() >= 70 && nec >= 70) {
        sum = 44;
        if (present("zombie undead", environment(this_player())))
            return notify_fail("Your mind cannot control more than one zombie at a time.\n");
        if (find_living("zombie "+this_player()->query_name()))
            return notify_fail("Your mind cannot control more than one zombie at a time.\n");
        if (random(sum) > random(nec)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        write("%^BOLD%^A zombie digs it's way from the ground!%^RESET%^");
        mon = new("/d/nopk/standard/undead/mob/zombie");
        mon->set_name("zombie "+this_player()->query_name());
        mon->move(environment(tp));
    } else
    if (str == "wight" && tp->query_mp() >= 110 && nec >= 110) {
        sum = 66;
        if (present("wight undead", environment(this_player())))
            return notify_fail("Your mind cannot control more than one wight at a time.\n");
        if (find_living("wight "+this_player()->query_name()))
            return notify_fail("Your mind cannot control more than one wight at a time.\n");
        if (random(sum) > random(nec)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        write("%^BOLD%^A wight claws it's way from the ground!%^RESET%^");
        mon = new("/d/nopk/standard/undead/mob/wight");
        mon->set_name("wight "+this_player()->query_name());
        mon->move(environment(tp));
    } else
    if (str == "spectre" && tp->query_mp() >= 150 && nec >= 150) {
        sum = 88;
        if (present("spectre undead", environment(this_player())))
            return notify_fail("Your mind cannot control more than one spectre at a time.\n");
        if (find_living("spectre "+this_player()->query_name()))
            return notify_fail("Your mind cannot control more than one spectre at a time.\n");
        if (random(sum) > random(nec)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        write("%^BOLD%^A spectre fades out of the shadows before you!%^RESET%^");
        mon = new("/d/nopk/standard/undead/mob/spectre");
        mon->set_name("spectre "+this_player()->query_name());
        mon->move(environment(tp));
    } else
    if (str == "nightstalker" && tp->query_mp() >= 200 && nec >= 200) {
        sum = 88;
        if (present("nightstalker undead", environment(this_player())))
            return notify_fail("Your mind cannot control more than one nightstalker at a time.\n");
        if (find_living("nightstalker "+this_player()->query_name()))
            return notify_fail("Your mind cannot control more than one nightstalker at a time.\n");
        if (random(sum) > random(nec)) {
            write("Your call was either not heard or ignored.\n");
            return 1;
        }
        write("%^BOLD%^A nightstalker fades out of the shadows before you!%^RESET%^");
        mon = new("/d/nopk/standard/undead/mob/nightstalker");
        mon->set_name("nightstalker "+this_player()->query_name());
        mon->move(environment(tp));
    } else
    {
        write("Syntax: <raise [undead_name]>\n");
        return 1;
    }
    // ---------------------------------------------------------------
    //                    Demons above this line
    // ---------------------------------------------------------------
    ob = present(str, environment(tp));
    write("You raise an undead from beyond!");
    say(this_player()->query_cap_name()+" raises an undead from beyond!", ob);
    ob->set_owner(tp);
    this_player()->add_mp(-(sum*2 + random(sum)));
    this_player()->add_skill_points("necromancy", random(sum));
    return 1;
}
void help() {
    write("Syntax: <raise [undead_name]>\n\n");
    write("This spell allows a necromancer to raise an undead "
      "monster. The name of the undead to be raised must "
      "be known. If the mage is strong enough, the raised "
      "undead will be under the complete control of the caster. "
      "<command [undead] to reveal powers> will tell you what "
      "available powers the raised undead has. (eg. <command "
      "skeleton to reveal powers>). <raise list> can be used "
      "to see what undead may be raised.");
}
int spell() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_subclass() != "necromancer") return 0;
    if (o->query_skill("necromancy") < 35) return 0;
    if (o->query_level() < 10) return 0;
    return 1;
}
